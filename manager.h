#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"

class Manager : public Employee
{
public:
    Manager();


private:
    double sellProfit = 0;

};

#endif // MANAGER_H
