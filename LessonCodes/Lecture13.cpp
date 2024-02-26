//
// Created by Samsara on 2024/2/26.
// File name: Lecture13.cpp
// Description: 
//
#include <iostream>
#include <vector>

using std::cout, std::endl;

template<typename T>
void print(T &t)
{
    std::cout << "It is lvalue: " << t << std::endl;
}

template<typename T>
void print(T &&t)
{
    std::cout << "It is rvalue: " << t << std::endl;
}

template<typename T>
void testForward(T &&t)
{
    print(t);
    print(std::forward<T>(t));
}

int main()
{
    int x = 42;
    testForward(x);
    testForward(42);
    return 0;
}