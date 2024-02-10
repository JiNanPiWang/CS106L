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
    cout << "What is your name? ";
    string name;
    getline(cin, name, '\n');

    cout << "What is your age? ";
    int age;
    cin >> age;

    cout << "Where are you from? ";
    string home;
    cin >> home;

    cout << "Hello " << name << "(age " << age << " from " << home << ")" << endl;

    return 0;
}