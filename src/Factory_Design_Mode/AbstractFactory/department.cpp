#include "./include/department.h"

std::shared_ptr<Project> DepartmentManager::createProject(void)
{
    auto project = this->department->createProject();   // 创建一个新项目对象

    this->projects.push_back(project);      // 管理员这边也要保存一份

    return project;
}

std::shared_ptr<Project> DepartmentManager::createProject(const std::string  __name)
{
    auto project = this->department->createProject(__name);   // 创建一个新项目对象

    this->projects.push_back(project);                       // 管理员这边也要保存一份

    return project;
}

std::shared_ptr<Employee> DepartmentManager::createEmployee(void)
{
    std::shared_ptr<Employee> employee = this->department->createEmployee();

    employee->registerAccount();        // 先注册获取 ID

    // 管理员这边保存一份
    this->employees[employee->getEmployeeID()] = employee;

    return employee;
}