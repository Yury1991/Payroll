#ifndef RECEIVERWINDOW_H
#define RECEIVERWINDOW_H

#include <QDialog>
#include <QtWidgets>
#include "employeewindow.h"

class ReceiverWindow : public EmployeeWindow
{
    friend class DirectorWindow;

public:
     explicit ReceiverWindow(QWidget *parent = nullptr);
    ~ReceiverWindow();
    QHBoxLayout *createPackedHLayout(QWidget *pwgt1);
    QHBoxLayout *createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
    QLabel *createLabel(const QString &str);
    QPushButton *createButton(const QString &str);
    QLineEdit *createLine(const QString &str);
    QLineEdit *createEmptyLine();
    QGridLayout *createMainLayout();
    QGridLayout *getMainLayout();
    QWidget *getWidget();
public slots:
     void slotCalculateButtonClicked();
 private:
    double profit = 0;          //общая выработка предприятия
    const double percent = 0.015;     // процент от выработки
    double salaryPercent = 0;   // процент от выработки в денежном эквиваленте
    double totalSalary = 0;
    QLabel *profitLabel;
    QLineEdit *profitLine;
    QLabel *salaryPercentLabel;
    QLineEdit *salaryPercentLine;
    QLabel *minSalaryLabel;
    QLineEdit *minSalaryLine;
    QLabel *totalSalaryLabel;
    QLineEdit *totalSalaryLine;
    QHBoxLayout *profitLayout;
    QHBoxLayout *salaryPercentLayout;
    QHBoxLayout *minSalaryLayout;
    QHBoxLayout *totalSalaryLayout;
    QGridLayout *receiverLayout;
    QWidget *receiverWidget;

};

#endif // RECEIVERWINDOW_H
