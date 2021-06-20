#include "employee.h"

Employee::Employee()
{
    minSalary = 45000;
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
    if(workingDays == calendarWorkingDays){
        return minSalary;
    }
    else{
        minSalary = (minSalary * workingDays)/calendarWorkingDays;
         return minSalary;
    }
}
double Employee::getTotalSalary(){
    return totalSalary;
}
void Employee::setTotalSalary( double totalSalary){
    this->totalSalary = totalSalary;
}
double Employee::calculateTotalSalary(){
    totalSalary = minSalary;
    return totalSalary;
}

Employee:: ~Employee(){

}
