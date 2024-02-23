//
// Created by Samsara on 2024/2/23.
// File name: Lecture11.cpp
// Description: 
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> v{"Hello", "World"};
    cout << v[0] << endl; // 等同于cout.operator<<(v.operator[](0));
    v[1] += '!'; // 等同于v.operator[](1).operator+=("!");

    return 0;
}