#include <iostream>

/*
    constexpr 函数是可能在编译期间运行的函数。
    当在常量表达式中调用该关键字修饰的函数时，
    或者用一个该关键字修饰的变量来获取 constexpr 函数的返回值时，它会在编译期运行。
    也可以用只能在运行期求值的参数来调用 constexpr 函数，这种函数是隐含内联的。

    constexpr 函数的返回值通常会被标记为只读的（存放在只读/静态存储区），且该函数具有以下的好处：

    1.  性能更好

    2.  在编译期求值的 constexpr 函数 是纯函数，因此是线程安全的，可以并行执行。
*/

/**
 * @brief 以辗转相除法的实现为例，
 * 可以使用 constexpr 关键字修饰该函数，让它在编译期内求值。
 * 
 * @param __a 整数 A
 * @param __b 整数 B
 * 
 * @return A 和 B 的最大公约数
*/
constexpr auto gcd(int __a, int __b);

constexpr auto gcd(int __a, int __b)
{
    while (__b != 0)
    {
        auto t = __b;
        __b = __a % __b;
        __a = t;
    }

    return __a;
}

int main(int argc, char const *argv[])
{
    /*使用 constexpr 让 gcd 在编译器运行，变量 result 是只读的，不容修改。*/
    constexpr int result = gcd(11, 121);

    int a = 11, b = 121;

    /*正常运行*/
    int resultB = gcd(a, b);

    printf("%d %d", result, resultB);

    return EXIT_SUCCESS;
}
