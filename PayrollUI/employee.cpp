#include "employee.h"

Employee::Employee()
{
    minSalary = 0;       // минимальный оклад
    workingDays = 0;            // отработанные дни
    calendarWorkingDays = 0;    // календарные рабочие дни
    totalSalary = 0;             // итоговая зарплата
}

int Employee::getWorkingDays(){
    return workingDays;
}
void Employee::setWorkingDays(int workingDays){
    this->workingDays = workingDays;
}

int Employee::getCalendarWorkingDays(){
    return calendarWorkingDays;
}
void Employee::setCalendarWorkingDays(int calendarWorkingDays){
    this->calendarWorkingDays = calendarWorkingDays;
}

double Employee::getMinSalary(){
    return minSalary;
}
void Employee::setMinSalary(double minSalary){
    this->minSalary = minSalary;
}
double Employee::calculateMinSalary(){
         return minSalary;

}
double Employee::getTotalSalary(){
    return totalSalary;
}
void Employee::setTotalSalary( double totalSalary){
    this->totalSalary = totalSalary;
}
double Employee::calculateTotalSalary(){
    if(workingDays == calendarWorkingDays){
        totalSalary = minSalary;
        return totalSalary;
    }
    else{
        totalSalary = (minSalary * workingDays)/calendarWorkingDays;
         return totalSalary;
    }
}

Employee:: ~Employee(){

}
