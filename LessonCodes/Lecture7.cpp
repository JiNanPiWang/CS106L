//
// Created by Samsara on 2024/2/20.
// File name: Lecture7.cpp
// Description: 
//
#include <iostream>
#include <vector>

using namespace std;

template <typename Collection, typename DataType>
int countOccurences(const Collection &list, DataType val)
{
    int count = 0;
    for (size_t i = 0; i < list.size(); ++i)
        if (list[i] == val)
            ++count;
    return count;
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    cout << countOccurences<vector<int>, int>(v, 4) << endl;
    return 0;
}