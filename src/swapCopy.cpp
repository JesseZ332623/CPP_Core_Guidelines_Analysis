#include <MyLib/myLogerDef.h>

#include <algorithm>

using namespace MyLib::MyLoger;

class Count
{
    private:
        int * data;
        std::size_t dataLength;

    public:
        Count(int value, int n) : data(new int[n]), dataLength(n) { std::fill_n(this->data, n, value); }

        Count(const Count &);

        std::size_t getSize(void) const noexcept { return this->dataLength; }

        int front(void) const { return this->data[0]; }

        void display(void) const 
        { 
            std::for_each(
                this->data, this->data + this->dataLength, 
                [](const int n) { std::cout << n << ' '; }
            ); 
        }

        friend void swap(Count & a, Count & b) noexcept
        {
            std::swap(a.data, b.data);
            std::swap(a.dataLength, b.dataLength);
        }

        Count & operator=(const Count & __count);

        Count & operator=(Count && __count) noexcept;

        ~Count() { delete[] this->data; }
};

Count::Count(const Count & __count) : data(new int[__count.getSize()]), dataLength(__count.getSize())
{
    std::fill_n(this->data, __count.getSize(), __count.front());    
}

Count & Count::operator=(const Count & __count)
{
    Count tempCount(__count);   // 构造出一个临时的 Count 类对象

    swap(*this, tempCount);     // 将临时对象和本体交换

    return *this;
}

Count & Count::operator=(Count && __count) noexcept
{
    Count tempCount(std::move(__count));    // 对于右值，要做移动操作
    swap(*this, tempCount);

    return *this;
}

int main(int argc, char const *argv[])
{
    Count count_a(5, 5);

    Count count_b(0, 5);
    count_b = count_a;

    count_a.display();
    count_b.display();

    return EXIT_SUCCESS;
}
