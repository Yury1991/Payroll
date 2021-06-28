#include "director.h"
#include "receiver.h"


Director::Director(){

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
    return salaryPercent + directorFee + minSalary;
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
