#include "receiver.h"

Receiver::Receiver(){}

Receiver::Receiver(QString fullName, qreal profit,  unsigned short workingDays, unsigned short calendarWorkingDays,
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
qreal Receiver::getProfit(){
    return profit;
}
void Receiver::setProfit(qreal profit){
   this->profit = profit;
}

qreal Receiver::getPercent(){
    return percent;
}

qreal Receiver::calculateSalaryPercent(){
    salaryPercent = profit * 0.015;
    if(Receiver::getWorkingDays() == Receiver::getCalendarWorkingDays()){
        return salaryPercent;
    }
    else{
        salaryPercent = (salaryPercent*Receiver::getWorkingDays())/Receiver::getCalendarWorkingDays();
        return salaryPercent;
    }
}


qreal Receiver::calculateMinSalary(){
        if(profit <= 2000000){
            Receiver::setMinSalary(10000);
        }
        else if ((profit > 2000000) && (profit < 3000000)) {
            Receiver::setMinSalary(150000);
        }
        else if((profit >= 3000000) && (profit < 4000000)){
            Receiver::setMinSalary(20000);
        }
        else{
            Receiver::setMinSalary(25000);
        }

        if(Receiver::getWorkingDays() == Receiver::getCalendarWorkingDays()){
            return Receiver::getMinSalary();
        }
        else{
            Receiver::setMinSalary(Receiver::getMinSalary()*Receiver::getWorkingDays()/Receiver::getCalendarWorkingDays());
            return Receiver::getMinSalary();
        }
}

qreal Receiver::calculateIntermediateSalary(){
    intermediateSalary = minSalary + salaryPercent;
    if(isPayFund == true){
        intermediateSalary -= intermediateSalary *0.1;
        return intermediateSalary;
    }
    else{
        return intermediateSalary;
    }
}

qreal Receiver::calculateTotalSalary(){
    totalSalary = (intermediateSalary - penalty + premium + adjustment);
    return totalSalary;
}
Receiver::~Receiver(){

}
