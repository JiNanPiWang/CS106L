//
// Created by Samsara on 2024/2/22.
// File name: Lecture8.cpp
// Description: 
//
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v{3, 2, 1};
//    auto cmp = [](const int &a, const int &b) { return a > b; };
//    auto [min, max] = minmax_element(v.begin(), v.end(), cmp);
//    cout << *min << " " << *max << endl;

    // 第三个参数代表初始值
    auto sum = accumulate(v.begin(), v.end(), 1);
    cout << "sum: " << sum << endl;

    return 0;
}