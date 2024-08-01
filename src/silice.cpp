#include <iostream>
#include <MyLib/myLogerDef.h>

#if false
struct Base 
{
    int base{1998};
};

struct Derived : Base
{
    int derived{2011};
};

/**
 * @brief 传入一个基类（Basic Class）进行操作。
 */
void needB(Base base) {}

int main(int argc, char const *argv[])
{
    Derived derived;            // 创建一个子类

    /**
     * 创建一个基类，接受子类的拷贝，
     * derived 会强制转换成 Base 类型，切掉子类的数据。
     * 
     * (1) (2) (3) 皆是如此。
     */
    Base    base = derived;     // (1)

    Base derived_2(derived);    // (2)

    needB(derived);             // (3)
    
    return EXIT_SUCCESS;
}
#endif

struct Base
{
    virtual std::string getName(void) const { return {"Base\n"}; }
};

struct Derived : Base
{
    /**
     * @brief 重载 Base::getName() 返回字符串 "Derived"
     */
    std::string getName(void) const override { return {"Derived\n"}; }
};

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLoger;

    Base base_1;
    NOTIFY_LOG(base_1.getName());

    Derived derive_1;
    NOTIFY_LOG(derive_1.getName());

    Base base_2 = derive_1;
    NOTIFY_LOG(base_2.getName());

    Base & base_3 = derive_1;
    NOTIFY_LOG(base_3.getName());

    Base * base_4 = new Derived;
    NOTIFY_LOG(base_4->getName());

    return EXIT_SUCCESS;
}
