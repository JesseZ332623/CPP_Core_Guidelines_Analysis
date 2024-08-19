#include <MyLib/myLogerDef.h>

#include <stdexcept>

using namespace MyLib::MyLoger;

/**
 * @brief 工厂模式学习之简单工厂，需求如下：
 *        目前公司扩张，增加了设计师职位，所以需要更新管理系统，
 *        使用简单工厂设计模式完成建模。                   
*/

/**
 * @brief 该枚举类型用于标记不同的员工职位。 
*/
enum EmployeeType {
    PROGRAMER = 0, DESIGNER
};

/**
 * @brief 员工父类，设计师 和 程序员类均继承于它，
 *        可以借助多态，创建不同的子类。
*/
struct Employee {

    virtual void show(void) const = 0;
    virtual ~Employee() {}
};

/**
 * @brief 程序员类
*/
struct Programer : public Employee
{
    Programer(void) { 
        CORRECT_LOG("Create a porgramer object complete.\n");
    }

    void show(void) const override { WARNING_LOG("Hi! I am a [Programer].\n"); }
};

/**
 * @brief 设计师类
*/
struct Designer : public Employee
{
    Designer(void) {
        CORRECT_LOG("Create a designer object complete.\n");
    }

    void show(void) const override { WARNING_LOG("Hi! I am a [Designer].\n"); }
};

/**
 * @brief 部门类，负责各个职员类的创建
*/
struct Department
{
    /**
     * @brief 根据传入的员工类型来创建不同的员工。
    */
    Employee * createEmployee(EmployeeType __type)
    {
        switch (__type)
        {
            case PROGRAMER:

                NOTIFY_LOG("Department class create a porgramer object.\n");
                return new Programer();
                break;

            case DESIGNER:

                NOTIFY_LOG("Department class create a designer object.\n");
                return new Designer();
                break;

            // 如果创建未知类型的员工直接甩异常。
            default:
                throw std::invalid_argument("Department::createEmployee(__type): Unkown type.\n");
        }
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    Department compnanyDepartment;

    Employee * programerA = compnanyDepartment.createEmployee(EmployeeType::PROGRAMER);
    Employee * designerA  = compnanyDepartment.createEmployee(EmployeeType::DESIGNER);
    Employee * _xxx_ = nullptr;

    programerA->show();
    designerA->show();

    try
    {
        _xxx_ = compnanyDepartment.createEmployee((EmployeeType)3);
    }
    catch (const std::invalid_argument & __invalidArg)
    {
        ERROR_LOG(__invalidArg.what());
        delete _xxx_;
    }
    delete programerA;
    delete designerA;

    return EXIT_SUCCESS;
}
