// ownerShipSemantic.cpp

#include <iostream>
#include <memory>
#include <utility>

/**
 * 设计一个简单的类，在析构的时候会输出这个类的信息。
*/
class MyString
{
    private:
        std::string myString;

    public:
        explicit MyString(std::string & __s) : myString(__s) {}

        ~MyString()  { printf("destroy object: %s\n", myString.c_str()); }
};

/*传值*/
void functionCopy(MyString __myString) {}

/*传指针*/
void functionPointer(MyString * __myString) {}

/*传引用*/
void functionReference(MyString & __myString) {}

/*通过 std::unique_ptr 传递*/
void functionUniquePointer(std::unique_ptr<MyString> __myStringUniquePtr) {}

/*通过 std::shared_ptr 传递*/
void functionSharedPointer(std::shared_ptr<MyString> __myStringSharedPtr) 
{ 
    printf("There are currently [%ld] shared_ptrs pointing to this piece of memory\n", __myStringSharedPtr.use_count()); 
}

int main(int argc, char const *argv[])
{
    puts("Program Begin: ");

    std::string smallyA = "114514";
    std::string smallyB = "1919810";
    std::string smallyC = "Fuck You!";

    /*
        初始化列表初始化（C++11）
        myString 在 main 中被声明，它会在 main 函数结束后被析构。
    */
    MyString myString{smallyA};
    
    /*myStringPointer 拿到 myString 的地址*/
    MyString *myStringPointer = &myString;

    /*myStringReference 与 myString 绑定*/
    MyString &myStringReference = myString;

    /*创建一个对象由唯一指针 myStringUniquePtr 动态管理*/
    auto myStringUniquePtr = std::make_unique<MyString>(smallyB);

    /*创建一个对象由分享指针 myStringSharedPtr 动态管理*/
    auto myStringSharedPtr = std::make_shared<MyString>(smallyC);

    /*
        按值传递，调用该函数会将 myString 拷贝给 __myString，
        __myString 的声明周期仅限这个函数，因此会在调用结束后输出 destroy object: 114514
    */
    functionCopy(myString);

    /*
        按指针传递，仅仅传递了 myString 对象的地址，不涉及拷贝或移动。
        所以这个函数无权销毁指向的对象，故不会输出信息。
    */
    functionPointer(myStringPointer);

    /*
        按引用传递，和传指针类似，也只是借用了资源，不涉及拷贝或移动。
        所以这个函数无权销毁所绑定的对象，故不会输出信息。
    */
    functionReference(myStringReference);

    /*
        使用 std::move 转移 myStringUniquePtr 的所有权给 __myStringUniquePtr
        而 __myStringUniquePtr 的生命周期仅限这个函数，因此会在调用结束后输出 destroy object: 1919810
    */
    functionUniquePointer(std::move(myStringUniquePtr));

    /*
        将 myStringSharedPtr 的拷贝传递给 __myStringSharedPtr，涉及到了构建，
        但是由于 shared_ptr 的特性，此时一共有 2 个 分享指针指向了同一片内存，算是给这片内存 "续命" 了。
        函数调用后输出：There are currently [2] shared_ptrs pointing to this piece of memory
    */
    functionSharedPointer(myStringSharedPtr);


    puts("Program End: ");
    return EXIT_SUCCESS;
}

/*
    在 main 函数结束后 myStringSharedPtr 和 myString 的声明周期才算彻底结束，故调用析构函数输出：
    destroy object: Fuck You!
    destroy object: 114514
*/
