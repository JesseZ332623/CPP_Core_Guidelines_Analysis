#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <iostream>
#include <algorithm>
#include <memory>

class Widget
{
    private:
        class impl;
        std::unique_ptr<impl> pimpl;

    public:
        Widget(int);  

        void draw();

        Widget(Widget &&) = default;
        Widget & operator=(Widget &&) = default;

        /*禁用 拷贝构造函数 和 拷贝运算符，转而使用移动构造函数*/
        Widget(const Widget &) = delete;
        Widget & operator=(Widget &) = delete;

        ~Widget();
};

#endif