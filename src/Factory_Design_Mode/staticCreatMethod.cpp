#include <MyLib/myLogerDef.h>

using namespace MyLib::MyLoger;

/**
 * @brief 工厂模式学习前置任务之：静态创建方法：
 *        需求：假设需要设计一个员工管理系统，
 *             目前是创业初期，部门内只有程序员一个职位，
 *             使用静态创建方法对该需求进行建模。
*/

/**
 * @brief 程序员类
*/
struct Programer 
{
    Programer(void) { 
        CORRECT_LOG("Create a porgramer object complete.\n"); 
    }
};

/**
 * @brief 部门类，负责各个职员类的创建
*/
struct Department
{
    /**
     * @brief Create a Programer object。
    */
    static Programer * createProgramer(void) 
    {
        NOTIFY_LOG("Department class create a porgramer object.\n");
        return new Programer();
    }
};

int main(int argc, char const *argv[])
{
    Programer * newProgamer = Department::createProgramer();

    delete newProgamer;

    return EXIT_SUCCESS;
}
