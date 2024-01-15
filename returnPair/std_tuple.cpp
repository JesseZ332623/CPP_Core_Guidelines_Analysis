#include <iostream>
#include <tuple>
#include <cstring>
/*
    F.21 要返回多个 “出” 值，优先考虑返回结构体或者元组。
*/

#define C false
#define CPP true

struct myStruct 
{
    int count;
    double price;
    char describe[25];
};
/*
    输出结构体的内容
*/
void showStructContence(const struct myStruct * __myStruct)
{
    printf("%d\t%lf\t%s\n", __myStruct->count, __myStruct->price, __myStruct->describe);
}

/*
    在 C 语言中，返回多个值，一般只能返回：数组，字符串，结构体，而且一般只返回它们的指针。
    先演示结构体的返回：
*/
myStruct * modifyStructData(int __c, double __p, const char * __desc, struct myStruct * __beModify)
{
    __beModify->count = __c;
    __beModify->price = __p;
    strcpy(__beModify->describe, __desc);

    return __beModify;
}

/*
    而到了 C++，就有更加先进的方法来返回多个数据。比如在 C++11 版本引入的元组（tuple）。
*/
auto returnTuple(int __c, double __p, std::string __desc)
{
    /*
        使用 std::tie 将传入的数据打包成一个元组并返回。
    */
    return std::tie(__c, __p, __desc);
}

int main(int argc, char const *argv[])
{
#if C
    struct myStruct newShop = {100, 12.67, "Apple"};

    showStructContence(&newShop);

    struct myStruct *newShopPointer = modifyStructData(98, 15.50, "Apple", &newShop);

    showStructContence(newShopPointer);
#endif

#if CPP
    /*将 3 个数据打包成元组返回给 newTuple*/
    auto newTuple = returnTuple(19, 18.50, "Potato");

    /*使用结构化绑定（C++17）拆包 newTuple 元组*/
    auto [count, price, describe] = newTuple;

    /*输出*/
    std::cout << count << ' ' << price << ' ' << describe << '\n';
#endif
    
    return EXIT_SUCCESS;
}
