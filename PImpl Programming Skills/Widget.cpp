#include "./Widget.h"

class Widget::impl
{
    private:
        int data;
    
    public:
        impl(int __n) : data(__n) {}

        void draw(const Widget & __w) { printf("draw data: %d.\n", data); }
};

Widget::Widget(int __n) : pimpl(std::make_unique<impl>(__n)) {}

//Widget & Widget::operator=(Widget &&) = default;

void Widget::draw() { pimpl->draw(*this); }

Widget::~Widget() = default;



int main(int argc, char const *argv[])
{
    Widget testWidget(12);

    testWidget.draw();

    return EXIT_SUCCESS;
}
