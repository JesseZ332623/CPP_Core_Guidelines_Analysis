#include <iostream>
#include <iomanip>

namespace Distance
{
    class MyDistance
    {
        private:
            double meter;       // 数据，单位：米

        public:
            /*
                单参构建函数没有 explicit 关键字
            */
            //explicit 
            MyDistance(const double __dis) noexcept : meter(__dis) {}

            // 将两个对象的私有数据相加并返回一个新对象
            friend MyDistance operator+(const MyDistance & __disA, const MyDistance & __disB) 
            { 
                return MyDistance(__disA.meter + __disB.meter); 
            }

            // 输出该类的私有数据
            friend std::ostream & operator<<(std::ostream & __os, const MyDistance & __myDis)
            {
                __os << __myDis.meter << " Meter.";

                return __os;
            }
    };

    /*
        C++11 新增的 用户定义字面量，可以让表达式更具可读性。

        表达式 operator"" _Km(100) 等价于 100_Km
    */
    namespace Unit
    {
        MyDistance operator "" _Km(long double __d) { return MyDistance(1000 * __d); }

        MyDistance operator "" _M(long double __m) { return MyDistance(__m); }

        MyDistance operator "" _Dm(long double __d) { return MyDistance(__d / 10); }

        MyDistance operator "" _Cm(long double __c) { return MyDistance(__c / 100); }
    }
}

int main(int argc, char const *argv[])
{
    using namespace Distance::Unit;

    /*小数点输出不超过 7 位*/
    std::cout << std::setprecision(7);

    // 没有任何问题
    std::cout << "1.0_Km + 2.0_Dm + 3.0_Cm = " << 1.0_Km + 2.0_Dm + 3.0_Cm << '\n';

    /* 
        由于 Distance::MyDistance 类的单参构造函数没有被 expicit 关键字修饰，5.5 后面没有跟用户定义字面量，表达式

        4.2_Km + 5.5 + 10.0_M + 0.3_Cm

        会等价于：

        operator+(operator+(operator+(operator "" _Km(4.2), Distance::MyDistance(5.5)), operator"" _M(10.0)), operator ""_Cm(0.3));

        显然，5.5 会通过类构造函数完成类型转换，得出的结果会不符合直觉且不易发现。

        但是如果该类的单参构造函数被 expicit 关键字修饰，编辑器很快就会报错：没有与这些操作数匹配的 "+" 运算符
    */
    std::cout << "4.2_Km + 5.5_Dm + 10.0_M + 0.3_Cm = " << 4.2_Km + 5.5 + 10.0_M + 0.3_Cm << '\n';

    return 0;
}
