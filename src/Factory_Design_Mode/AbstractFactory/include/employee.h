#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "./defs.h"

#include <random>

using namespace MyLib::MyLoger;

struct Employee {

    protected:
        std::random_device                  randDevice;
        std::uniform_int_distribution<int>  dist;
        int employeeID;

        int generateID(void) { return this->dist(this->randDevice); }
    
    public:
        /**
         * @brief Construct a new Employee object
        */
        Employee(void) : employeeID(0), randDevice(), dist(114514, 1919810) {}

        void      setEmployeeID(const int __ID) { this->employeeID = __ID; }
        const int getEmployeeID(void) const     { return this->employeeID; }

        /**
         * @brief 生成员工 ID 为员工进行注册。
        */
        virtual void  registerAccount(void) = 0;

        /**
         * @brief 显示员工属性。
        */
        virtual void  show(void) const = 0;

        virtual ~Employee() {}
};

struct Programer : public Employee
{
    Programer(void) : Employee() {}

    void show(void) const override;

    void registerAccount(void) override;
};

struct Desinger : public Employee
{
    Desinger(void) : Employee() {}

    void show(void) const override;

    void registerAccount(void) override;
};

#endif // _EMPLOYEE_H_