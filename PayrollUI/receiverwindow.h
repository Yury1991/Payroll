#ifndef RECEIVERWINDOW_H
#define RECEIVERWINDOW_H

#include <QDialog>
#include <QtWidgets>
#include "employeewindow.h"

class EmployeeWindow;

class ReceiverWindow : public EmployeeWindow //EmployeeWindow
{
    Q_OBJECT
public:
    ReceiverWindow();
    ~ReceiverWindow();


    QLabel *profitLabel;
    QLineEdit *profitLine;
    QLabel *salaryPercentLabel;
    QLineEdit *salaryPercentLine;
    QLabel *minSalaryLabel;
    QLineEdit *minSalaryLine;
    QLabel *totalSalaryLabel;
    QLineEdit *totalSalaryLine;


public slots:
     void slotCalculateButtonClicked() override;


 private:
    double profit = 0;          //общая выработка предприятия
    const double percent = 0.015;     // процент от выработки
    double salaryPercent = 0;   // процент от выработки в денежном эквиваленте
    double totalSalary = 0;    
    QHBoxLayout *profitLayout;
    QHBoxLayout *salaryPercentLayout;
    QHBoxLayout *minSalaryLayout;
    QHBoxLayout *totalSalaryLayout;
    QGridLayout *receiverLayout;
};

#endif // RECEIVERWINDOW_H
