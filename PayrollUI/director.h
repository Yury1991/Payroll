#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "receiver.h"


class Director : public Receiver{
public:
    //Конструктор
    Director();
    Director(QString fullName, qreal profit, ushort workingDays, ushort calendarWorkingDays,
             bool isPayFund, qreal penalty, qreal premium, qreal adjustment);
    ~Director();

    //Расчет процента от выработки
    qreal calculateSalaryPercent() override;

    //Расчет минимальной зарплаты
    qreal calculateMinSalary() override;

    //Расчет промежуточной зарплаты
    qreal calculateIntermediateSalary() override;

    //Расчет итоговой зарплаты
    qreal calculateTotalSalary() override;

    //Работа с доплатой директора
    qreal getDirectorFee();
private:
    const QString position = "Директор"; //Должность сотрудника
    const qreal directorFee = 5000;    // надбавка за директорство
    const qreal percent = 0.03;        // процент директора от общей выработки
};

#endif // DIRECTOR_H
