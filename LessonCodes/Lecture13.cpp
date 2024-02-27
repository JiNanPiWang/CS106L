//
// Created by Samsara on 2024/2/26.
// File name: Lecture13.cpp
// Description: 
//
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>

using std::cout, std::endl, std::vector, std::string;

class StringVector
{
    vector<string> vec;
public:
    // 初始化列表
    StringVector(const std::initializer_list<string> &vec) : vec(vec) {}
    StringVector(StringVector &&vec)  noexcept : vec(std::move(vec.vec)) {}
};

class StringVector1
{
    vector<string> vec;
public:
    // 初始化列表
    StringVector1(const std::initializer_list<string> &vec) : vec(vec) {}
    StringVector1(StringVector1 &&vec) : vec(vec.vec) {}
};

int main()
{
    vector<int> v(100000000);

    // 测试使用std::move()的情况
    auto start = std::chrono::steady_clock::now();
    StringVector sv = StringVector{"1"};
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> moveDuration = end - start;
    // 输出测试结果
    std::cout << "Time taken with std::move(): " << moveDuration.count() << " seconds" << std::endl;


    vector<int> v1(100000000);
    // 测试使用std::move()的情况
    start = std::chrono::steady_clock::now();
    StringVector1 sv1 = StringVector1{"1"};
    end = std::chrono::steady_clock::now();
    moveDuration = end - start;
    // 输出测试结果
    std::cout << "Time taken without std::move(): " << moveDuration.count() << " seconds" << std::endl;



    return 0;
}