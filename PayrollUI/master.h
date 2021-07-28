#ifndef MASTER_H
#define MASTER_H

#include "employee.h"

class Master : public Employee
{  
public:
    Master();
    Master(QString fullName, qreal masterProd, bool isFirst,
           bool isPayFund, qreal penalty, qreal premium, qreal adjustment);
    ~Master();
    qreal calculateMasterProdProfit();
    qreal calculateIntermediateSalary() override;
    qreal calculateTotalSalary() override;
private:
    const QString position = "Мастер";
    qreal masterProd;
    qreal masterProdProfit;
    const qreal firstMinProfit = 40000;
    const qreal secondMinProfit = 50000;
    bool isFirst;
    bool isSecond;
};

#endif // MASTER_H
