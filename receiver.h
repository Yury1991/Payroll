#ifndef RECEIVER_H
#define RECEIVER_H
#include "employee.h"

class Receiver : public Employee
{

public:
    Receiver();    // Конструктор

    //Расчет выработки
    double getProfit();
    void setProfit(double profit);

    //Расчет процента от выработки
    double getPercent();
    void setPercent(double percent);
    double calculateSalaryPercent();

    //Управление отработанными днями
    int getWorkingDays();
    void setWorkingDays(int workingDays);

    //Управление календарными рабочими днями
    int getCalendarWorkingDays();
    void setCalendarWorkingDays(int workingDays);

    //Расчет минимальной зарплаты/оклада
    double getMinSalary();
    void setMinSalary(double minSalary);
    double calculateMinSalary();


    //Расчет итоговой зарплаты
    double calculateTotalSalary();

 private:
    double profit = 0;          //общая выработка предприятия
    double percent = 0.015;     // процент от выработки

    double minSalary = 0;       // минимальный оклад
    double salaryPercent = 0;   // процент от выработки в денежном эквиваленте
    int workingDays = 0;                //  отработанные дни
    int calendarWorkingDays = 0;        // календарные рабочие дни

};

#endif // RECEIVER_H
