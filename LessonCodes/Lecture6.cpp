//
// Created by Samsara on 2024/2/13.
// File name: Lecture6.cpp
// Description: 
//
#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
T getTypeValue()
{
    while (true)
    {
        // typeid(int).name() 调用回返回一个表示整型（int）的名称。具体返回值取决于编译器的实现
        // 返回的类型名称(可能是i)通常是编译器内部使用的名称，并不一定是易于人类阅读的形式。
        cout << "Enter num" << typeid(T).name() << ": ";
        string line;
        T result;
        char extra;
        if (!getline(cin, line))
            throw domain_error("Unable to get line from cin");

        istringstream iss(line);
        if (iss >> result && !(iss >> extra))
            return result;

        cout << "Invalid format" << endl;
    }
}

int main()
{
    int a = getTypeValue<int>();
    cout << "a = " << a << endl;
    double b = getTypeValue<double>();
    cout << "b = " << b << endl;
    return 0;
}