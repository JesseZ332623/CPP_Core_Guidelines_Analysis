#include <iostream>
#include <tuple>
#include <cstring>
/*
    F.21 要返回多个 “出” 值，优先考虑返回结构体或者元组。
*/

#define C true
#define CPP false

struct myStruct 
{
    int count;
    double price;
    char describe[25];
};

/**
 * @brief 输出结构体的内容
 * 
 * @param __myStruct 传入的非空结构体
 * 
 * @return non-return
*/
void showStructContent(const struct myStruct * __myStruct)
{
    if (!__myStruct) { return; }

    printf("%d\t%lf\t%s\n", __myStruct->count, __myStruct->price, __myStruct->describe);
}

/**
 * @brief           创建新结构体并返回这个结构体的指针
 * 
 * @param __c       数量
 * @param __p       价格
 * @param __desc    物品描述
 * 
 * @return          新结构体的指针
*/
struct myStruct * createStructData(int __c, double __p, const char * __desc)
{
    struct myStruct * newStruct = (myStruct *)malloc(sizeof(myStruct));

    if (!newStruct) { return NULL; }

    newStruct->count = __c;
    newStruct->price = __p;
    strcpy(newStruct->describe, __desc);

    return newStruct;
}

/**
 * @brief               修改结构体内的数据
 * 
 * @param __c           数量
 * @param __p           价格
 * @param __desc        物品描述
 * @param __beModify    要进行修改的目标结构体指针
 * 
 * @return              返回修改后的结构体指针
*/
struct myStruct * modifyStructData(int __c, double __p, const char * __desc, struct myStruct * __beModify)
{
    if (!__beModify) { return NULL; }

    __beModify->count = __c;
    __beModify->price = __p;
    strcpy(__beModify->describe, __desc);

    return __beModify;
}

/*
    而到了 C++，就有更加先进的方法来返回多个数据。比如在 C++11 版本引入的元组（tuple）。
*/
/**
 * @brief               传入一些数据，将这些数据组装成一个元组并返回
 * 
 * @param __c           数量
 * @param __p           价格
 * @param __desc        物品描述
 * 
 * @return              返回这些数据组装成的元组
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
    struct myStruct *newShop = createStructData(1000, 90.05, "Phone");

    showStructContent(newShop);

    modifyStructData(98, 15.50, "Apple", newShop);

    showStructContent(newShop);

    free(newShop);
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
