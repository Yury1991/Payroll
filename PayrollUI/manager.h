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
    qreal calculateTotalSalary () override;

private:
    qreal sellProfit;
    const qreal managerPercent = 0.01;
    const qreal vacationPayFundPercent = 0.1;
    qreal managerProfit;
    qreal minSalary;


};

#endif // MANAGER_H
