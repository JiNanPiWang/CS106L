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

    explicit Drink(std::string flavor) : _flavor((std::move(flavor))) {}

    virtual void make()
    {
        cout << "Made tea from Drink class!" << endl;
    }

    virtual ~Drink() = default;

private:
    std::string _flavor;
};

// 使用 public 继承时，基类的 public 成员在派生类中仍然是 public，protected 成员在派生类中变成 protected，而 private 成员在派生类中仍然是 private。
// 派生类对象可以直接访问基类的 public 和 protected 成员，但不能直接访问基类的 private 成员。其余同理
class Tea : public Drink
{
public:
    Tea() = default;

    explicit Tea(std::string flavor) : Drink(std::move(flavor)) {}

    ~Tea() override = default;

    void make()
    override
    {
        cout << "Made tea from Tea class!" << endl;
    }
};

int main()
{
    Tea t("red");

    // 使用make()和Drink::make()
    t.make();
    t.Drink::make();

    return 0;
}