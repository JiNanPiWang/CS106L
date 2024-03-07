### Assignment 2: Marriage Pact 



1. 我们需要写一个函数，把文件里面的名字放入一个set，在这里依然使用文件流

   ```c++
   std::set<std::string> get_applicants(std::string filename) {
       std::set<std::string> st;
       std::ifstream inputFile(filename);
       if (inputFile.is_open()) {
           std::string line;
           while (std::getline(inputFile, line)) {
               st.insert(line);
           }
       }
       return st;
   }
   ```

2. find_matches：从集合中取出所有与您姓名缩写相同的名称，并将指向它们的指针放入新的 std::queue 中

   这个难度并不大，但是坑点是让我们把set内元素的指针存入一个string *的队列中，set内部存储的元素默认为const，如果尝试获取 std::set 中一个元素的指针，得到的就会是一个const类型的指针，所以这里还需要把const去掉

   ```c++
   std::queue<std::string *> find_matches(std::set<std::string> &students)
   {
       // 假设我叫Jinan Piwang
       std::queue<std::string *> q;
       for (const auto &student: students)
       {
           auto firstCh = student[0];
           auto secondPos = student.find(' ') + 1;
           auto secondCh = student[secondPos];
           if (firstCh == 'J' && secondCh == 'P')
           {
               // 在C++中，std::set 内部存储的元素默认为const
               // 在编译器层面，这意味着如果您尝试获取 std::set 中一个元素的指针，
               // 您将得到一个指向 const 数据的指针（即 const std::string*）
               // 但是我们队列的参数类型是<std::string *>，并不是const
               // 所以我们要么把指针的const去掉，要么改变函数的返回值参数
               // 在这里我改变了指针的const属性，如果确保后面不会动对应内容的话，这么什么问题
               q.push(const_cast<std::string *>(&student));
           }
       }
       return q;
   }
   ```

3. 主函数

   主函数中调用上面写的内容就可以啦

   ```c++
   int main()
   {
       // Your code goes here. Don't forget to print your true love!
       auto applicants = get_applicants(
               R"(D:\Projects\2024-2-26-CS106L\Assignments\Assignment2_marriagepact\students.txt)");
       auto matches = find_matches(applicants);
       while (!matches.empty())
       {
           std::cout << *matches.front() << std::endl;
           matches.pop();
       }
       return 0;
   }
   ```

