#include "./include/department.h"

int main(int argc, char const *argv[])
{
    system("cls");

    UIDepartment uiDepart;
    ITDepartment itDepart; 

    DepartmentManager departManager {&uiDepart};

    auto designerA = departManager.createEmployee();
    auto designerB = departManager.createEmployee();

    auto projectA  = departManager.createProject("Web page UI 2024.3.1");
    projectA->assignTo(designerA->getEmployeeID());

    departManager.changeDepartment(&itDepart);   // 切换生产线

    auto programerA = departManager.createEmployee();
    auto projectB   = departManager.createProject("Web page H5 Code");
    projectB->assignTo(programerA->getEmployeeID());

    projectA->show();
    projectB->show();

    return EXIT_SUCCESS;
}
