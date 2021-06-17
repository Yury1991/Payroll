#include "director.h"
#include "receiver.h"


Director::Director()
{
    Director::setPercent(0.03);
    Director::setMinSalary(15000);

}
//Расчет выработки
double Director::getProfit(){
    return profit;
}
void Director::setProfit(double profit){
    this->profit = profit;
}
//Управление отработанными днями
int Director::getWorkingDays(){
    return workingDays;
}
void Director::setWorkingDays(int workingDays){
    this->workingDays = workingDays;
}

//Управление календарными рабочими днями
int Director::getCalendarWorkingDays(){
    return calendarWorkingDays;
}
void Director::setCalendarWorkingDays(int calendarWorkingDays){
    this->calendarWorkingDays = calendarWorkingDays;
}
//Расчет процента от выработки
double Director::getPercent(){
    return percent;
}
void Director::setPercent(double percent){
    this->percent = percent;
}

double Director::calculateSalaryPercent(){
    salaryPercent = profit * 0.03;
    if(workingDays ==calendarWorkingDays){
        return salaryPercent;
    }
    else{
        salaryPercent = (salaryPercent*workingDays)/calendarWorkingDays;
        return salaryPercent;
    }

}
double Director::getDirectorFee(){
    return directorFee;
}


bool Director::getIsMissed(){
    return isMissed;
}
void Director::setIsMissed(bool isMissed){
    this->isMissed = isMissed;
}

double Director::calculateTotalSalary(){
    return salaryPercent + directorFee + minSalary;
}

void Director::setMinSalary(double minSalary){
    this->minSalary = minSalary;
}

double Director::calculateMinSalary(){
    if(workingDays == calendarWorkingDays){
        return minSalary = 15000;
    }
    else{
        return minSalary = (minSalary * workingDays)/calendarWorkingDays;
    }
}


