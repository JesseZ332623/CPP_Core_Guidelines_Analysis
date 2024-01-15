#include <utility>
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

// std::make_unique 一种可能的实现

namespace myStd
{
    /**
     * @brief make_unique 一种可能的实现，利用变长参数模板，std::forward 完美转发，以及移动语义优化。
     * 
     * @tparam Type 传入参数的类型，使用形参包打包。
     * 
     * @param __args 用户传入的参数，被形参包打包。
     * 
     * @return 解包形参包，通过 std::forward 转发到 Type 类型的构建函数中，构造出一个匿名临时对象，
     * 利用 new 关键在在堆中创建该对象，以移动语义转移所有权给 std::unique_ptr<Type> 的构造函数，
     * 构造出一个 std::unique_ptr<Type> 类型的对象，最后返回 std::unique_ptr<Type> 类型的对象，去动态的管理所创建的 Type 对象。
    */
    template <typename Type, typename ... Args>
    std::unique_ptr<Type> make_unique(Args&& ... __args)
    {
        return std::unique_ptr<Type>(new Type(std::forward<Args>(__args)...));
    }
};

int main(int argc, char const *argv[])
{
    const std::vector<int> a = {345, 134, 13, 254, 3, 476536, 235};
    std::unique_ptr<std::vector<int>> vectorPointer = myStd::make_unique<std::vector<int>>(a);

    std::for_each(vectorPointer->begin(), vectorPointer->end(), [](const int __n) { printf("%d ", __n); }); puts("");

    vectorPointer->at(1) = 431;

    std::for_each(vectorPointer->begin(), vectorPointer->end(), [](const int __n) { printf("%d ", __n); });

    return EXIT_SUCCESS;
}
