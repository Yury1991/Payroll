#include "receiverwindow.h"
#include "receiver.h"
#include "staffwindow.h"


ReceiverWindow::ReceiverWindow(QWidget*parent)
    : EmployeeWindow(parent)
{
    profitLabel = createLabel("Выработка предприятия");
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
    backButton = createButton("Назад");

    //Компоновка окна
    profitLayout = createPackedHLayout(profitLabel, profitLine);
    salaryPercentLayout = createPackedHLayout(salaryPercentLabel, salaryPercentLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createPackedHLayout(calculateButton);
    backLayout = createPackedHLayout(backButton);
    receiverLayout = new QGridLayout;
    receiverLayout->addLayout(profitLayout, 0, 0);
    receiverLayout->addLayout(salaryPercentLayout, 1, 0);
    receiverLayout->addLayout(workingDaysLayout, 2 ,0);
    receiverLayout->addLayout(calendarWorkingDaysLayout, 3, 0);
    receiverLayout->addLayout(minSalaryLayout, 4, 0);
    receiverLayout->addLayout(totalSalaryLayout, 5, 0);
    receiverLayout->addLayout(calculateLayout, 6, 0);
    receiverLayout->addLayout(backLayout, 7, 0);
    receiverWidget = createWidget(receiverLayout);
    setWindowTitle("Расчет зарплаты приемщиков");
}

void ReceiverWindow::slotButtonClicked(){
    if(buttonName == calculateButton->text()){
        Receiver *receiver = new Receiver();
        receiver->setProfit(getValue(profitLine));
        receiver->calculateSalaryPercent();
        receiver->setWorkingDays(getValue(workingDaysLine));
        receiver->setCalendarWorkingDays(getValue(calendarWorkingDaysLine));
        receiver->calculateMinSalary();
        QString res = QString::number(receiver->calculateTotalSalary());
        totalSalaryLine->setText(res);
        totalSalaryLine->displayText();
    }
    else{
        StaffWindow *staffWindow = new StaffWindow();
        staffWindow->show();
    }
    this->close();
}





ReceiverWindow::~ReceiverWindow(){

}
