#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee
{
public:
    //Конструктор:
    Manager();
    Manager(QString fullName, qreal sellProfit, ushort wDays, ushort allDays,
            bool isPayFund, bool isFourPercent, qreal penalty, qreal premium, qreal adjustment);

    ~Manager();
    //Методы доступа:
    qreal getManagerProfit();
    void setManagerProfit(qreal managerProfit);
    //Методы
    qreal calculateManagerProfit();
    qreal calculateIntermediateSalary () override;
    qreal calculateTotalSalary() override;
private:
    const QString position = " Менеджер"; //Должность сотрудника
    const qreal minSalary = 45000;
    bool isFourPercent;
    qreal sellProfit;       
    qreal managerProfit;
};

#endif // MANAGER_H
