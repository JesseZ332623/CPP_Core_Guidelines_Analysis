#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

/*
    通过将函数声明为 noexcept，可以禁止该函数抛出异常。
    noexcept 关键字在该语境下意味着：我不在乎异常。

    其原因可能是：程序员无法对这个异常做出反应，这种情况下就只能调用 std::terminated() 去强行终止程序。

    此外，以下类型的函数永远都不要抛异常：
        默认构建，构建，析构 函数
        移动操作函数
        swap 函数
*/

/**
 * @brief 从标准输入流（通常是键盘）中读取数据并存入这个字符串 vector 中，
 * 该函数会在内存耗尽时崩溃。
 * 
 * @param __is 标准输入流的引用
 * 
 * @return 完成输出后返回的字符串 vector
*/
std::vector<std::string> collect(std::istream & __is) noexcept;

std::vector<std::string> collect(std::istream & __is) noexcept
{
    std::vector<std::string> result;
    
    /*
        若传入的输入流是 std::cin，即重定向到键盘，
        在循环内没有使用 break continue 关键字的话，该循环就是死循环。

        若传入的是一个文件 std::ifstream 或者别的程序（pipe），且数据量足够大时，也会因为内存耗尽奔溃。
    */
    for (std::string s; std::getline(__is, s);)
    {
        //if (s == "quit") { break; }
        result.push_back(s);
    }

    //while (std::getchar() != '\n') { continue; }
    
    return result;
}

int main(int argc, char const *argv[])
{
    std::ifstream targetFileRead("./data/target.txt", std::ios_base::in);
    
    std::vector<std::string> stringSet = collect(targetFileRead);

    std::for_each(stringSet.begin(), stringSet.end(), [](const std::string & __s) -> void { std::cout << __s << '\n'; });

    return EXIT_SUCCESS;
}
