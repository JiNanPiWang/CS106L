/*
 * CS106L SimpleEnroll Assignment Part 1
 * Created by Fabio Ibanez
 */

#include "utils.cpp"
#include <exception>
#include <iostream>
#include <system_error>
#include <vector>

std::string COURSES_PATH = R"(D:\Projects\2024-2-26-CS106L\Assignments\Assignment1_simpleenroll\courses.csv)";

bool structTest() { // 测试是否能引入utils.cpp，以及结构体是否构造成功
  Course c{"Standard C++ Programming", "1", "2023-2024 Winter"};
  return true;
}

int main() {
  std::vector<Course> vector_of_courses;

  if (!structTest()) {
    std::cerr << "structTest Failed 😞";
  } else {
    std::cout << "structTest Passed! ✅" << '\n';
  }

  parse_csv(COURSES_PATH, vector_of_courses);

  write_courses_offered(vector_of_courses);

  write_courses_not_offered(vector_of_courses);

  FILE *pipe = popen("python3 utils/autograder.py", "r");
  if (!pipe)
    return -1;

  char buffer[128];
  while (!feof(pipe)) {
    if (fgets(buffer, 128, pipe) != NULL)
      std::cout << buffer;
  }
  pclose(pipe);

  // uncomment this line to debug
  // print_vector(vector_of_courses);
  return 0;
}
