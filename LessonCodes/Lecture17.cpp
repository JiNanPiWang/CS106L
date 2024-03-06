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

void greet(int id)
{
    // 加入延时，可以更好的发现问题
    // 程序中确实创建了两个线程，主线程（main）会继续执行它下面的代码，不会等待 thread1 和 thread2 完成。
    // 如果关联的线程还在运行且没有被 detach，那么 std::thread 的析构函数会调用 std::terminate
    // 析构函数通过结合性(joinable)来判断是否需要调用 std::terminate
    // TODO: 看joinable如何实现
    cout << "Hello there! My name is " << std::this_thread::get_id() << endl;
}

int main()
{
    cout << "Greetings from my threads..." << endl;

    // 可以看出main也是一个线程，与其他并行
    cout << "Hello there! My name is " << std::this_thread::get_id() << endl;

    // 可以理解为，告诉一个工人需要去做什么
    std::thread thread1(greet, 1);
    std::thread thread2(greet, 2);

    thread1.join();
    thread2.join();

    cout << "All greetings done!" << endl;
    return 0;
}