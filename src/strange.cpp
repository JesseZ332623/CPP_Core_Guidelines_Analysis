#include <iostream>

/*
    明确了深拷贝构造函数，
    但是拷贝运算符却用的是默认的，这也会造成未定义行为。
*/
struct Strange
{
    public:
        int * __data;

    Strange() : __data(new int(2011)) {}

    // 使用了深拷贝
    Strange(const Strange & __dat) : __data(new int(*__dat.__data)) {}

    // 使用了浅拷贝
    Strange & operator=(const Strange & __dat) = default;

    ~Strange() { delete __data; }
};

int main(int argc, char const *argv[])
{
    Strange objectA;
    Strange objectB(objectA);   // 使用深拷贝

    puts("Deep Copy:");
    printf("ObjectA Value = %d\tAddress = %p\nObjectB Value = %d\tAddress = %p\n",
    *(objectA.__data), objectA.__data, *(objectB.__data), objectB.__data);

    Strange objectC;

    /*
        使用浅拷贝。
        显然两个对象同时持有同一片内存上的指针，
        在析构时会将同一片内存释放两次，造成未定义行为。
    */
    objectC = objectA;          

    puts("Shallow Copy:");
    printf("ObjectA Value = %d\tAddress = %p\nObjectB Value = %d\tAddress = %p\n",
    *(objectA.__data), objectA.__data, *(objectC.__data), objectC.__data);


    return EXIT_SUCCESS;
}
