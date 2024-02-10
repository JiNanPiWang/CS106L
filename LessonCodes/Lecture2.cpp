//
// Created by Samsara on 2024/2/8.
// File name: Lecture2.cpp
// Description: CS 106L Fall 2019 - Lecture 2: Streams II (Screencast)
//
#include <sstream>
#include <iostream>

using namespace std;

// 在C++中，流有以下几个状态：
// good()：流处于正常状态，没有发生错误。
// eof()：流已经到达了文件末尾（对于输入流）或者输出流已经到达了文件末尾（对于输出流）。
// fail()：流发生了错误，但不是严重错误。例如，当你试图读取一个整数，但输入的内容不是整数时，流会进入这个状态。
// bad()：流发生了严重错误，通常是由于设备故障或者其他不可恢复的错误导致的。

int getInteger(const string &prompt, const string &reprompt)
{
    while (true)
    {
        cout << prompt;
        string line;
        if (!getline(cin, line))
        {
            // 通知调用者发生了无法处理的错误。
            throw domain_error("...");
        }

        istringstream iss(line);
        int val;
        string remain;

        // 如果输入流中的下一个字符不是数字，提取操作会失败，val的值将保持不变，而输入流的状态会被设置为失败状态。
        if ((iss >> val) && !(iss >> remain))
        {
            return val;
        }

        cout << reprompt << endl;
    }
}

int main()
{
    cout << "What is your name? ";
    string name;
    getline(cin, name, '\n');

//    cout << "What is your age? ";
    int age = getInteger("Please enter your age: ", "Age format is wrong. ");

    cout << "Where are you from? ";
    string home;
    getline(cin, home, '\n');

    cout << "Hello " << name << "(age " << age << " from " << home << ")" << endl;

    return 0;
}