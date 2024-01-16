#include "./Widget.h"

/*
    调用 std::unique_ptr<impl> 的构建函数，
    并使用 std::make_unique<impl>(__n) 去实例化 impl 类，
    参数 __n 会作为 Widget::impl 类构建函数的参数去创建这个类。

    这样我们在实例化 Widget 类的时候，也实例化了 Widget::impl 类，
    并使用一个唯一指针去指向它。 
*/
Widget::Widget(int __n) : pimpl(std::make_unique<impl>(__n)) {}

/*
    Widget::draw() 会通过智能指针 pimpl 调用 Widget::impl::draw，
    并传入 Widget 类对象它本身。
*/
void Widget::draw() { pimpl->draw(*this); }