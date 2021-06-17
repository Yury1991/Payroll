#include "receiver.h"

Receiver::Receiver()
{
    percent = 0.015;
}
double Receiver::getProfit(){
    return profit;
}
void Receiver::setProfit(double profit){
   this->profit = profit;
}

double Receiver::getPercent(){
    return percent;
}

void Receiver::setPercent(double percent){
    this->percent = percent;
}
double Receiver::calculateSalaryPercent(){

    salaryPercent = profit * 0.015;
    if(workingDays ==calendarWorkingDays){
        return salaryPercent;
    }
    else{
        salaryPercent = (salaryPercent*workingDays)/calendarWorkingDays;
        return salaryPercent;
    }
}

//Управление отработанными днями
int Receiver::getWorkingDays(){
    return workingDays;
}
void Receiver::setWorkingDays(int workingDays){
    this->workingDays = workingDays;
}

//Управление календарными рабочими днями
int Receiver::getCalendarWorkingDays(){
    return calendarWorkingDays;
}
void Receiver::setCalendarWorkingDays(int calendarWorkingDays){
    this->calendarWorkingDays = calendarWorkingDays;
}

double Receiver::getMinSalary(){
    return minSalary;
}
void Receiver::setMinSalary(double minSalary){
    this->minSalary = minSalary;
}

double Receiver::calculateTotalSalary(){

    return minSalary + salaryPercent;
}

double Receiver::calculateMinSalary(){
        if(profit <= 2000000){
            minSalary = 10000;
        }
        else if ((profit > 2000000) && (profit < 3000000)) {
            minSalary = 150000;
        }
        else if((profit >= 3000000) && (profit < 4000000)){
            minSalary = 20000;
        }
        else{
            minSalary = 25000;
        }

        if(workingDays == calendarWorkingDays){
            return minSalary;
        }
        else{
            minSalary = (minSalary*workingDays)/calendarWorkingDays;
            return minSalary;
        }

}
