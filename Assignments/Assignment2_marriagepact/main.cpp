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

std::set<std::string> get_applicants(std::string filename)
{
    std::set<std::string> st;
    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        std::string line;
        while (std::getline(inputFile, line))
        {
            st.insert(line);
        }
    }
    return st;
}

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
