#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "receiver.h"


class Director : public Receiver{
public:
    //Конструктор
    Director();
    Director(QString fullName, double profit, unsigned short workingDays, unsigned short calendarWorkingDays, bool isPayFund);
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
    const double percent = 0.03;        // процент директора от общей выработки
};

#endif // DIRECTOR_H
