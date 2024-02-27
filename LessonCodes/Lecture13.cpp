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

    auto v4 = v1 + v2; // v1 is l, v2 is l, but v1 + v2 is rvalue
    v1 += v4;
    size_t size = v.size();
    val = static_cast<int> (size);
    v1[1] = 4 * i;
    ptr = &val; // 右值，val的地址没有地址
    v1[2] = *ptr;
    return 0;
}