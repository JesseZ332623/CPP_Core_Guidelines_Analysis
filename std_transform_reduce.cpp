#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <execution>

/**
 * @brief 使用循环来 串行的求取 vector 内所有字符串的长度之和，这种方法易于理解，
 * 但数据量大起来就歇菜了。
 * 
 * @param __strVec 传入的源 std::vector
 * 
 * @return vector 内所有字符串的长度之和
*/
size_t getLengthCount(std::vector<std::string> & __strVec);

/**
 * @brief 使用 std::transform_reduce 和并行策略（std::execution::par）来求取 vector 内所有字符串的长度之和。
 * 这种方法在数据量较大时非常有效。此外，为了安全起见，使用了函数模板提高安全性，避免滥用 auto。
 * 
 * @param __strVec      传入的源 std::vector
 * @param __add         计算的规则
 * @param __eachLength  返回每个字符串之长
 * 
 * @return vector 内所有字符串的长度之和
*/
template <typename Add, typename LengthFunc>
size_t getLengthCount(std::vector<std::string> & __strVec, Add __add, LengthFunc __eachLength);

size_t getLengthCount(std::vector<std::string> & __strVec)
{
    size_t result = 0;

    for (auto elementString : __strVec) { result += elementString.size(); }

    return result;
}

template <typename Add, typename LengthFunc>
size_t getLengthCount(std::vector<std::string> & __strVec, Add __add, LengthFunc __eachLength)
{
    /*
        std::execution::par 可以指示该算法利用多核心 CPU 资源，并行地处理多个数据。
        初始值 std::size_t{0} 表示 reduce 操作的初始结果为 0。
    */
    return std::transform_reduce(std::execution::par, __strVec.begin(), __strVec.end(), std::size_t{0}, __add,  __eachLength);
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> stringVector = {"Only", "testing", "pourpose"};

    printf("The sum of string lengths inside the container = %zd.\n", getLengthCount(stringVector));

    printf("The sum of string lengths inside the container = %zd.\n", 
            getLengthCount(stringVector, 
                           [](size_t __a, size_t __b) { return __a + __b; }, 
                           [](std::string __s) { return __s.size(); })
          );
    return EXIT_SUCCESS;
}
