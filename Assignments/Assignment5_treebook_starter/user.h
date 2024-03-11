#include <set>
#include <string>

class User
{
public:
    // write special member functions, including default constructor!

    // default constructor
    User() = default;
    User(std::string name) noexcept;

    // 赋值的参数应该是另外一个对象
    User(User &&other) noexcept;
    User &operator=(User &&other) noexcept;

    // 禁用复制
    User(const User &) = delete;
    User &operator=(const User &) = delete;

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);

    // add the < operator overload here!
    friend bool operator<(const User &a, const User &b);

private:
    std::string name;
    std::set<User> friends;

};