Assignment 5: Treebook

本题我认为有问题，他想实现的是一个用户类(`User`)，用户拥有名称(`std::string`)和朋友集合(`std::set<User>`)

题目要求 The class should be move assignable and move constructible, but not copy assignable or copy constructible. 要求我们**不能实现复制赋值和复制构造**，并且要求我们能够完成重载加法，加法让我们把对方放入我们的set，The+operator will representing adding a user to another user’s friend list。但是`std::set` 内部使用红黑树（Red-Black Tree）来实现有序集合。在插入或删除元素时，可能需要对元素进行重新平衡，这就涉及到对元素的复制。如果用户类(`User`)不支持复制构造和复制赋值，就无法满足`std::set`对元素进行操作的要求。

如果大家想做，可以把 `user.h` 中的 `std::set<User>` 为 `std::set<User*>`，或者无视不能实现复制赋值和复制构造的要求。

