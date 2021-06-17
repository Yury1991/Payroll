#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
public:
    Employee();


    //Расчет минимальной зарплаты/оклада
    double getMinSalary();
    void setMinSalary(double minSalary);
    double calculateMinSalary();

    //Управление отработанными днями
    int getWorkingDays();
    void setWorkingDays(int workingDays);

    //Управление календарными рабочими днями
    int getCalendarWorkingDays();
    void setCalendarWorkingDays(int workingDays);

    //Отсутствие работника
    bool getIsMissed();
    void setIsMissed(bool isMissed);


    //Итоговая зарплата

    double calculateTotalSalary();


    double totalSalary; // итоговая зарплата

private:
    double minSalary = 10000;           //минимальный оклад

    int workingDays = 0;                //  отработанные дни
    int calendarWorkingDays = 0;        // календарные рабочие дни
    bool isMissed = false;              // отсутствие

};

#endif // EMPLOYEE_H
