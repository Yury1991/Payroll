#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
public:
    Employee();
    ~Employee();

    //Расчет минимальной зарплаты/оклада
    virtual double getMinSalary();
    virtual void setMinSalary(double minSalary);
    virtual double calculateMinSalary();

    //Управление отработанными днями
    virtual int getWorkingDays();
    virtual void setWorkingDays(int workingDays);

    //Управление календарными рабочими днями
    virtual int getCalendarWorkingDays();
    virtual void setCalendarWorkingDays(int workingDays);

    //Итоговая зарплата
    virtual double getTotalSalary();
    virtual void setTotalSalary( double totalSalary);
    virtual double calculateTotalSalary();
private:
    double minSalary = 0;       // минимальный оклад
    int workingDays = 0;            // отработанные дни
    int calendarWorkingDays = 0;    // календарные рабочие дни
    double totalSalary = 0;             // итоговая зарплата

};

#endif // EMPLOYEE_H
