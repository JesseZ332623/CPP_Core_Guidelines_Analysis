#ifndef __DEPARTMENT_H_
#define __DEPARTMENT_H_

#include "./defs.h"
#include "./employee.h"
#include "./project.h"

#include <memory>
#include <vector>
#include <unordered_map>

/**
 * @brief 部门抽象基类。
*/
struct Department
{   
    /**
     * @brief Create a Employee object
    */
    virtual std::shared_ptr<Employee> createEmployee() const = 0;

    /**
     * @brief Create a Project object
    */
    virtual std::shared_ptr<Project> createProject()  const = 0;
    virtual std::shared_ptr<Project> createProject(const std::string  __name) const = 0;

    virtual ~Department() {}
};

/**
 * @brief IT 部门类 
*/
struct ITDepartment : public Department
{
    std::shared_ptr<Employee> createEmployee() const override {

        return std::make_shared<Programer>();
    }

    std::shared_ptr<Project> createProject()  const override {

        return std::make_shared<ITProject>();
    }

    std::shared_ptr<Project> createProject(const std::string  __name) const {

        auto newProject = std::make_shared<ITProject>();

        newProject->setProjectName(__name);

        return newProject;
    }
};

/**
 * @brief UI 部门类
*/
struct UIDepartment : public Department
{
    std::shared_ptr<Employee> createEmployee() const override {

        return std::make_shared<Desinger>();
    }

    std::shared_ptr<Project> createProject()  const override {

        return std::make_shared<UIProject>();
    }

    std::shared_ptr<Project> createProject(const std::string __name) const {

        auto newProject = std::make_shared<UIProject>();

        newProject->setProjectName(__name);

        return newProject;
    }
};

struct DepartmentManager
{
    private:
        Department * department;
        std::vector<std::shared_ptr<Project>> projects;
        std::unordered_map<int, std::shared_ptr<Employee>> employees;
    
    public:
        explicit DepartmentManager(Department * __department) : 
        department(__department), projects(), employees() {}

        void changeDepartment(Department * __department) {
            this->department = __department;
        }

        std::shared_ptr<Project>  createProject(void);
        std::shared_ptr<Project>  createProject(const std::string __name);

        std::shared_ptr<Employee> createEmployee(void);
};

#endif // __DEPARTMENT_H_