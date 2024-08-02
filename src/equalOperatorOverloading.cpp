#include <MyLib/myLogerDef.h>

using namespace MyLib::MyLoger;

class MyBadInt
{
    private:
        int number;

    public:
        MyBadInt(int n) : number(n) {}

        /**
         * @brief 这样的等号重载是正确但不够好的，它可以适应
         *        MyBadInt(5) == 5;
         * 
         *       但不能适应：
         *       5 == MyBedInt(5); 
         */
        bool operator==(const MyBadInt & __myBedInt) 
        { return this->number == __myBedInt.number; }
};

class MyGoodInt
{
    private:
        int number;

    public:
        explicit MyGoodInt(int n) : number(n) {}

        /**
         * 而向下面的 == 运算符重载的设计，更全面，更合理，
         * 适合所有的情况。
         */
        friend bool operator==(const MyGoodInt & a, const MyGoodInt & b)
        { return a.number == b.number; }

        friend bool operator==(int number, const MyGoodInt & a)
        { return number == a.number; }

        friend bool operator==(const MyGoodInt & a, int number)
        { return a.number == number; }
};

struct Base 
{
    std::string str;
    int number;

    virtual bool operator==(const Base & base) const
    {
        return (str == base.str) && (base.number == number);
    }
};

struct Derived : Base
{
    char charactor;

    /**
     * @brief  看似正常的 == 运算符重载，其实暗藏隐患。
    */
    virtual bool operator==(const Derived & derived) const
    {
        return (this->str       == derived.str)     && 
               (this->number    == derived.number)  &&
               (this->charactor == derived.charactor);
    }
};

int main(int argc, char const *argv[])
{
    MyGoodInt(5) == 5;                  // OK

    5 == MyGoodInt(5);                  // OK

    MyGoodInt(5) == MyGoodInt(5);       // OK

    Base base;
    Base & baseRef = base;

    Derived derived;
    Derived & derivedRef = derived;
    
    /**
     * 比较了 str 和 number，但是忽略了 charactor。
     */
    base == derived;
    
    /**
     * 要么不合法，要么和上面一样
     */
    derived == base;

    Derived derived_2;

    derived == derived_2;   // OK

    Derived & derivedRef_2 = derived_2;

    derivedRef_2 == derivedRef; // OK

    return EXIT_SUCCESS;
}
