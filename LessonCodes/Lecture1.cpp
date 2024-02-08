//
// Created by Samsara on 2024/2/8.
// File name: Lesson1.cpp
// Description: CS 106L Fall 2019 - Lecture 1: Streams I (Screencast)
//
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    // 输出流是指向输出设备（如屏幕、文件、打印机等）的数据流。
    // 在C++中，输出流通常用于将数据发送到标准输出（通常是屏幕）或文件中。
    // 使用了 ostringstream 对象 oss 来构建一个字符串流，
    ostringstream oss("Ito En Green Tea ");
    cout << oss.str() << endl;

    // 通过 oss << ... 可以向流中添加内容
    oss << 16.9 << " Ounce ";
    cout << oss.str() << endl;

    // 从尾部添加内容
//    oss.seekp(0, stringstream::end); // 等价于ostringstream oss("Ito En Green Tea ", stringstream::ate);
//    oss << "!";
//    cout << oss.str() << endl;

    // 就像cout，oss会从后面一直加
    // oss 不能直接输出是因为 ostringstream 是用于构建字符串的输出流，
    // 它将数据以字符串的形式存储在内存中，而不是直接输出到屏幕或文件。
    oss << "(Pack of " << 12 << ")";
    cout << oss.str() << endl;

    return 0;
}