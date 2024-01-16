#include <iostream>
#include <set>
#include <tuple>

int main(int argc, char const *argv[])
{
    std::set<int> mySet;
    std::set<int>::iterator setIter;

    bool ifInsert = false;

    /*
        std::set<int>::insert() 会返回一个 std::pair<std::set<int>::iterator, bool>
        第一个类型是指向插入元素的迭代器，还有一个布尔类型，表示是否插入成功（插入成功则为 true）

        因此可以使用 std::tie 将这 insert 返回的 pair 解包到 setIter 和 ifInsert 之中。
    */
    std::tie(setIter, ifInsert) = mySet.insert(2023);

    if (ifInsert) { printf("2023 was inserted successfully.\n"); }

    /*
        使用结构化绑定（C++17）将 insert 的返回值解包到 setIter2 和 ifInsert2 中。

        和 std::tie 相比，结构化绑定不需要预先声明变量，编译器会自行推断。
    */
    auto [setIter2, ifInsert2] = mySet.insert(2024);

    if (ifInsert2) { printf("2024 was inserted successfully.\n"); }

    printf("%d %s\n", *setIter2, ((ifInsert2) ? "true" : "false"));

    for (auto n : mySet) { printf("%d ", n); } std::puts("");


    return EXIT_SUCCESS;
}
