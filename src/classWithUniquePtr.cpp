#include <iostream>
#include <MyLib/myLogerDef.h>

#include <memory>

struct MyClass
{
    /**
     * 一个唯一指针 uniPtr，维护了一个在堆上的整数 114514
     * 
     * std::unique_ptr 拥有资源的绝对所有权，不允许拷贝
     */
    std::unique_ptr<int> uniPtr = std::make_unique<int>(114514);

    void display(void) const { printf("%d\n", this->uniPtr.operator*()); }
};

int main(int argc, char const *argv[])
{
    MyClass classA;

    // 相关拷贝操作都是不允许的。

    //MyClass classB(classA);

    MyClass classC;
    //classC = classA;

    classA.display();
    
    return 0;
}
