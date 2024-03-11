#include "user.h"
#include <set>
#include <iostream>
#include <string>
#include <utility>

User::User(std::string name) noexcept
{
//  Implement the additional constructor here!
    this->name = std::move(name);
}

User::User(User &&other) noexcept: name(std::move(other.name)), friends(std::move(other.friends))
{
    // 对于 std::string 和 std::set 来说，标准库已经保证它们是在移动操作后处于有效的状态，
    // 这意味着 other.name 将变为一个空字符串，而 other.friends 将变为一个空的 std::set。
    // 你不需要手动去清空它们或者设置一个特定的值，C++ 标准库的移动构造函数已经为你处理好了。
//    other.name = "";
//    while (!other.friends.empty())
//        other.friends.erase(other.friends.begin());
    // TODO: 测试这里不删除上面的内容会怎么样
}

User &User::operator=(User &&other) noexcept
{
    if (this != &other)
    {
        this->name = other.name;
        this->friends = other.friends;
    }
    return *this;
}

std::string User::getName() const
{
    return name;
}

std::set<User> User::getFriends() const
{
    return friends;
}

void User::setName(std::string name)
{
    this->name = name;
}

// TODO: Implement the < operator overload here!
bool operator<(const User &a, const User &b)
{
    return a.name < b.name;
}