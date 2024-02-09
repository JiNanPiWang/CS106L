//
// Created by Samsara on 2024/2/8.
// File name: Lecture2.cpp
// Description: CS 106L Fall 2019 - Lecture 2: Streams II (Screencast)
//
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    string str = "123";
    istringstream iss(str);
    int result;
    iss >> result;
    if (iss.fail())
        throw domain_error("...");

    char remain;
    iss >> remain;
    if (iss.fail())
        throw domain_error("...");
    return 0;
}