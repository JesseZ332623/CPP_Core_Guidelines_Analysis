#ifndef __PROJECT_H_
#define __PROJECT_H_

#include "defs.h"

using namespace MyLib::MyLoger;

struct Project {

    protected:
        std::string projectName;
        int         employeeID;

    public:
        Project() : projectName(), employeeID(0) {}
        Project(const std::string & __proName) : projectName(__proName), employeeID(0) {}

        void      setEmployeeID(const int __ID)               { this->employeeID =  __ID; }
        void      setProjectName(const std::string __newName) { this->projectName = __newName; }
        const int getEmployeeID(void) const                   { return this->employeeID; }

        const std::string & getProjectName(void) const { return this->projectName; }

        /**
         * @brief 将本项目分配给 ID 为 __employeeID 的员工去做。
         * 
         * @param __employeeID  员工 ID
        */
        virtual void assignTo(const int) = 0;

        /**
         * @brief 显示项目信息，格式为：“什么项目，交给谁干的。”
        */
        virtual void show(void) const = 0;
        
        virtual ~Project() {}
};

struct ITProject : public Project {

    ITProject() : Project() {}
    ITProject(const std::string & __proName) : Project(__proName) {}

    void assignTo(const int __employeeID) override;

    void show(void) const override;
};

struct UIProject : public Project {

    UIProject() : Project() {}
    UIProject(const std::string &__proName) : Project(__proName) {}

    void assignTo(const int __employeeID) override;

    void show(void) const override;
};

#endif // __PROJECT_H_