#include <iostream>

#define PRESS_REFERENCE true
#define PRESS_VALUE false

class testClass
{
    private:
        int number;

    public:
        testClass() : number(0) {}
        testClass(const int __num) : number(__num) {}

        int * getDataPointer() { return &number; }
        int getData() const { return number; }

#if PRESS_REFERENCE
        testClass & operator = (const testClass & __tClass) 
        { 
            if (this == &__tClass) { return *this; }

            number = __tClass.number;

            return *this;
        }
#endif

/*
    如果拷贝运算符按值传递的话，
    每调用一次函数都要经过一次拷贝构造函数。
*/
#if PRESS_VALUE
        testClass operator = (const testClass & __tClass) 
        { 
            if (this == &__tClass) { return *this; }
            
            number = __tClass.number;

            return * this;
        }
#endif
        friend std::ostream & operator << (std::ostream & __os, testClass & __tClass);

        ~testClass() {}
};

std::ostream & operator << (std::ostream & __os, testClass & __tClass)
{
    __os << "Number = " << __tClass.getData() << "\tAddress: " << __tClass.getDataPointer() << '\n';

    return __os;
}

int main(int argc, char const *argv[])
{
    testClass a1(10), a2(100), a3(45);

    std::cout << a1 << a2 << a3  << '\n';

    /*
        如果拷贝运算符按值传递，
        这里就多出了两次构造的开销，如果这个类很大，会产生大量开销。
    */
    a1 = a2 = a3;

    std::cout << a1 << a2 << a3  << '\n';
    return 0;
}

/*
    Number = 10     Address: 0x4fbddff70c
    Number = 100    Address: 0x4fbddff708
    Number = 45     Address: 0x4fbddff704

    Number = 45     Address: 0x4fbddff70c
    Number = 45     Address: 0x4fbddff708
    Number = 45     Address: 0x4fbddff704
*/