#include <cstddef>

/*
    演示一个没有明确定义深拷贝和移动语义的类在进行默认拷贝（浅拷贝）时，
    由于重复删除同一地址所发生的未定义行为。
*/

class BigClass
{
    private:
        int * __array;
        std::size_t length;

    public:
        BigClass(std::size_t __len = 0) : __array(new int[__len]), length(__len) {}

        /*
            期间没有明确定义深拷贝和移动语义
        */

        ~BigClass() { delete __array; }
};

int main(int argc, char const *argv[])
{
    /**
     * 创建了两个类 A，B。A 仅仅拷贝了自己的成员变量 __array 所指向内存的地址给 B，
     * 因此 A 和 B 持有同一个地址的数据，当 main 函数运行结束，对象 A，B 调用析构函数就会将同一片内存释放两次，
     * 造成未定义行为。
    */

    BigClass objectA(100);
    BigClass objectB = objectA;

    return 0;
}
