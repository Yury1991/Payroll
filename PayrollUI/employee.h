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
    Employee(QString fullName, double minSalary, unsigned short workingDays, unsigned short calendarWorkingDays, bool isPayFund);
    ~Employee();

    //Должность сотрудника
    virtual QString getPosition();

    //ФИО соттрудникаа
    virtual QString getFullName();
    virtual void setFullName(const QString &str);

    //Расчет минимальной зарплаты/оклада
    virtual double getMinSalary();
    virtual void setMinSalary(double minSalary);
    virtual double calculateMinSalary();

    //Управление отработанными днями
    virtual unsigned short getWorkingDays();
    virtual void setWorkingDays(int workingDays);

    //Управление рабочими днями
    virtual unsigned short getCalendarWorkingDays();
    virtual void setCalendarWorkingDays(unsigned short workingDays);

    //Итоговая зарплата
    virtual double getTotalSalary();
    virtual void setTotalSalary( double totalSalary);
    virtual double calculateTotalSalary();
private:
    const QString position = "Окладчик"; // должность сотрудника
    QString fullName;                    //ФИО соттрудникаа
    double minSalary;               // минимальный оклад
    unsigned short workingDays;                // отработанные дни
    unsigned short calendarWorkingDays;        // рабочие дни
    double totalSalary = 0;             // итоговая зарплата
    bool isPayFund;
};

#endif // EMPLOYEE_H
