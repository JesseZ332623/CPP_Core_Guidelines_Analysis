#include <iostream>
#include <algorithm>
#include <vector>
#include <span>

/*
    在 C++ 中有很多 STL 算法和容器能帮你优雅的解决数组传递的问题，
    比如 std::vector 和 std::span

    std::span 是一个对象，它可以指代连续存储的一串对象，它永远不是所有者。
    而这段连续的内存可以是数组，或者带有大小的指针，也可以是 STL 容器。

    tips: 当前使用 std::span 不知为何编译不了，以后再研究。

    说实话，个人感觉这种用法有些多此一举，明明针对容器的拷贝用 std::copy 就行了。。。。
*/

template <typename Type>
void copyContainer(std::span<const Type> __src, std::span<Type> __dest);

template <typename Type>
void copyContainer(std::span<const Type> __src, std::span<Type> __dest)
{
    if (__dest.size() < __src.size())
    {
        throw std::out_of_range("__dest is to small.");
    }

    auto destIterator = __dest.begin();

    for (const auto & element : __src) { *destIterator++ = element; }
    
}

int main(int argc, char const *argv[])
{
    std::vector<int> srcVector = {1, 2, 3, 4, 5};
    std::vector<int> destVector(srcVector.size());

    auto printContent = [](const int & __n) { std::cout << __n << ' '; };

    //copyContainer(srcVector, destVector);

    std::copy(srcVector.begin(), srcVector.end(), destVector.begin());

    std::for_each(srcVector.begin(), srcVector.end(), printContent); std::putchar('\n');
    std::for_each(destVector.begin(), destVector.end(), printContent);

    return EXIT_SUCCESS;
}