//
// Created by Samsara on 2024/2/23.
// File name: Lecture9.cpp
// Description: 
//
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a[5] = {0, 1, 2, 3, 4};

    // 指针是常量
    int *const p = a;
    // 指针指向的值是常量，同int const *p1 = a;
    const int *p1 = a;


    // p++会报错，(*p)++不会
    (*p)++;
    // p1++不会报错，(*p1)++会
    p1++;

    vector<int> v = {1, 2, 3, 4};
    const vector<int>::iterator it = v.begin();
    vector<int>::const_iterator it1 = v.begin();

    // it++会报错，(*it)++不会
    (*it)++;
    // it1++不会报错，(*it1)++会
    it1++;

    return 0;
}