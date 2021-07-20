#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <QString>
using namespace std;

class Employee
{
    friend class Receiver;
    friend class Director;
    friend class Manager;
public:
    Employee();
    Employee(QString fullName, qreal minSalary, ushort workingDays, ushort calendarWorkingDays,
             bool isPayFund, qreal penalty, qreal premium, qreal adjustment);
    ~Employee();

    //Должность сотрудника
    virtual QString getPosition();

    //ФИО соттрудникаа
    virtual QString getFullName();
    virtual void setFullName(const QString &str);

    //Расчет минимальной зарплаты/оклада
    virtual qreal getMinSalary();
    virtual void setMinSalary(qreal minSalary);
    virtual qreal calculateMinSalary();

    //Управление отработанными днями
    virtual ushort getWorkingDays();
    virtual void setWorkingDays(ushort workingDays);

    //Управление рабочими днями
    virtual ushort getCalendarWorkingDays();
    virtual void setCalendarWorkingDays(ushort workingDays);

    //Промежуточная зарплата
    virtual qreal calculateIntermediateSalary();

    //Итоговая зарплата
    virtual qreal getTotalSalary();
    virtual void setTotalSalary(qreal totalSalary);
    virtual qreal calculateTotalSalary();
private:
    const QString position = "Окладчик"; // должность сотрудника
    QString fullName;                    //ФИО соттрудникаа
    qreal minSalary;               // минимальный оклад
    ushort workingDays;                // отработанные дни
    ushort calendarWorkingDays;        // рабочие дни
    qreal intermediateSalary;       //Промежуточная зарплата(до штрафов, премий, корректировки
    qreal totalSalary;             // итоговая зарплата
    qreal penalty;          //Штрафы
    qreal premium;          //Премия
    qreal adjustment;       //Корректировка


    bool isPayFund;
};

#endif // EMPLOYEE_H
