#include "employee.h"

Employee::Employee()
{
    fullName = "Без имени";
    minSalary = 0;       // минимальный оклад
    workingDays = 0;            // отработанные дни
    calendarWorkingDays = 0;    // календарные рабочие дни
    totalSalary = 0;             // итоговая зарплата
    isPayFund = false;
}

Employee::Employee(QString fullName, double minSalary, unsigned short workingDays, unsigned short calendarWorkingDays, bool isPayFund){
    this->fullName = fullName;
    this->minSalary = minSalary;
    this->workingDays = workingDays;
    this->calendarWorkingDays = calendarWorkingDays;
    this->isPayFund = isPayFund;
}

QString Employee::getPosition(){
    return position;
}
QString Employee::getFullName(){
    return fullName;
}

void  Employee::setFullName(const QString &str){
    fullName = str;
}

unsigned short Employee::getWorkingDays(){
    return workingDays;
}
void Employee::setWorkingDays(int workingDays){
    this->workingDays = workingDays;
}

unsigned short Employee::getCalendarWorkingDays(){
    return calendarWorkingDays;
}
void Employee::setCalendarWorkingDays(unsigned short calendarWorkingDays){
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
    }
    else{
        totalSalary = (minSalary * workingDays)/calendarWorkingDays;        
    }
    if(isPayFund == true){
        totalSalary -=  totalSalary* 0.1 ;
        return totalSalary;
    }
    else{
        return totalSalary;
    }
}

Employee:: ~Employee(){

}
