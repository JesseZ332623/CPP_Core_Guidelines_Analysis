#include "./include/project.h"

void ITProject::assignTo(const int __employeeID)
{
    this->setEmployeeID(__employeeID);

    printSplitLine(35, '-');
    CORRECT_LOG(
        "Assing IT project:\n\t<" + this->getProjectName() + ">\n"
    );
    NOTIFY_LOG(
        "to programer\n\tID = [" + std::to_string(this->getEmployeeID()) + "]\n"
    );
    printSplitLine(35, '-');
}

void ITProject::show(void) const
{
    printSplitLine(35, '-');
    NOTIFY_LOG(
        "Project Name: " + this->getProjectName() + '\n'
    );

    if (!this->employeeID) {

        WARNING_LOG("Do not assignment any employee.\n");
    }
    else {
        NOTIFY_LOG(
            "Assigned to programer ID = [" +
            std::to_string(this->getEmployeeID()) + "]\n"
        );
    }
    printSplitLine(35, '-');
}

void UIProject::assignTo(const int __employeeID)
{
    this->setEmployeeID(__employeeID);

    printSplitLine(35, '-');
    CORRECT_LOG(
        "Assing IT project:\n\t<" + this->getProjectName() + ">\n"
    );
    NOTIFY_LOG(
        "to designer\n\tID = [" + std::to_string(this->getEmployeeID()) + "]\n"
    );
    printSplitLine(35, '-');
}

void UIProject::show(void) const
{
    printSplitLine(35, '-');
    NOTIFY_LOG(
        "Project Name: " + this->getProjectName() + '\n'
    );

    if (!this->employeeID) {

        WARNING_LOG("Do not assignment any employee.\n");
    }
    else {
        NOTIFY_LOG(
            "Assigned to designer ID = [" +
            std::to_string(this->getEmployeeID()) + "]\n"
        );
    }
    printSplitLine(35, '-');
}