#ifndef RECEIVER_H
#define RECEIVER_H
#include "employee.h"

class Receiver : public Employee
{
    friend class Director;
public:
    Receiver();    // Конструктор
    Receiver(QString fullName, qreal profit, ushort workingDays, ushort calendarWorkingDays,
             bool isPayFund, qreal penalty, qreal premium, qreal adjustment);
    ~Receiver();    //Деструктор

    //Расчет выработки
    virtual qreal getProfit();
    virtual void setProfit(qreal profit);

    //Расчет процента от выработки
    virtual qreal getPercent();
    virtual qreal calculateSalaryPercent();   
    virtual qreal calculateMinSalary();
    //Расчет промежуточный зарплаты
    qreal calculateIntermediateSalary() override;

    //Расчет итоговой зарплаты
    qreal calculateTotalSalary() override;
 private:
    const QString position = "Приемщик"; //Должность сотрудника
    qreal profit;                  //Общая выработка предприятия
    const qreal percent = 0.01;       //Процент от выработки
    qreal salaryPercent;           //Процент от выработки в денежном эквиваленте
};

#endif // RECEIVER_H
