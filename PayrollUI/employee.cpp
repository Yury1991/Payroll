#include "employee.h"

Employee::Employee()
{
    fullName = "Без имени";
    minSalary = 0;       // минимальный оклад
    wDays = 0;            // отработанные дни
    allDays = 0;    // календарные рабочие дни
    totalSalary = 0;             // итоговая зарплата
    isPayFund = false;
}

Employee::Employee(QString fullName, qreal minSalary, ushort workingDays, ushort calendarWorkingDays,
                   bool isPayFund, qreal penalty, qreal premium, qreal adjustment){
    this->fullName = fullName;
    this->minSalary = minSalary;
    this->wDays = workingDays;
    this->allDays = calendarWorkingDays;
    this->isPayFund = isPayFund;
    this->penalty = penalty;
    this->premium = premium;
    this->adjustment = adjustment;
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

ushort Employee::getWorkingDays(){
    return wDays;
}
void Employee::setWorkingDays(ushort workingDays){
    this->wDays = workingDays;
}

ushort Employee::getCalendarWorkingDays(){
    return allDays;
}
void Employee::setCalendarWorkingDays(ushort calendarWorkingDays){
    this->allDays = calendarWorkingDays;
}

qreal Employee::getMinSalary(){
    return minSalary;
}
void Employee::setMinSalary(qreal minSalary){
    this->minSalary = minSalary;
}

qreal Employee::getTotalSalary(){
    return totalSalary;
}
void Employee::setTotalSalary(qreal totalSalary){
    this->totalSalary = totalSalary;
}
qreal Employee::calculateIntermediateSalary(){
    if(wDays == allDays){
        intermediateSalary = minSalary;
    }
    else{
        intermediateSalary = (minSalary * wDays)/allDays;
    }
    if(isPayFund == true){
        intermediateSalary -=  intermediateSalary* 0.1 ;
        return intermediateSalary;
    }
    else{
        return intermediateSalary;
    }
}

qreal Employee::calculateTotalSalary(){
    totalSalary = (intermediateSalary - penalty + premium + adjustment);
    return totalSalary;
}

Employee:: ~Employee(){

}
