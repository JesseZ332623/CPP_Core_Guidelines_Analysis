#include <MyLib/myLogerDef.h>

using namespace MyLib::MyLoger;

/**
 * @brief   C.120
 *         （仅）使用类的层次结构来表示具有内在层次结构的概念
 * 
 *          如果代码中要建模的东西具有内在的层次结构，就应该使用层次结构，
 *          这在一些 GUI 程序的设计上很常见。
*/

/**
 * @brief 作为最底层的接口，提供基础的渲染工作。
 */
class DrawableUIElement
{
    public:
        /**
         * @brief rander() 为纯虚函数，不可实例化，
         *        需要派生出子类去实现。
         */
        virtual void rander() const = 0;
};

/**
 * @brief 一个抽象的按钮类，也是虚基类。
 */
class AbstractButton : public DrawableUIElement
{
    public:
        /**
         * @brief onClick() 也是纯虚函数，不可实例化，
         *        需要派生出子类去实现。
         */
        virtual void onClick() = 0;
};

/**
 * @brief PushButton 作为真正的接口基类，
 *        实现 rander() 和 onClick() 接口。
 */
class PushButton : public AbstractButton
{
    protected:
        bool isClick;

    public:
        PushButton() : isClick(false) {}

        void rander() const override {
            NOTIFY_LOG("Rander PushButton.\n");
        }

        void onClick() override {
            this->isClick = true;
            CORRECT_LOG("[PushButton: Click ON]\n");
            this->isClick = false;
            CORRECT_LOG("[PushButton: Click OFF]\n");
        }
};

/**
 * @brief CheckBox 由 PushButton 派生，
 *        所以需要重写所有方法。
 */
class CheckBox : public PushButton
{
    public:
        void rander() const final {
            NOTIFY_LOG("Rander CheckBox.\n");
        }

        void onClick() final {
            this->isClick = true;
            CORRECT_LOG("[CheckBox: Click ON]\n");
            this->isClick = false;
            CORRECT_LOG("[CheckBox: Click OFF]\n");
        }
};

int main(int argc, char const *argv[])
{
    CheckBox   simpleCheckBox;
    PushButton simplePushButton;

    simplePushButton.rander();
    simplePushButton.onClick();

    simpleCheckBox.rander();
    simpleCheckBox.onClick();
    
    return EXIT_SUCCESS;
}
