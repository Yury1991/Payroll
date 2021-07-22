#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee
{
public:
    Manager();
    Manager(QString fullName, qreal sellProfit, ushort wDays, ushort allDays, bool isPayFund, qreal penalty, qreal premium, qreal adjustment);
    ~Manager( );
    qreal getManagerProfit();
    //Методы
    qreal calculateManagerProfit();
    qreal calculateIntermediateSalary () override;
    qreal calculateTotalSalary() override;
private:
    const qreal minSalary = 45000;
    qreal sellProfit;   
    bool isFourPercent;
    qreal managerProfit;   
    qreal totalSalary;
};

#endif // MANAGER_H
