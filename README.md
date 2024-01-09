# CPP_Guidelines_Analysis 学习笔记

## 3.2 运用依赖注入化解

一个很简单的日志器切换，可以这么实现：

```C++
#include <chrono>
#include <iostream>
#include <memory>

/*
    这个程序演示了如何使用依赖注入替换一个日志记录器，他的类关系如下：

    抽象基类 Logger 公共派生出 SimpleLogger 类 和 TimeLogger 类
    前者单纯的输出一条日志，后者在输出时需要带上时间信息。
*/

class Logger
{
    public:
        /**
         * @brief 向终端，或某个文件输出一条日志信息。
         * 
         * @param __mess 传入的日志信息
         * 
         * @return non-return
        */
        virtual void write(const std::string & __mess) = 0;            // 纯虚函数
        virtual ~Logger() = default;
};

class SimpleLogger : public Logger
{
    private:
        /**
         * @brief 向终端，或某个文件输出一条日志信息。（重载于 Logger 类方法）
         * 
         * @param __mess 传入的日志信息
         * 
         * @return non-return
        */
        void write(const std::string & __mess) override
        {
            std::cout << __mess << std::endl;
        }
};

class TimeLogger : public Logger
{
    private:

        /*
            自定义持续时间类型 MySecondTick
            是 std::chrono::duration<long double> 类型
        */
        using MySecondTick = std::chrono::duration<long double>;

        /**
         * @brief 获取当前时间距离 UNIX 纪元的时间差。
         * 
         * @return 当前时间距离 UNIX 纪元的时间差
        */
        long double timeSinceEpoch()
        {
            /*获取当前系统时间点*/
            auto timeNow = std::chrono::system_clock::now();

            /*
                获取当前时间距离 UNIX 纪元的 
                std::chrono::_V2::system_clock::duration 对象。
            */
            auto duration = timeNow.time_since_epoch();

            /*
                将该对象转换成 long double 类型
            */
            MySecondTick second(duration);

            /*返回秒数*/
            return second.count();
        }

        std::string currentTime()
        {
            /*获取当前系统时间点*/
            const auto timeNow = std::chrono::system_clock::now();
            
            /*将当前时间转换成 time_t 类型，一个有符号的长长整型*/
            const std::time_t currentTime = std::chrono::system_clock::to_time_t(timeNow);

            /*最后将这个 time_t 类型转换成当前系统时间的字符串，并传给 std::string 去构建并返回（移动而非拷贝）*/
            return std::string(std::ctime(&currentTime));
        }

        void write(const std::string & __mess) override
        {
            /*强制使用定点表示法*/
            std::cout << std::fixed;

            /*输出带时间信息的日志信息*/
            std::cout << "Time since epoch: " << timeSinceEpoch() << ": " << __mess << '\n';
            std::cout << "Current system time: " << currentTime() << std::endl;
        }
};

class Client
{
    private:
        /*一个指向了 Logger 类的分享指针*/
        std::shared_ptr<Logger> logger;

    public:
        /*构建函数初始化 logger 指针*/
        Client(std::shared_ptr<Logger> log) : logger(log) {}

        /*输出日志*/
        void doSomeThing() { logger->write("Message"); }

        /*
            改变 Logger 的类型，
            所有日志类都由 Logger 抽象类派生而来，可以随意切换
        */
        void setLogger(std::shared_ptr<Logger> log) { logger = log; }
};
```

由代码可见，所有的日志器类均派生自抽象类 Logger，因此可以很安全的进行类型转换（即抽象父类转换成子类）。
这样就可以在使用中随意切换日志的类型，如下面代码所示：

```C++
int main(int argc, char const *argv[])
{
    std::cout << std::endl;

    /*使用 make_shared 而不是 new 实例化，更安全*/
    Client clineA(std::make_shared<SimpleLogger>());
    /*普通日志，只能单纯的输出一条日志*/
    clineA.doSomeThing();

    /*切换成带时间的日志*/
    clineA.setLogger(std::make_shared<TimeLogger>());
    clineA.doSomeThing();
    clineA.doSomeThing();

    std::putchar('\n');
    
    return EXIT_SUCCESS;
}
```
