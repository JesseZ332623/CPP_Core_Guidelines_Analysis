#include <algorithm>
#include <vector>
#include <iostream>
#include <cctype>

/*
    std::transform 对指定范围内的数据应用指定操作，并输出新的结果序列。
    它有 3 个重载版本，其参数列表如下：

    1. 单输入范围，单输出范围
        std::transform(begin, end, out, operation);
    对 begin - end 范围内的数据应用 operation 操作，将结果输出到 out 中。

    2. 双输入范围，单输出范围
        std::transform(begin_1, end_1, begin_2, out, operation);
    对 begin_1 - end_1，begin_2 - end_2 的同样大小的输入范围内的数据应用 operation 操作，
    将结果输出到 out 中。

    3. 单输入范围，双输出范围
        std::transform(begin, end, out_1, out_2, operation);
    对 begin_1 - end_1 应用 operation 操作，返回一个 pair 类型，
    pair.first 输出给 out_1，pair.second 输出给 out_2。
*/

/**
 * @brief 1. 单输入范围，单输出范围。
 * 对 begin - end 范围内的数据应用 operation 操作，将结果输出到 out 中（本函数是输出回它自己）。
 * 这种操作可以用在字符串的大小写转换上，一行代码搞定。
 *
 * @param __str 要进行操作的字符串引用
 *
 * @return non-return
 */
void toLower(std::string &__str);

/**
 * 2. 双输入范围，单输出范围
 * 对 begin_1 - end_1，begin_2 - end_2 的同样大小的输入范围内的数据应用 operation 操作，将结果输出到 __result 中。
 *
 * @param __vecA    要进行操作的容器 A
 * @param __vecB    要进行操作的容器 B
 * @param __result  返回的结果容器
 *
 * @return non-return
 */
void addVector(std::vector<int> &__vecA, std::vector<int> &__vecB, std::vector<int> &__result);

/**
 * 3. 单输入范围，双输出范围
 * 对 begin_1 - end_1 应用 operation 操作，返回一个 pair 类型，pair.first 输出给 out_1，pair.second 输出给 out_2。
 *
 * @param __vec    要进行操作的容器
 * @param __resultA  返回的结果容器 A
 * @param __resultB  返回的结果容器 B
 *
 * @return non-return
 * 
 * tips: 该版本在本机不知为何无法运行，以后再研究。
 */
void multiplyVectorToTwoVectors(std::vector<int> &__vec, std::vector<int> &__resultA, std::vector<int> &__resultB);

void toLower(std::string &__str)
{
    std::transform(__str.begin(), __str.end(), __str.begin(), [](char __ch) { return std::tolower(__ch); });
}

void addVector(std::vector<int> &__vecA, std::vector<int> &__vecB, std::vector<int> &__result)
{
    auto addRule = [](int __a, int __b) -> int { return __a + __b; };

    std::transform(__vecA.begin(), __vecA.end(), __vecB.begin(), std::back_inserter(__result), addRule);
}

#if false
void multiplyVectorToTwoVectors(std::vector<int> &__vec, std::vector<int> &__resultA, std::vector<int> &__resultB)
{
    auto pair = [](int x)
    { return std::make_pair(x * 2, x * 3); };

    std::transform(__vec.begin(), __vec.end(), std::back_inserter(__resultA), std::back_inserter(__resultB), pair);
}
#endif

int main(int argc, char const *argv[])
{
#if true
    std::vector<int> vectorA = {12, 21, 6, 9, 8};
    std::vector<int> vectorB = {1, 2, 3, 4, 5};
    std::vector<int> resultA;
    std::vector<int> resultB;

    auto printContent = [](const int & __n) { std::cout << __n << ' '; };

    addVector(vectorA, vectorB, resultA);

    std::for_each(resultA.begin(), resultA.end(), printContent); std::putchar('\n');
    //std::for_each(resultB.begin(), resultB.end(), printContent); std::putchar('\n');

#endif

    return EXIT_SUCCESS;
}
