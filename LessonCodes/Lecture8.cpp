//
// Created by Samsara on 2024/2/22.
// File name: Lecture8.cpp
// Description: 
//
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v{3, 2, 1, 6, 5, 4, 9, 8, 7};
//    auto cmp = [](const int &a, const int &b) { return a > b; };
//    auto [min, max] = minmax_element(v.begin(), v.end(), cmp);
//    cout << *min << " " << *max << endl;

    // 第三个参数代表初始值
//    auto add = [](int sum, int a) { return sum + 666; };
//    auto sum = accumulate(v.begin(), v.end(), 0, add);
//    cout << "sum: " << sum << endl;

    // STL的nth_element是一个非常有用的算法，它用于重新排列元素，
    // 以便第n个位置的元素（假如所有元素都经过排序）会出现在其应有的位置上，
    // 而且它前面的所有元素都不大于它，它后面的所有元素都不小于它。
//    nth_element(v.begin(), v.begin() + 3, v.end());
    // 输出调整后位于第4位置的元素（索引为3，因为开始于0）
//    cout << "The fourth element is " << v[3] << '\n';

    vector<int> v1;
    copy_if(v.begin(), v.end(), back_inserter(v1),
            [](int item){ return item >= 4; });

    for (auto item: v1) {
        cout << item << " ";
    }

    return 0;
}