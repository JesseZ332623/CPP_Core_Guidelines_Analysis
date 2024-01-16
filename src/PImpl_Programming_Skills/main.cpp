#include "./Widget.h"

int main(int argc, char const *argv[])
{
    Widget widgetA(12);
    Widget widgetB(21);

    /*
        使用这个类的人不需要关系这个接口需要什么参数和以及具体的实现过程。
        成功的将数据和接口解耦，即便实现的细节有所变化，使用者也不必担心。
    */
    widgetA.draw();
    widgetB.draw();

    /*使用移动语义，将 B 的所有权转让给 A*/
    widgetA = std::move(widgetB);


    widgetA.draw();

    /*此时 B 就悬空了，在重新构建它之前不能再调用它*/
    //widgetB.draw();

    widgetB = Widget(123);

    widgetB.draw();

    return EXIT_SUCCESS;
}
