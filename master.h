#ifndef MASTER_H
#define MASTER_H
#include "employee.h"

class Master : public Employee
{
public:
    Master();
    // оплата выработки
    double getMasterProfit();
    void setMasterProfit(double masterProfit);

    //Имеется ли премия
    bool getIsPremium();
    void setIsPremium(bool isPremium);

    //Управление отработанными днями
    int getWorkingDays();
    void setWorkingDays(int workingDays);

    //Управление календарными рабочими днями
    int getCalendarWorkingDays();
    void setCalendarWorkingDays(int workingDays);

    //Расчет премии
    double getPremium();
    void setPremium(double premium);
    double calculatePremium();

    //Итоговая зарплата
    double calculateTotalSalary();

private:
    double masterProfit;
    bool isPremium = false;
    double premium = 0;
    int workingDays;
    int calendarWorkingDays;
    bool isMissed = false;
};

#endif // MASTER_H
