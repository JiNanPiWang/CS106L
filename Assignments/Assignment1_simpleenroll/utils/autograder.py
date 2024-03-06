'''
Hey friend! Glad you're curious about this, but please don't touch this file :>)
'''

from csv_utils import *
import os

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