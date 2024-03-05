//
// Created by Samsara on 2024/3/5.
// File name: Lecture17.cpp
// Description: 
//
#include <iostream>
#include <utility>
#include <fstream>
#include <mutex>
#include <thread>
#include <memory>

using std::cout, std::endl;

void greet(int id)
{
    cout << "Hello there! My name is " << id << endl;
}

int main()
{
    cout << "Greetings from my threads..." << endl;

    // 可以理解为，告诉一个工人需要去做什么
    std::thread thread1(greet, 1);
    std::thread thread2(greet, 2);

    cout << "All greetings done!" << endl;
    return 0;
}