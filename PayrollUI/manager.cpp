#include "manager.h"

Manager::Manager(){
    sellProfit = 0;    
    intermediateSalary = 0;    
    isPayFund = false;
    isFourPercent = false;
    penalty = 0;
    premium = 0;
    adjustment = 0;
}

Manager::Manager(QString fullName, qreal sellProfit, ushort wDays, ushort allDays, bool isFourPercent,
                         bool isPayFund, qreal penalty, qreal premium, qreal adjustment ){
    this->fullName = fullName;
    this->sellProfit = sellProfit;    
    this->wDays = wDays;
    this->allDays = allDays;
    this->isFourPercent = isFourPercent;
    this->isPayFund = isPayFund;
    this->penalty = penalty;
    this->premium = premium;
    this->adjustment = adjustment;
}
/* QString managerPercentValue = QString::number(manager->calculateSellProfitPercent());
        QString managerIntermediateSalary = QString::number(manager->calculateIntermediateSalary());
        QString managerTotalSalary = QString::number(manager->calculateTotalSalary());*/
qreal Manager::calculateManagerProfit(){
    if(isFourPercent == true){
        managerProfit = sellProfit * 0.04;
    }
    else{
        managerProfit = sellProfit * 0.07;
    }
    return managerProfit ;
}


qreal Manager::calculateIntermediateSalary(){
    if(wDays == allDays){
        intermediateSalary = (minSalary + managerProfit);
    }
    else{
        intermediateSalary = ((minSalary * wDays)/allDays + managerProfit);
    }
    if(isPayFund == true){
        intermediateSalary -=  intermediateSalary* 0.1 ;
        return intermediateSalary;
    }
    else{
        return intermediateSalary;
    }
}

qreal Manager::calculateTotalSalary(){
    totalSalary = (intermediateSalary - penalty + premium + adjustment);
    return totalSalary;
}

Manager::~Manager(){

}
