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

    // 需要忽视掉age后面输入的空格，否则下面的getline就会读入空格并认为读入完毕
    cin.ignore();

    cout << "Where are you from? ";
    string home;
    getline(cin, home, '\n');

    cout << "Hello " << name << "(age " << age << " from " << home << ")" << endl;

    return 0;
}