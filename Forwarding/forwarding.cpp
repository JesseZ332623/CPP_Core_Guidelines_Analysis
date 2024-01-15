#include <utility>
#include <iostream>

/**
 * @brief 使用 std::forward 对用户传入的参数进行完美转发（即保持左值的左值性，以及右值的右值性）
 * 
 * @tparam Type~TypeN 使用形参包，可以将 n 个数据打包。
 * 
 * @param  typeN     用户传入的 n 个数据的右值引用，都会通过形参包打包。
 * 
 * @return 将形参包中的数据全部解包，转发到某个类型的构建函数中，构造出一个临时对象，最后通过移动语义返回。
*/
template <typename Type, typename ... TypeN>
Type create(TypeN && ... typeN)
{
    return Type(std::forward<TypeN>(typeN)...);
}

struct MyType
{
    private:
        int count;
        double score;
        bool ifValue;

    public:
        MyType(int __c, double __s, bool __ifVal) : count(__c), score(__s), ifValue(__ifVal) {}

        friend std::ostream & operator<<(std::ostream & __os, struct MyType & myType);

};

std::ostream & operator<<(std::ostream & __os, struct MyType & myType)
{
    __os << myType.count << '\t' << myType.score << '\t' << ((myType.ifValue) ? "true" : "false") << '\n';

    return __os;
}

int main(int argc, char const *argv[])
{
    int myTypeCount = 25;
    // 转发 3 个参数，构建后返回：（左值，右值，右值）
    MyType myType = create<MyType>(myTypeCount, 88.60, true);

    long double decimal = 3.1415926535;
    // 转发 1 个参数：（左值）
    long double myDecimal = create<long double>(decimal);

    // 转发 1 个参数：（右值）
    int myInteger = create<int>(114514);

    // 无参转发，结果为 0
    int empty = create<int>();

    std::cout << myType;
    std::cout << myDecimal << '\t' << myInteger << '\t' << empty << '\n';
    
    return EXIT_SUCCESS;
}
