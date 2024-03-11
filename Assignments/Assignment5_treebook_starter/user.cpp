#include "user.h"
#include <set>
#include <iostream>
#include <string>
#include <utility>


User::User(std::string name) {
// TODO: Implement the additional constructor here!
    this->name = std::move(name);
}

std::string User::getName() const {
    return name;
}

std::set<User> User::getFriends() const {
    return friends;
}

void User::setName(std::string name) {
    this->name = name;
}

// TODO: Implement the < operator overload here!