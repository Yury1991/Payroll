#include "manager.h"

Manager::Manager(){
    sellProfit = 0;

    intermediateSalary = 0;
    managerPercent = 0;
    isPayFund = false;
    penalty = 0;
    premium = 0;
    adjustment = 0;
}

Manager::Manager(QString fullName, qreal sellProfit, ushort workingDays, ushort calendarWorkingDays, qreal managerPercent,
                         bool isPayFund, qreal penalty, qreal premium, qreal adjustment ){
    this->fullName = fullName;
    this->sellProfit = sellProfit;
    this->workingDays = workingDays;
    this->calendarWorkingDays = calendarWorkingDays;
    this->managerPercent = managerPercent;
    this->isPayFund = isPayFund;
    this->penalty = penalty;
    this->premium = premium;
    this->adjustment = adjustment;
}

qreal Manager::calculateSellProfitPercent(){
    managerProfit = sellProfit * managerPercent;
    return managerProfit ;
}


qreal Manager::calculateIntermediateSalary(){
    if(workingDays == calendarWorkingDays){
        intermediateSalary = minSalary;
    }
    else{
        intermediateSalary = (minSalary * workingDays)/calendarWorkingDays;
    }
    if(isPayFund == true){
        intermediateSalary -=  intermediateSalary* 0.1 ;
        return intermediateSalary;
    }
    else{
        return intermediateSalary;
    }
}

Manager::~Manager(){

}
