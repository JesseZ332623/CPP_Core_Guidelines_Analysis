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
    const int arrayA[] = {12, 13, 14, 764470};
    int arrayB[4] = {0};

    std::span srcSpan(arrayA);
    std::span destSpan(arrayB);

    //copyContainer(srcSpan, destSpan);

    return EXIT_SUCCESS;
}