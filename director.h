#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "receiver.h"


class Director : public Receiver
{

public:
    //Конструктор
    Director();
    ~Director();

    //Расчет процента от выработки
    double calculateSalaryPercent() override;

    //Расчет минимальной зарплаты
     double calculateMinSalary() override;

    //Расчет итоговой зарплаты
    double calculateTotalSalary() override;

    //Работа с доплатой директора
    double getDirectorFee();
private:
    const double directorFee = 5000;    // надбавка за директорство
    const double percent = 0.03;              //процент работника от бщей выработки
    double profit = 0;                  //общая выработка предприятия
    double minSalary = 0;               //минимальный оклад/зарплата
    double salaryPercent = 0;           //процент от выработки в денежном эквиваленте
    double totalSalary = 0 ;
};

#endif // DIRECTOR_H
