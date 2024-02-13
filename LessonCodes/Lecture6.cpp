//
// Created by Samsara on 2024/2/13.
// File name: Lecture6.cpp
// Description: 
//
#include <iostream>

using namespace std;

int getTypeValue()
{
    // typeid(int).name() 调用回返回一个表示整型（int）的名称。具体返回值取决于编译器的实现
    // 返回的类型名称(可能是i)通常是编译器内部使用的名称，并不一定是易于人类阅读的形式。
    cout << "Enter a" << typeid(int).name() << ": ";
    return 0;
}

int main()
{
    getTypeValue();
    return 0;
}