#include "receiver.h"

Receiver::Receiver()
{

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

double Receiver::calculateSalaryPercent(){

    salaryPercent = profit * 0.015;
    if(Receiver::getWorkingDays() == Receiver::getCalendarWorkingDays()){
        return salaryPercent;
    }
    else{
        salaryPercent = (salaryPercent*Receiver::getWorkingDays())/Receiver::getCalendarWorkingDays();
        return salaryPercent;
    }
}

double Receiver::calculateTotalSalary(){
    Receiver::setTotalSalary(Receiver::getMinSalary() + salaryPercent);
    return getTotalSalary();
}

double Receiver::calculateMinSalary(){
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

Receiver::~Receiver(){

}
