#include "manager.h"

Manager::Manager(){

}

Manager::Manager(QString fullName, qreal sellProfit, ushort wDays, ushort allDays,
                 bool isPayFund, bool isFourPercent, qreal penalty, qreal premium, qreal adjustment)
{
    this->fullName = fullName;
    this->sellProfit = sellProfit;
    this->wDays = wDays;
    this->allDays = allDays;
    this->isPayFund = isPayFund;
    this->isFourPercent = isFourPercent;
    this->penalty = penalty;
    this->premium = premium;
    this->adjustment = adjustment;
}

qreal Manager::calculateManagerProfit(){
    if(isFourPercent == true)
        managerProfit = (sellProfit * 0.04);
    else
        managerProfit = (sellProfit * 0.07);
    return managerProfit;
}
qreal Manager::getManagerProfit(){
    return managerProfit;
}

void Manager::setManagerProfit(qreal managerProfit){
    this->managerProfit = managerProfit;
}

qreal Manager::calculateIntermediateSalary(){
    if(wDays == allDays){
        intermediateSalary = minSalary + managerProfit;
    }
    else{
        intermediateSalary = ((minSalary * wDays)/allDays) + managerProfit;
    }
    if(isPayFund == true){
        intermediateSalary -=  (intermediateSalary* 0.1) ;
        return intermediateSalary;
    }
    else{
        return intermediateSalary;
    }
}

qreal Manager::calculateTotalSalary(){
    totalSalary = intermediateSalary - penalty + premium + adjustment;
    return totalSalary;
}

Manager::~Manager(){

}
