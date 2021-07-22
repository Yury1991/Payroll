#include "director.h"
#include "receiver.h"


Director::Director(){

}

Director::Director(QString fullName, qreal profit,  unsigned short workingDays, unsigned short calendarWorkingDays,
                   bool isPayFund, qreal penalty, qreal premium, qreal adjustment){
    this->fullName = fullName;
    this->profit = profit;
    this->wDays = workingDays;
    this->allDays = calendarWorkingDays;
    this->isPayFund = isPayFund;
    this->penalty = penalty;
    this->premium = premium;
    this->adjustment = adjustment;
}

qreal Director::calculateSalaryPercent(){
    salaryPercent = profit * 0.03;
    if(Director::getWorkingDays() == Director::getCalendarWorkingDays()){
        return salaryPercent;
    }
    else{
        salaryPercent = (salaryPercent*Director::getWorkingDays())/Director::getCalendarWorkingDays();
        return salaryPercent;
    }
}

qreal Director::getDirectorFee(){
    return directorFee;
}

qreal Director::calculateIntermediateSalary(){
    intermediateSalary = minSalary + salaryPercent + directorFee;
    if(isPayFund == true){
         intermediateSalary -= intermediateSalary * 0.1;
         return intermediateSalary;
    }
    else{
       return intermediateSalary;
    }
}

qreal Director::calculateTotalSalary(){
    totalSalary = (intermediateSalary - penalty + premium + adjustment);
    return totalSalary;
}

qreal Director::calculateMinSalary(){
    if(Director::getWorkingDays() == Director::getCalendarWorkingDays()){
        return minSalary = 15000;
    }
    else{
        return minSalary = (minSalary * Director::getWorkingDays())/Director::getCalendarWorkingDays();
    }
}

Director::~Director(){

}
