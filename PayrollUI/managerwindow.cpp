#include "managerwindow.h"
#include "staffwindow.h"
#include "manager.h"

ManagerWindow::ManagerWindow()
{
    dateLabel = createLabel("Дата заполнения:");
    dateValueLabel = createLabel(createDate());
    fullNameLabel = createLabel("ФИО сотрудника:");
    fullNameLine = createEmptyLine();
    sellProfitLabel = createLabel("Прибыль от продаж: ");
    sellProfitLine = createEmptyLine();
    salaryLabel = createLabel("Оклад:");
    salaryLine = createEmptyLine();
    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine();
    calendarWorkingDaysLabel = createLabel("Рабочие дни:");
    calendarWorkingDaysLine = createEmptyLine();
    managerProfitLabel = createLabel("Прибыль сотрудника:");
    managerProfitValueLabel = createEmptyLabel();

    fourPercent = new QRadioButton("4%");
    sevenPercent = new QRadioButton("7%");

    totalSalaryLabel = createLabel("Итоговая зп:");
    totalSalaryLine = createEmptyLine();

    calculateButton = createCalculateButton();
    writeButton = createWriteButton();
    backButton = createBackButton();


    //Компоновка
    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    sellProfitLayout = createPackedHLayout(sellProfitLabel, sellProfitLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    payFundLayout = createRightPackedHLayout(gbOptions);
    percentButtonsLayout = createRightPackedHLayout(fourPercent, sevenPercent);
    gbPercent = createGroupBox(tr("Процент менеджера:"), percentButtonsLayout);
    sellPercentLayout = createRightPackedHLayout(gbPercent);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryValueLabel);
    managerProfitLayout = createPackedHLayout(managerProfitLabel, managerProfitValueLabel);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createPackedHLayout(calculateButton, writeButton);
    backLayout = createLeftPackedHLayout(backButton);

    managerLayouts = {dateLayout, fullNameLayout, sellProfitLayout, workingDaysLayout, calendarWorkingDaysLayout,
                     payFundLayout, sellPercentLayout, minSalaryLayout, managerProfitLayout, intermediateSalaryLayout, penaltyLayout,
                     premiumLayout, adjustmentLayout, totalSalaryLayout, calculateLayout, backLayout};

    managerMainLayout = createMainLayout(managerLayouts);
    managerWidget = createWidget(managerMainLayout);
    setCentralWidget(managerWidget);
    setWindowTitle("Расчет зарплаты менеджера");
}
void ManagerWindow::slotCalculateButtonClicked(){
    if((getValue(workingDaysLine) > getValue(calendarWorkingDaysLine)) || ((getValue(calendarWorkingDaysLine) == 0)))
    {
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
    }
    else{
        qreal percent = 0;
        if(fourPercent->isChecked()){
            percent = 0.04;
        }
        else{
            percent = 0.07;
        }
        manager = new Manager(fullNameLine->text(), getValue(sellProfitLine), getDays(workingDaysLine), getDays(calendarWorkingDaysLine), percent,
                              payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));
        /*Manager(QString fullName, qreal sellProfit, ushort workingDays, ushort calendarWorkingDays, qreal managerPercent,
            bool isPayFund, qreal penalty, qreal premium, qreal adjustment);*/
        QString managerPercentValue = QString::number(manager->calculateSellProfitPercent());
        QString managerIntermediateSalary = QString::number(manager->calculateIntermediateSalary());
        QString managerTotalSalary = QString::number(manager->calculateTotalSalary());
        managerProfitValueLabel->setText(managerPercentValue);
        intermediateSalaryValueLabel->setText(managerIntermediateSalary);
        totalSalaryLine->setText(managerTotalSalary);
    }
}

void ManagerWindow::slotBackButtonClicked(){
    this->close();
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow->show();
}

void ManagerWindow::slotWriteButtonClicked(){

}
ManagerWindow::~ManagerWindow()
{

}
