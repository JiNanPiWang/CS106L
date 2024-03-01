//
// Created by Samsara on 2024/2/26.
// File name: Lecture13.cpp
// Description: 测试std::move效率，别用vector，因为它复制自动使用move
// 对比时，最好使用大内存的指针，因为这样差别很大
//
#include <iostream>
#include <chrono>
#include <cassert>

using std::cout, std::endl;

class Array
{
public:
    int size_;
    int *data_;

    explicit Array(int size) : size_(size), data_(new int[size]) {}

    Array(Array &other) : size_(other.size_), data_(new int[size_])
    {
        for (int i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    Array(Array &&other)  noexcept : size_(other.size_), data_(other.data_)
    {
        // 因为现在这个对象指向了other原来内存的内容，如果不清除other的指针，那么other析构时，会把data_也清除
        // 因为是std::move，返回右值引用
        other.data_ = nullptr;
    }

    Array &operator=(Array &&other) noexcept
    {
        if (*this != other)
        {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_; // 转移资源所有权
            other.data_ = nullptr;  // 避免源对象析构时释放资源
        }
        return *this;
    }

    bool operator==(const Array &rhs) const
    {
        return size_ == rhs.size_ &&
               data_ == rhs.data_;
    }

    bool operator!=(const Array &rhs) const
    {
        return !(rhs == *this);
    }

    virtual ~Array()
    {
        delete[] data_;
    }
};

void test(const Array &b, const Array &c)
{
    assert(b.size_ == c.size_);
    for (int i = 0; i < b.size_; ++i)
        assert(b.data_[i] == c.data_[i]);
}

int main()
{
    Array a(int(1e8)), c(int(1e8));
    for (int i = 0; i < a.size_; ++i)
    {
        a.data_[i] = rand();
        c.data_[i] = rand();
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    Array b(a);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    c = (std::move(a));
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

    std::cout << "Copy construction took " << duration1.count() << " microseconds\n";
    std::cout << "Move construction took " << duration2.count() << " microseconds\n";

    test(b, c);
    cout << "Move constructor equals copy constructor, move correct!" << endl;
    return 0;
}