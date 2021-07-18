#ifndef RECEIVER_H
#define RECEIVER_H
#include "employee.h"

class Receiver : public Employee
{
    friend class Director;
public:
    Receiver();    // Конструктор
    Receiver(QString fullName, double profit, unsigned short workingDays, unsigned short calendarWorkingDays, bool isPayFund);
    ~Receiver();    //Деструктор

    //Расчет выработки
    virtual double getProfit();
    virtual void setProfit(double profit);

    //Расчет процента от выработки
    virtual double getPercent();
    virtual double calculateSalaryPercent();

    //Расчет минимальной зарплаты/оклада
    double calculateMinSalary() override;

    //Расчет итоговой зарплаты
    double calculateTotalSalary() override;
 private:
    const string position = "Приемщик"; //Должность сотрудника
    double profit = 0;                  //Общая выработка предприятия
    const double percent = 0.015;       //Процент от выработки
    double salaryPercent = 0;           //Процент от выработки в денежном эквиваленте
};

#endif // RECEIVER_H
