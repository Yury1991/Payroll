#ifndef RECEIVERWINDOW_H
#define RECEIVERWINDOW_H

#include <QDialog>
#include <QtWidgets>

class ReceiverWindow : public QDialog
{
    Q_OBJECT
public:
    ReceiverWindow();
    ~ReceiverWindow();

    /*Расчет выработки
    virtual double getProfit();
    virtual void setProfit(double profit);*/

    QLabel *profitLabel;
    QLineEdit *profitLine;


    /*Расчет процента от выработки
    virtual double getPercent();
    virtual double calculateSalaryPercent();*/

    QLabel *salaryPercentLabel;
    QLineEdit *salaryPercentLine;
    /*Расчет минимальной зарплаты/оклада
    double calculateMinSalary() override;*/

    QLabel *minSalaryLabel;
    QLineEdit *minSalaryLine;

    /*Расчет итоговой зарплаты
    double calculateTotalSalary() override;*/

    QLabel *totalSalaryLabel;
    QLineEdit *totalSalaryLine;



 private:
    double profit = 0;          //общая выработка предприятия
    const double percent = 0.015;     // процент от выработки
    double salaryPercent = 0;   // процент от выработки в денежном эквиваленте
    double totalSalary = 0;
};

#endif // RECEIVERWINDOW_H
