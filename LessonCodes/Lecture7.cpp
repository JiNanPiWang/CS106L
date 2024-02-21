//
// Created by Samsara on 2024/2/20.
// File name: Lecture7.cpp
// Description: 
//
#include <iostream>
#include <vector>

using namespace std;

// 修改模板函数以包含一个函数对象作为谓词
template <typename Collection, typename UnaryPredicate>
int countOccurences(const Collection &list, UnaryPredicate pred)
{
    int count = 0;
    for (size_t i = 0; i < list.size(); ++i)
        if (pred(list[i]))
            ++count;
    return count;
}

class GreaterThan
{
public:
    explicit GreaterThan(int limit) : limit(limit) {}

    bool operator() (int val) const
    {
        return val >= limit;
    }

private:
    int limit;
};

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    int limit = 4; // 创建一个GreaterThan对象，设置限制值为4
    GreaterThan func(limit);

    // 调用countOccurences，传入vector和GreaterThan对象
    // 注意：这里不再需要明确指定模板参数，编译器可以自动推断
    cout << countOccurences<vector<int>>(v, func)
            << "item is greater than " << limit;
    return 0;
}