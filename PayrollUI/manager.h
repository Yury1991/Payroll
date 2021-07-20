#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee
{

public:
    Manager();
    ~Manager();

    qreal calculateSellProfitPercent();
    qreal calculateMinSalary() override;
    qreal calculateIntermediateSalary () override;

private:
    qreal sellProfit;
    qreal managerPercent;
    qreal managerProfit;
    qreal minSalary;


};

#endif // MANAGER_H
