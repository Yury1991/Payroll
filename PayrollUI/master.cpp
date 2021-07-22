#include "master.h"

Master::Master()
{

}

Master::Master(QString fullName, qreal masterProd, bool isFirst,
               bool isPayFund, qreal penalty, qreal premium, qreal adjustment){
    this->fullName = fullName;
    this->masterProd = masterProd;
    this->isFirst = isFirst;
    this->isPayFund = isPayFund;
    this->penalty = penalty;
    this->premium = premium;
    this->adjustment = adjustment;
}
qreal Master::calculateMasterProdProfit(){
    if((masterProd >= firstMinProfit) && (isFirst == true)){
    masterProdProfit = masterProd;
    }
    else if ((masterProd < firstMinProfit) && (isFirst == true)) {
        masterProdProfit = firstMinProfit;
    }
    else if((masterProd >= secondMinProfit) && (isFirst == false)){
        masterProdProfit = masterProd;
    }
    else{
        masterProdProfit = secondMinProfit;
    }
    return masterProdProfit;
}

qreal Master::calculateIntermediateSalary(){
    intermediateSalary = masterProdProfit;
    if(isPayFund == true){
        intermediateSalary -=  intermediateSalary* 0.1 ;
        return intermediateSalary;
    }
    else{
        return intermediateSalary;
    }
}

qreal Master::calculateTotalSalary(){
    totalSalary = (intermediateSalary - penalty + premium + adjustment);
    return totalSalary;
}

Master::~Master()
{

}
