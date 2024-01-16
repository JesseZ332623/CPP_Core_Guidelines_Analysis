#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <iostream>
#include <algorithm>
#include <memory>
/*
    使用 PImpl（Pointer to implementation 指向实现的指针） 编程技巧，
    将实现的细节放在另一个类上，从而将其从类中移除。而这个包含实现细节的类是通过指针访问的。

    这么做的原因是：私有数据成员会参与类的内存布局，而私有函数成员会重载决策。
    这些依赖意味着对成员实现细节的修改会导致所有类的用户都需要重新编译。

    持有指向实现的指针（PImpl）的类可将用户隔离在类实现的变化之外，而代价是多了一次间接访问。
*/
class Widget
{
    private:
        /*创建一个名为 impl 的类，具体实现放在外部*/
        class impl;

        /*
            再创建一个 impl 类型的唯一指针 pimpl，
            所有类的成员方法都要通过这个智能指针去间接访问 impl 类中的数据或接口。
        */
        std::unique_ptr<impl> pimpl;

    public:
        Widget(int __n);  /*构建函数，定义在实现文件中*/

        void draw();      /*公共接口 draw，将会转发给实现*/

        /*
            由于没有声明裸指针或其他复杂的数据，
            所以使用默认的 移动构造函数 和 移动语义 即可。
        */
        Widget(Widget &&) = default;
        Widget & operator=(Widget &&) = default;

        /*禁用 拷贝构造函数 和 拷贝运算符，转而使用移动构造函数*/
        Widget(const Widget &) = delete;
        Widget & operator=(Widget &) = delete;

        /*
            由于没有声明裸指针或其他复杂的数据，
            使用默认析构函数即可。
        */
        ~Widget() = default;
};

/*Widget::impl 类的具体实现*/
class Widget::impl
{
    private:
        int data;
    
    public:
        impl(int __n) : data(__n) {}

        /*收到来自 Widget 类对象的转发，才会调用 draw 输出信息。*/
        void draw(const Widget & __w) { std::printf("Drwa data: %d.\n", data); }
};


#endif