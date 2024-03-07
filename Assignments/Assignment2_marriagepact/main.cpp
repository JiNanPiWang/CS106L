/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <fstream>

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

std::queue<std::string*> find_matches(std::set<std::string> &students) {
    // TODO: Implement this function.
}



int main() {
    // Your code goes here. Don't forget to print your true love!
    auto x=  get_applicants(
            R"(D:\Projects\2024-2-26-CS106L\Assignments\Assignment2_marriagepact\students.txt)");
    return 0;
}
