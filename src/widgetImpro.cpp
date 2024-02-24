#include <iostream>

class WidgetImpro
{
    private:
        int width{640};
        int height{480};
        bool frame{false};
        bool visible{true};

        int getHeight(const int __width) { return __width * 3 / 4; }

    public:
        WidgetImpro() = default;

        explicit WidgetImpro(const int __width) noexcept : width(__width), height(getHeight(__width)) {}

        WidgetImpro(const int __width, const int __height) noexcept : width(__width), height(__height) {}

        friend std::ostream & operator<<(std::ostream & __os, const WidgetImpro & __widget)
        {
            __os << std::boolalpha << __widget.width << " * " << __widget.height
                 << ", Frame: " << __widget.frame
                 << ", Visible: " << __widget.visible;

            return __os;
        }
};

int main(int argc, char const *argv[])
{
    WidgetImpro wImproVGA;

    std::cout << wImproVGA << '\n';

    return 0;
}
