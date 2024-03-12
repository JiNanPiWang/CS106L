//
// Created by Samsara on 2024/3/5.
// File name: Lecture17.cpp
// Description: 
//
#include <iostream>
#include <chrono>
#include <fstream>
#include <mutex>
#include <thread>
#include <memory>

using std::cout, std::endl;

std::mutex mutex;

void greet(int id)
{
    std::lock_guard<std::mutex> lg(mutex);
    cout << "Hello there! My name is " << id << endl;
}

int main()
{
    cout << "Greetings from my threads..." << endl;

    // 可以理解为，告诉一个工人需要去做什么
    std::thread thread1(greet, 1);
    std::thread thread2(greet, 2);

    // 可以理解为线程重新加入回main线程
    thread1.join();
    thread2.join();

    cout << "All greetings done!" << endl;
    return 0;
}