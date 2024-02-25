//
// Created by Samsara on 2024/2/23.
// File name: Lecture11.cpp
// Description: 
//

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class StringVector
{
    vector<string> vec;

public:
    // 初始化列表
    StringVector(const initializer_list<string> &vec) : vec(vec) {}

    void push_back(const string &str)
    {
        vec.push_back(str);
    }

    // 防止出现(vec+=s)+="str"不行，所以需要有返回值
    StringVector &operator+=(const string &str)
    {
        vec.push_back(str);
        return *this;
    }

    StringVector operator+(const StringVector &other) const
    {
        // 如果不新建，则v = v + v会导致+运算完后，左边的v也被改变
        auto new_vec = *this;
        copy(other.vec.begin(), other.vec.end(), back_inserter(new_vec.vec));
        return new_vec;
    }

    // 重载输出流操作符 << 作为友元函数的原因是因为该函数需要访问 StringVector 类的私有成员 vec。
    friend ostream &operator<<(ostream &os, const StringVector &stringVector)
    {
        os << "StringVector: ";
        std::copy(stringVector.vec.begin(), stringVector.vec.end(),
                  ostream_iterator<std::string>(os, " "));
        return os;
    }
};

int main()
{
//    vector<string> v{"Hello", "World"};
//    cout << v[0] << endl;
    // 等同于
    // cout.operator<<(v.operator[](0));
    // operator<<(cout, v.operator[](0));

//    v[1] += '!';
    // 等同于
    // v.operator[](1).operator+=("!");
    // operator+=(operator[](v, 1), "!");

    StringVector v = {"abc", "def"};
    v = v + v;
    cout << v;

    return 0;
}