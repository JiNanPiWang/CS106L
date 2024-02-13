//
// Created by Samsara on 2024/2/12.
// File name: Lecture5.cpp
// Description: 
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec{5, 4, 3, 2, 1};
    for (auto x: vec) {
        cout << x << " ";
    }
    cout << endl;
    // Find the first occurrence of a value in a sequence.
    auto it = find(vec.begin(), vec.end(), 5);
    // *it是找到位置对应的值，而不是位置序号
    cout << *it << endl;

    return 0;
}