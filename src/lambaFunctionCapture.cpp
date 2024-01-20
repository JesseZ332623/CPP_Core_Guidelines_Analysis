/*
    functional 头文件提供了很多在函数式编程范式中会用到的工具，
    通过这些工具可以更方便地使用和组合各种函数或函数对象。

    使用 functional 头文件,可以编写出更加抽象和通用的算法。
*/
#include <functional>
#include <iostream>
#include <string>

auto makeLamba();

auto makeLamba()
{
    /*
        创建一个临时字符串，它的作用域仅限这个函数。
    */
    const std::string tempString = "On Stack Create.";

    /*Lamba 表达式捕获这个字符串，并返回这个字符串，最后函数返回这个 Lamba 表达式*/
    return [&tempString]() { return tempString; };
}

int main(int argc, char const *argv[])
{
    /*
        显然，tempString 在函数运行结束后已经过期，
        期间由于引用传递，没有发生拷贝。

        因此，这个函数所引用的字符串已经不存在了，
        执行它只会造成未定义行为，要么输出乱码，要么什么也不输出，不可预测。
    */
    auto bedLamba = makeLamba();

    /*未定义行为*/
    std::cout << bedLamba() << '\n';

    return EXIT_SUCCESS;
}