## Assignment 1: SimpleEnroll，我的解决方案

题目的内容很简单，就是让你找出可以选的课程和不可以选的课程。下面的内容按介绍pdf的顺序来看，也是我看的顺序。

1. 改变传入参数方式

   由于是两个文件，而且函数返回值都是空，所以我们需要使用引用传参的方式，将utils.cpp中的parse_csv，write_courses_offered，write_courses_not_offered三个函数的vector_of_courses参数都改为&vector_of_courses。

2. 改变默认路径

   utils.cpp中的19-22行

   ```c++
   // STUDENT TODO: add paths
   std::string COURSES_OFFERED_CSV_PATH = "<ENTER PATH HERE>";
   
   std::string COURSES_NOT_OFFERED_CSV_PATH = "<ENTER PATH HERE>";
   ```

   将其换成你文件的路径，比如我的

   ```c++
   // STUDENT TODO: add paths
   std::string COURSES_OFFERED_CSV_PATH = R"(D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll\student_output\courses_offered.csv)";
   
   std::string COURSES_NOT_OFFERED_CSV_PATH = R"(D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll\student_output\courses_not_offered.csv)";
   ```

   同理改掉main中的COURSES_PATH，我的是

   ```c++
   std::string COURSES_PATH = R"(D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll\courses.csv)";
   ```

3. 编写Course的类型

   在utils的24行

   ```c++
   struct Course {
     /* STUDENT TODO: ADD TYPE */ title;
     /* STUDENT TODO: ADD TYPE */ number_of_units;
     /* STUDENT TODO: ADD TYPE */ quarter;
   ```

   根据课程文件夹根目录的courses.csv，我们可以分析出，Title,Number of Units,Quarter分别代表了课程的名称、课程的学分数以及课程所在的季度，一个例子是：Personal Finance for Engineers,1,2023-2024 Autumn，又因为main里面的structTest都是string，所以这里的类型我是这样写的：

   ```c++
   struct Course {
     std::string title; // 课程的名称
     std::string number_of_units; // 课程的学分数
     std::string quarter; // 课程所在的季度
   ```

4. 通过编写parse_csv来读入csv

   同样还是在utils.cpp，我们现在需要读入并分解上面提到的课程内容，把课程名称学分数等内容拆分，后面再进行其他操作。pdf里面提示我们可以使用split函数，它在utils中定义了，实现是

   ```c++
   std::vector<std::string> split(std::string s, char delim) {
     std::vector<std::string> return_vec;
     std::stringstream ss(s);
     std::string token;
     while (getline(ss, token, ',')) {
       return_vec.push_back(token);
     }
     return return_vec;
   }
   ```

   它的功能很明显，根据逗号分隔开传入的字符串s，如何将分隔的内容放入vector，再返回。所以我们可以利用这个函数，将类似courses.csv里面的内容一行一行的传入，就得到了分隔开的数据。我的实现是这样的

   ```c++
   void write_courses_offered(std::vector<Course> &vector_of_courses) {
       std::ofstream outputFile(COURSES_OFFERED_CSV_PATH);
       for (const auto &course : vector_of_courses) {
           if (course.quarter == "2023-2024 Winter") {
               if (outputFile.is_open()) {
                   outputFile << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
               }
           }
       }
       while (true) {
           bool is_find = false;
           for (auto &course: vector_of_courses) {
               if (course.quarter == "2023-2024 Winter") {
                   delete_elem_from_vector(vector_of_courses, course);
                   is_find = true;
                   break;
               }
           }
           if (!is_find)
               break;
       }
   }
   ```

   在这里写完后，大家可以在main的30行放一个断点，然后调试看看vector_of_courses是否存入了正确的内容。

5. 得到可以选的课程

   根据我运行的结果来看，null就是不能选的课程，反之。所以遍历课程，找到course.quarter对应的内容，写入文件即可。还有一个要求就是需要删去不符合的内容，使用给的delete_elem_from_vector函数即可（vector删除之前踩过不少坑，所以最好还是抛弃时间复杂度）。

   ```c++
   void write_courses_offered(std::vector<Course> &vector_of_courses) {
       std::ofstream outputFile(COURSES_OFFERED_CSV_PATH);
       for (const auto &course : vector_of_courses) {
           if (course.quarter != "null") {
               if (outputFile.is_open()) {
                   outputFile << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
               }
           }
       }
       while (true) {
           bool is_find = false;
           for (auto &course: vector_of_courses) {
               if (course.quarter != "null") {
                   delete_elem_from_vector(vector_of_courses, course);
                   is_find = true;
                   break;
               }
           }
           if (!is_find)
               break;
       }
   }
   ```

6. 得到不可以选的课程

   与上面几乎一模一样

   ```c++
   void write_courses_not_offered(std::vector<Course> &vector_of_courses) {
       std::ofstream outputFile(COURSES_NOT_OFFERED_CSV_PATH);
       for (const auto &course : vector_of_courses) {
           if (course.quarter == "null") {
               if (outputFile.is_open()) {
                   outputFile << course.title << "," << course.number_of_units << "," << course.quarter << std::endl;
               }
           }
       }
   }
   ```
   
7. 修改一些内容使得可以运行python测试

   这个题目有自动测试的内容，但是是python的，我们也需要修改一些内容，当然，首先需要你有python环境变量。

   首先将main.cpp中的pipe路径修改一下，修改为自己目录的

   ```c++
   FILE *pipe = popen(
           R"(python3 D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll\utils\autograder.py)", "r");
   ```

   然后修改utils/autograder.py的内容，也是将路径都改为自己的

   ```python
   def main():
     # fstream writing tests!
     binary_to_csv(
       R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/utils/courses_not_offered.bin",
       R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/utils/courses_not_offered.csv")
     binary_to_csv(
       R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/utils/courses_offered.bin",
       R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/utils/courses_offered.csv")
     assert files_are_equal(
       R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/utils/courses_offered.csv",
       R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/student_output/courses_offered.csv"), "write_courses_offered test failed 😞"
     assert files_are_equal(
       R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/utils/courses_not_offered.csv",
                            R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/student_output/courses_not_offered.csv"), \
       "write_courses_not_offered test failed 😞"
     os.remove(R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/utils/courses_not_offered.csv")
     os.remove(R"D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll/utils/courses_offered.csv")
     print("Congratulations, your code passes all the autograder tests! ✅")
   
   main()
   ```

   这样就完成啦！

