#include "receiverwindow.h"
#include "receiver.h"


ReceiverWindow::ReceiverWindow()
{
    profitLabel = createLabel("Введите выработку предприятия: ");
    profitLine = createEmptyLine();
    salaryPercentLabel = createLabel("Процент от выработки: ");
    salaryPercentLine  = createEmptyLine();
    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine();
    calendarWorkingDaysLabel = createLabel("Календарные дни:");
    calendarWorkingDaysLine = createEmptyLine();
    minSalaryLabel = createLabel("Оклад: ");
    minSalaryLine = createEmptyLine();
    totalSalaryLabel = createLabel("Итоговая зарплата: ");
    totalSalaryLine = createEmptyLine();

    calculateButton = createButton("Рассчитать");
    connect(calculateButton, &QPushButton::clicked, this, &ReceiverWindow::slotCalculateButtonClicked);

    profitLayout = createPackedLayout(profitLabel, profitLine);    
    salaryPercentLayout = createPackedLayout(salaryPercentLabel, salaryPercentLine);
    workingDaysLayout = createPackedLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    minSalaryLayout = createPackedLayout(minSalaryLabel, minSalaryLine);
    totalSalaryLayout = createPackedLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createPackedLayout(calculateButton);



    receiverLayout = createMainLayout();
    receiverLayout->addLayout(profitLayout, 0 , 0);
    receiverLayout->addLayout(salaryPercentLayout, 1 , 0);
    receiverLayout->addLayout(minSalaryLayout, 2 , 0);
    receiverLayout->addLayout(totalSalaryLayout, 3 , 0);
    receiverLayout->addLayout(minSalaryLayout, 4 , 0);
    receiverLayout->addLayout(totalSalaryLayout, 5 , 0);
    receiverLayout->addLayout(calculateLayout, 6, 0);

    setLayout(receiverLayout);
    setWindowTitle("Расчет зарплаты приемщиков");
    setMinimumSize(350, 350);
}

void ReceiverWindow::slotCalculateButtonClicked(){
    Receiver *receiver = new Receiver();
    receiver->setProfit(getValue(profitLine));
    receiver->calculateSalaryPercent();
    receiver->setWorkingDays(getValue(workingDaysLine));
    receiver->setCalendarWorkingDays(getValue(calendarWorkingDaysLine));
    receiver->calculateMinSalary();
    QString res = QString::number(receiver->calculateTotalSalary());
    totalSalaryLine->setText(res);
}


ReceiverWindow::~ReceiverWindow(){

}
