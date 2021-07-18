#include "manager.h"

Manager::Manager()
{
    sellProfit = 0;
    minSalary = 45000;

}

qreal Manager::calculateSellProfitPercent(){
    managerProfit = sellProfit * managerPercent;
    return managerProfit ;
}

qreal Manager::calculateMinSalary(){
    return minSalary;
}

qreal Manager::calculateTotalSalary(){
    totalSalary = managerProfit + minSalary;
    return totalSalary;
}

Manager::~Manager(){

}
