#include "director.h"
#include "receiver.h"


Director::Director(){

}

Director::Director(QString fullName, double profit,  unsigned short workingDays, unsigned short calendarWorkingDays, bool isPayFund){
    this->fullName = fullName;
    this->profit = profit;
    this->workingDays = workingDays;
    this->calendarWorkingDays = calendarWorkingDays;
    this->isPayFund = isPayFund;
}

double Director::calculateSalaryPercent(){
    salaryPercent = profit * 0.03;
    if(Director::getWorkingDays() == Director::getCalendarWorkingDays()){
        return salaryPercent;
    }
    else{
        salaryPercent = (salaryPercent*Director::getWorkingDays())/Director::getCalendarWorkingDays();
        return salaryPercent;
    }
}

double Director::getDirectorFee(){
    return directorFee;
}

double Director::calculateTotalSalary(){
    totalSalary = salaryPercent + directorFee + minSalary;
    if(isPayFund == true){
         totalSalary -= totalSalary * 0.1;
         return totalSalary;
    }
    else{
       return totalSalary;
    }
}

double Director::calculateMinSalary(){
    if(Director::getWorkingDays() == Director::getCalendarWorkingDays()){
        return minSalary = 15000;
    }
    else{
        return minSalary = (minSalary * Director::getWorkingDays())/Director::getCalendarWorkingDays();
    }
}

Director::~Director(){

}
