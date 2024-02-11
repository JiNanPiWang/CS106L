//
// Created by Samsara on 2024/2/11.
// File name: Lecture3.cpp
// Description: 
//
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), rand);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, "\n"));
    return 0;
}