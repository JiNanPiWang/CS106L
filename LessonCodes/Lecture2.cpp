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
    // 输入Avery Wang，会出现错误，因为cin会认为空格代表清除缓冲区，Wang会被输入age，导致错误，输入被中止
    cout << "What is your name? ";
    string name;
    cin >> name;

    cout << "What is your age? ";
    int age;
    cin >> age;

    cout << "Where are you from? ";
    string home;
    cin >> home;

    cout << "Hello " << name << "(age " << age << " from " << home << ")" << endl;

    return 0;
}