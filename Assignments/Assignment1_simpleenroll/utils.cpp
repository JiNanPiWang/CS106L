/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 * Please complete each STUDENT TODO in this file.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

// (FIRST) STUDENT TODO: change how variables are passed into the functions you
// must complete

#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
#include <algorithm>

std::string COURSES_OFFERED_CSV_PATH =
        R"(D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll\student_output\courses_offered.csv)";

std::string COURSES_NOT_OFFERED_CSV_PATH =
        R"(D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll\student_output\courses_not_offered.csv)";

struct Course {
  std::string title; // 课程的名称
  std::string number_of_units; // 课程的学分数
  std::string quarter; // 课程所在的季度

  // ignore this!
  bool operator==(const Course &other) const {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

// forward declarations
void delete_elem_from_vector(std::vector<Course> &v, Course &elem);
std::vector<std::string> split(std::string s, char delim);

/*
 * This function should populate the vector_of_courses with structs of type
 * Class We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 */
void parse_csv(std::string filename, std::vector<Course> &vector_of_courses) {
    std::ifstream inputFile(filename); // 创建文件输入流
    if (inputFile.is_open()) {
        std::string infos; // 每一行的信息
        std::getline(inputFile, infos); // 跳过第一行
        while (std::getline(inputFile, infos)) {
            // 得到split分隔后的信息
            auto return_vector = split(infos, ',');
            auto parsed_course = Course();

            // 放入parsed_course对象，方便存入vector_of_courses
            parsed_course.title = return_vector[0];
            parsed_course.number_of_units = return_vector[1];
            parsed_course.quarter = return_vector[2];

            vector_of_courses.push_back(parsed_course);
        }
    }
}

/*
 * This function has TWO requirements.
 * 1) Write the courses that are offered to the file courses_offered.csv inside
 * the student_output folder
 *
 * 2) Delete classes that are offered from vector_of_courses.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 */
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

/*
 * This function writes the courses NOT offered to the file
 * courses_not_offered.csv inside of the student_output folder
 *
 * This function is ALWAYS called after the write_courses_offered function.
 * vector_of_courses will trivially contain classes that are not offered
 * since you delete offered classes from vector_of_courses in the
 * 'write_courses_offered' function.
 *
 * HINT: This should be VERY similar to write_courses_offered
 */
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

/* ######## HEYA! DON'T MODIFY ANYTHING BEYOND THIS POINT THX ######## */

// TODO: ADD DOCUMENTATION COMMENTS
void print_vector(std::vector<Course> vector_of_courses) {
  for (int i = 1; i < vector_of_courses.size(); ++i) {
    std::cout << vector_of_courses[i].title << ","
              << vector_of_courses[i].number_of_units << ","
              << vector_of_courses[i].quarter << std::endl;
  }
}

void delete_elem_from_vector(std::vector<Course> &v, Course &elem) {
  auto it = std::find(v.begin(), v.end(), elem);
  v.erase(it);
}

std::vector<std::string> split(std::string s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, ',')) {
    return_vec.push_back(token);
  }
  return return_vec;
}
