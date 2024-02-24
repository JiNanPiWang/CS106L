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
    cout << v;

    return 0;
}