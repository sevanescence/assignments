#include "EmployeeGroupContext.hpp"

#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

struct EmployeeIDOutOfBoundsException : public std::exception {
    char const * what() const throw () {
        return "Employee ID is out of bounds.";
    }
};

// class EmployeeGroups {
//     static EmployeeGroups *instance;
//     int *groups;
//     size_t size;

//     EmployeeGroups(size_t _size) {
//         size = _size;
//         groups = (int *) malloc(sizeof(int) * size);
//     }

//     public:
//         static EmployeeGroups *getInstance() {
//             if (! instance) instance = new EmployeeGroups(EmployeeGroupContext::GROUP_SIZE_DEFAULT);
//             return instance;
//         }

//         int *getGroups() {
//             return this->groups;
//         }
//         size_t getSize() {
//             return size;
//         }
// };

// class EmployeeGroupContext {
//     public:
//         static int const GROUP_SIZE_DEFAULT = 4;
//         EmployeeGroups *employeeGroups;
//         EmployeeGroupContext() {
//             employeeGroups = EmployeeGroups::getInstance();
//         }
// };

int ResolveEmployeeGroupByID(uint32_t id);
int ResolveEmployeeGroupsFromFile(ifstream fin, int employeesByGroup [4]);

int main() {

    // int employeesByGroup [4] = { 0, 0, 0, 0 };

    // try {

    // } catch (EmployeeIDOutOfBoundsException &e) {
    //     cout << "EmployeeIDOutOfBoundsException caught" << endl;
    //     cout << e.what() << endl;
    // }
}

int ResolveEmployeeGroupByID(uint32_t id) {
    if (id < 100 || id > 899)
        throw EmployeeIDOutOfBoundsException();
    if (id - 299 <= 0) return 1;
    if (id - 499 <= 0) return 2;
    if (id - 799 <= 0) return 3;
    /* if (id - 899 <= 0) */ return 4;
}
