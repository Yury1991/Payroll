#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee
{

public:
    Manager();
    Manager(QString fullName, qreal sellProfit, ushort workingDays, ushort calendarWorkingDays, qreal managerPercent,
            bool isPayFund, qreal penalty, qreal premium, qreal adjustment);
    ~Manager( );

    //Методы
    qreal calculateSellProfitPercent();   
    qreal calculateIntermediateSalary () override;

private:
    const qreal minSalary = 45000;
    qreal sellProfit;
    qreal managerPercent;
    qreal managerProfit;   
    qreal totalSalary;


};

#endif // MANAGER_H
