#include "receiverwindow.h"

ReceiverWindow::ReceiverWindow()
{
    profitLabel = new QLabel("Введите выработку предприятия: ");
    profitLine = new QLineEdit(" ");
    QHBoxLayout *profitLayout = new QHBoxLayout;
    profitLayout->addWidget(profitLabel);
    profitLayout->addWidget(profitLine);

    salaryPercentLabel = new QLabel("Процент от выработки: ");
    salaryPercentLine  = new QLineEdit(" ");
    QHBoxLayout *salaryPercentLayout = new QHBoxLayout;
    salaryPercentLayout->addWidget(salaryPercentLabel);
    salaryPercentLayout->addWidget(salaryPercentLine);


    minSalaryLabel = new QLabel("Процент от выработки: ");
    minSalaryLine = new QLineEdit(" ");
    QHBoxLayout *minSalaryLayout = new QHBoxLayout;
    minSalaryLayout->addWidget(minSalaryLabel);
    minSalaryLayout->addWidget(minSalaryLine);


    totalSalaryLabel = new QLabel("Итоговая зарплата: ");
    totalSalaryLine = new QLineEdit(" ");
    QHBoxLayout *totalSalaryLayout = new QHBoxLayout;
    totalSalaryLayout->addWidget(totalSalaryLabel);
    totalSalaryLayout->addWidget(totalSalaryLine);

    QGridLayout *employeeLayout = new QGridLayout;
    employeeLayout->addLayout(profitLayout, 0 , 0);
    employeeLayout->addLayout(salaryPercentLayout, 1 , 0);
    employeeLayout->addLayout(minSalaryLayout, 2 , 0);
    employeeLayout->addLayout(totalSalaryLayout, 3 , 0);
    setLayout(employeeLayout);
    setMinimumSize(200, 200);

}

ReceiverWindow::~ReceiverWindow(){

}
