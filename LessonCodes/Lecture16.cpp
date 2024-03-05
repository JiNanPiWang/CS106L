//
// Created by Samsara on 2024/3/5.
// File name: Lecture16.cpp
// Description: RAII
//
// noexcept应该在构造或者析构函数中出现的原因：比如在析构的一半抛出异常，会导致内存泄漏

#include <iostream>
#include <fstream>

// 不符合RAII，也就是资源获取即初始化
void printFile()
{
    std::ifstream input;
    input.open("a.txt");
    // ...
    input.close();
}

// 符合RAII
void printFileRAII()
{
    std::ifstream input("a.txt");
    // ...
    // 会自动close
}