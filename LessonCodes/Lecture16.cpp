//
// Created by Samsara on 2024/3/5.
// File name: Lecture16.cpp
// Description: RAII
//
// noexcept应该在构造或者析构函数中出现的原因：比如在析构的一半抛出异常，会导致内存泄漏

#include <iostream>
#include <fstream>
#include <mutex>
#include <map>
#include <memory>

// 不符合RAII，也就是资源获取即初始化
void printFile()
{
    std::ifstream input;
    input.open("a.txt");
    // ...
    input.close();
}

// 符合RAII
void printFileRAII()
{
    std::ifstream input("a.txt");
    // ...
    // 会自动close
}

// 不符合RAII
void cleanDatabase(std::mutex &databaseLock, std::map<int, int> &database)
{
    databaseLock.lock();
    // ...
    databaseLock.unlock();
}

// 符合RAII
void cleanDatabaseRAII(std::mutex &databaseLock, std::map<int, int> &database)
{
    // 详细看源码，std::lock_guard<std::mutex>是类型，可以理解为vector<int>，但其似乎没有成员函数
    std::lock_guard<std::mutex> Lock(databaseLock);
    // ...
}

// 不符合RAII
struct Node {};
void rawPtrFn()
{
    Node *n = new Node;
    // ...
    delete n;
}

// 符合RAII
void rawPtrFnRAII()
{
    // 独占拥有权，一个对象只能由一个 unique_ptr 拥有。
    std::unique_ptr<Node> n(new Node);

    // 共享拥有权，多个 shared_ptr 可以同时拥有相同的对象。当所有没有指针指向对象时析构
    std::shared_ptr<Node> n1(new Node);
    std::shared_ptr<Node> n2 = n1;

    // 与 std::shared_ptr 不同，std::weak_ptr 不会增加对象的引用计数。
    // 它提供了一种方法来观察和访问 shared_ptr 管理的对象，而不会造成所有权问题。
    std::weak_ptr<Node> n3 = n2;
    // weak_ptr 本身并不拥有对象。相反，当你需要访问 weak_ptr 所指向的对象时，你可以使用 wp.lock() 方法来尝试获取一个 std::shared_ptr
    std::shared_ptr<Node> n4 = n3.lock();

    // ...
}