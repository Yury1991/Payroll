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

bool Employee::getIsMissed(){
    return isMissed;
}
void Employee::setIsMissed(bool isMissed){
    this->isMissed = isMissed;
}

double Employee::getMinSalary(){
    return minSalary;
}
void Employee::setMinSalary(double minSalary){
    this->minSalary = minSalary;
}
double Employee::calculateMinSalary(){
    if(isMissed == false){
        return minSalary;
    }
    else{
        minSalary = (minSalary * workingDays)/calendarWorkingDays;
         return minSalary;
    }

}

double Employee::calculateTotalSalary(){
    totalSalary = minSalary;
    return totalSalary;
}
