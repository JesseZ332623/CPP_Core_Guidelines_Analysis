#include <MyLib/myLogerDef.h>

#include <random>

#ifndef ADDITIONAL

#define ADDITIONAL true

#endif // ADDITIONAL

using namespace MyLib::MyLoger;

/**
 * @brief 工厂模式学习之工厂方法模式，需求如下：
 *        公司的职员类型不变，但没创建一个员工，都要为他/她分配 ID
 *        更改以前的简单工厂模式，使用工厂方法模式实现建模。                 
*/

/**
 * @brief 员工抽象基类，设计师 和 程序员类均继承于它，
 *        Department 类可以借助多态，创建不同的子类。
*/
struct Employee {

    public:
        int employeeID;
        std::random_device randDevice;
        std::uniform_int_distribution<int> dist;

        Employee(void) : employeeID(0), dist(0, 114514) {}

        /**
         * @brief 生成员工 ID。
        */
        virtual void  registerAccount(void) = 0;

        /**
         * @brief 显示员工属性。
        */
        virtual void show(void) const = 0;

        virtual ~Employee() {}
};

/**
 * @brief 程序员类，继承自 Employee。
*/
struct Programer : public Employee
{
    void show(void) const override {
        NOTIFY_LOG(
            "Programer account, ID = [" + 
            std::to_string(this->employeeID) + "]\n"
        );
    }

    void registerAccount(void) override {
        this->employeeID = this->dist(this->randDevice);
        this->show();
    }
};

/**
 * @brief 设计师类，继承自 Employee。
*/
struct Desinger : public Employee
{
    void show(void) const override {
        NOTIFY_LOG(
            "Desinger  account, ID = [" + 
            std::to_string(this->employeeID) + "]\n"
        );
    }

    void registerAccount(void) override {
        this->employeeID = this->dist(this->randDevice);
        this->show();
    }
};

#if ADDITIONAL
struct Guard : public Employee
{
    void show(void) const override {
        NOTIFY_LOG(
            "Guard\t  account, ID = [" + 
            std::to_string(this->employeeID) + "]\n"
        );
    }

    void registerAccount(void) override {
        this->employeeID = this->dist(this->randDevice);
        this->show();
    }
};
#endif

/**
 * @brief 部门抽象基类，负责不同部门，不同职位员工的创建。
*/
struct Department
{
    virtual Employee * createEmployee() const = 0;

    /**
     * @brief 创建一个员工并为他分配一个 ID
    */
    Employee * onboard() const {
        Employee * employee = this->createEmployee();
        employee->registerAccount();

        return employee;
    }

    virtual ~Department() {}
};

/**
 * @brief IT 部门类，继承自 Department
*/
struct ITDepartment : public Department
{
    Employee * createEmployee() const override {

        return new Programer();
    }
};

/**
 * @brief UI 部门，继承自 Department
*/
struct UIDepartment : public Department
{
    Employee * createEmployee() const override {

        return new Desinger();
    }
};

#if ADDITIONAL
struct SecurityDepartment : public Department
{
    Employee * createEmployee() const override {

        return new Guard();
    }
};
#endif

int main(int argc, char const *argv[])
{
    system("cls");

    ITDepartment        itDepartment {};
    UIDepartment        uiDepartment {};

    Employee * programerA = itDepartment.onboard();
    Employee * desingerA  = uiDepartment.onboard();

#if ADDITIONAL
    SecurityDepartment  securityDepartment {};
    Employee * guardA = securityDepartment.onboard();
    delete guardA;
#endif

    delete programerA;
    delete desingerA;

    return EXIT_SUCCESS;
}
