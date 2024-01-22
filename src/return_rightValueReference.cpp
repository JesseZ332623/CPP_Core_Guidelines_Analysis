// return_rightValueReference.cpp

#include <iostream>

/**
 * 函数不要返回右值引用，和 std::move，下面用一个简单的函数举例：
*/

#if false
int && returnRightValueReference()
{
    /*
        int{114514} 创建了一个临时的左值，它的作用域仅限这个函数，因此编译器会发出警告：“返回了一个临时的引用”。

        g++ .\src\return_rightValueReference.cpp -o .\bin\return_rightValueReference
        .\src\return_rightValueReference.cpp: In function 'int&& returnRightValueReference()':
        .\src\return_rightValueReference.cpp:11:12: warning: returning reference to temporary [-Wreturn-local-addr]
        11 |     return int{114514};
            |           ^~~~~~~~~~~
    */
     return int{114514};
}
#endif

/**
 * @brief 这个函数的执行过程是这样的：
 *  1. 传入字符串的引用
 *  2. 调用 move 转移源字符串的所有权，形成一个临时右值引用，然后再返回，可以看作是将 __str 的所有权交给了另一个 字符串。
 * 
 * @param __str 传入字符串的引用
 * 
 * @return 函数返回后，接收这个函数的变量需要经历拷贝构造，会有不必要的开销。
 * 由于 ROV 和 NROV 的拷贝消除，这中操作对于函数来说不是优化而是劣化。
*/
std::string && returnStdMove(std::string & __str)
{
    return std::move(__str);
}

int main(int argc, char const *argv[])
{
    // auto rvReference = returnRightValueReference();

    std::string str = "AAA";

    auto value = returnStdMove(str);

    printf("%s %s", value.c_str(), str.c_str());

    return EXIT_SUCCESS;
}
