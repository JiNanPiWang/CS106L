//
// Created by Samsara on 2024/2/12.
// File name: Lecture5.cpp
// Description: 
//
#include <map>
#include <iostream>

using namespace std;

int main()
{
    multimap<int, int> mp;
    mp.insert(make_pair(3, 3));
    mp.insert({3, 12});
    cout << mp.count(3) << endl;
    return 0;
}