//
// Created by Samsara on 2024/2/22.
// File name: Lecture8.cpp
// Description: 
//
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{3, 2, 1, 4, 5, 6};
    auto cmp = [](const int &a, const int &b) { return a > b; };
    auto [min, max] = minmax_element(v.begin(), v.end(), cmp);
    cout << *min << " " << *max << endl;
    return 0;
}