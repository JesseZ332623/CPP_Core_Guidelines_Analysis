#include "./include/employee.h"

void Programer::show(void) const
{
    //printSplitLine(35, '-');
    NOTIFY_LOG(
        "This is Programer account, ID = [" + 
        std::to_string(this->employeeID) + "]\n\n"
    );
    //printSplitLine(35, '-');
}

void Programer::registerAccount(void)
{
    this->setEmployeeID(this->generateID());
    this->show();
}

void Desinger::show(void) const
{
    //printSplitLine(35, '-');
    NOTIFY_LOG(
        "This is Desinger account, ID = [" + 
        std::to_string(this->getEmployeeID()) + "]\n\n"
    );
    //printSplitLine(35, '-');
}

void Desinger::registerAccount(void)
{
    this->setEmployeeID(this->generateID());
    this->show();
}