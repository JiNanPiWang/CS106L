#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!


    User(std::string name);

    // getter functions
    std::string getName() const;
    std::set<User> getFriends() const;

    // setter functions
    void setName(std::string name);

    // TODO: add the < operator overload here!
    
private:
    std::string name;
    std::set<User> friends;

};