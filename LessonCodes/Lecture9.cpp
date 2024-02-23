//
// Created by Samsara on 2024/2/23.
// File name: Lecture9.cpp
// Description: 
//
#include <iostream>

using namespace std;

int main()
{
    int a[5] = {0, 1, 2, 3, 4};

    // 指针是常量
    int *const p = a;

    // 指针指向的值是常量
    const int *p1 = a;
    int const *p2 = a;

    // p++会报错，(*p)++不会
    (*p)++;

    // p1++不会报错，(*p1)++会
    p1++;

    return 0;
}