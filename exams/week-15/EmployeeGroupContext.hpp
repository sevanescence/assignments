#ifndef EMPLOYEE_GROUP_CONTEXT_H
#define EMPLOYEE_GROUP_CONTEXT_H

#include "EmployeeGroups.hpp"

class EmployeeGroupContext {
    public:
        static int const GROUP_SIZE_DEFAULT = 4;
        EmployeeGroups *employeeGroups;
        EmployeeGroupContext();
};

#endif
