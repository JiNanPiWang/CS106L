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
#include <vector>

using std::cout, std::endl;

std::mutex mutex;
const int NumThreads = 8;

void greet(int id)
{
    std::lock_guard<std::mutex> lg(mutex);
    cout << "Hello there! My name is " << id << endl;
}

int main()
{
    cout << "Greetings from my threads..." << endl;

    std::vector<std::thread> threads;
    threads.reserve(NumThreads);
    for (int i = 0; i < NumThreads; ++i)
    {
        // threads.push_back(std::thread(greet, i));
        // 这里，emplace_back 直接将参数传递给 std::thread 的构造函数，而不需要显式创建 std::thread 对象。
        threads.emplace_back(greet, i);
    }

    // 可以理解为线程重新加入回main线程
    for (auto &t : threads)
        t.join();

    cout << "All greetings done!" << endl;
    return 0;
}