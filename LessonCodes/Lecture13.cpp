//
// Created by Samsara on 2024/2/26.
// File name: Lecture13.cpp
// Description: 
//
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

int main()
{
    // 左右值分辨
    int val = 2;
    int *ptr = 0x02248837;
    vector<int> v1{1, 2, 3};

    auto &ptr2 = ptr;
    auto &&v4 = v1 + v2; // 右值引用，可以理解为延长了右值的生命
    auto &ptr3 = &val;

    auto &&val2 = val; // 错误，不能将左值绑定给右值引用

    const auto &ptr3 = ptr + 5; // const可以

    return 0;
}