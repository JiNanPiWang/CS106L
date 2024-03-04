//
// Created by Samsara on 2024/3/4.
// File name: Lecture15.cpp
// Description: 
//
#include <iostream>
#include <utility>

using std::cout, std::endl;

class Drink
{
public:
    explicit Drink() = default;
    explicit Drink(std::string flavor) : _flavor(std::move(flavor)) {}

    virtual void make() = 0;

    virtual ~Drink() = default;

private:
    std::string _flavor;
};