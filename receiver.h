#ifndef RECEIVER_H
#define RECEIVER_H
#include "employee.h"

class Receiver : public Employee
{

public:
    Receiver();    // Конструктор
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
    double profit = 0;          //общая выработка предприятия
    const double percent = 0.015;     // процент от выработки
    double salaryPercent = 0;   // процент от выработки в денежном эквиваленте
    double totalSalary = 0;

};

#endif // RECEIVER_H
