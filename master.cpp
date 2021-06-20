#include "master.h"

Master::Master()
{

}

// оплата выработки
double Master::getMasterProfit(){
    return masterProfit;
}
void Master::setMasterProfit(double masterProfit){
    this->masterProfit = masterProfit;
}

//Имеется ли премия
bool Master::getIsPremium(){
    return isPremium;
}

void Master::setIsPremium(bool isPremium){
    this->isPremium = isPremium;
}

//Управление отработанными днями
int Master::getWorkingDays(){
    return workingDays;
}
void Master::setWorkingDays(int workingDays){
    this->workingDays = workingDays;
}

//Управление календарными рабочими днями
int Master::getCalendarWorkingDays(){
    return calendarWorkingDays;
}
void Master::setCalendarWorkingDays(int calendarWorkingDays){
    this->calendarWorkingDays = calendarWorkingDays;
}

//Расчет премии
double Master::getPremium(){
    return premium;
}
void Master::setPremium(double premium){
    this->premium = premium;
}
double Master::calculatePremium() {
    if((isPremium == true) && (workingDays == calendarWorkingDays)){
        return premium;
    }
    else if((isPremium == true) && (workingDays != calendarWorkingDays)){
        premium = (premium*workingDays)/calendarWorkingDays;
        return premium;
    }
    else{
        premium = 0;
        return premium;
    }

}

//Итоговая зарплата
double Master::calculateTotalSalary(){
    setTotalSalary(masterProfit + premium);
    return getTotalSalary();
}

Master::~Master(){

}
