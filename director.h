#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "receiver.h"


class Director : public Receiver
{

public:
    Director();




    //Расчет выработки
    double getProfit();
    void setProfit(double profit);


    //Управление отработанными днями
    int getWorkingDays();
    void setWorkingDays(int workingDays);

    //Управление календарными рабочими днями
    int getCalendarWorkingDays();
    void setCalendarWorkingDays(int workingDays);

    //Расчет процента от выработки
    double getPercent();
    void setPercent(double percent);
    double calculateSalaryPercent();

    //Расчет минимальной зарплаты
    double getMinSalary();
    void setMinSalary(double minSalary);
    double calculateMinSalary();

    //Расчет итоговой зарплаты
    double calculateTotalSalary();

    //Работа с доплатой директора
    double getDirectorFee();


    //Флаг отсутствия
    bool getIsMissed();
    void setIsMissed(bool isIll);

private:
    double percent = 0.03;              //процент работника от бщей выработки
    double profit = 0;                  //общая выработка предприятия
    double minSalary = 0;               //минимальный оклад/зарплата
    double salaryPercent = 0;           //процент от выработки в денежном эквиваленте
    bool isMissed = false;              //отсутствие


    const double directorFee = 5000;    // надбавка за директорство
    int workingDays = 0;                //  отработанные дни
    int calendarWorkingDays = 0;        // календарные рабочие дни


};

#endif // DIRECTOR_H
