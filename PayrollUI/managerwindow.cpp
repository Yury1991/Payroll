#include "managerwindow.h"
#include "staffwindow.h"
#include "manager.h"

ManagerWindow::ManagerWindow()
{

    sellProfitLabel = createLabel("Прибыль от продаж: ");
    sellProfitLine = createEmptyLine();   
    managerProfitLabel = createLabel("Прибыль сотрудника:");
    managerProfitValueLabel = createEmptyLabel();

    fourPercent = new QRadioButton("4%");
    sevenPercent = new QRadioButton("7%");

    salaryLine = new QLineEdit("45000");

    //Компоновка
    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    sellProfitLayout = createPackedHLayout(sellProfitLabel, sellProfitLine);
    wDaysLayout = createPackedHLayout(wDaysLabel, wDaysLine);
    allDaysLayout = createPackedHLayout(allDaysLabel, allDaysLine);
    payFundLayout = createRightPackedHLayout(optionsBox);
    percentButtonsLayout = createRightPackedHLayout(fourPercent, sevenPercent);
    gbPercent = createGroupBox(tr("Процент менеджера:"), percentButtonsLayout);
    sellPercentLayout = createRightPackedHLayout(gbPercent);
    salaryLayout = createPackedHLayout(salaryLabel, salaryLine);
    managerProfitLayout = createPackedHLayout(managerProfitLabel, managerProfitValueLabel);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout = createLeftPackedHLayout(backButton);

    managerLayouts = {dateLayout, fullNameLayout, sellProfitLayout, wDaysLayout, allDaysLayout,
                     payFundLayout, sellPercentLayout, salaryLayout, managerProfitLayout, intermediateSalaryLayout, penaltyLayout,
                     premiumLayout, adjustmentLayout, totalSalaryLayout, calculateLayout, backLayout};

    managerMainLayout = createMainLayout(managerLayouts);
    managerWidget = createWidget(managerMainLayout);
    setCentralWidget(managerWidget);
    setWindowTitle("Расчет зарплаты менеджера");
}
void ManagerWindow::slotCalculateButtonClicked(){
    if((getValue(wDaysLine) > getValue(allDaysLine)) || ((getValue(allDaysLine) == 0)))
    {
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
    }
    else{       
        manager = new Manager(fullNameLine->text(), getValue(sellProfitLine), getDays(wDaysLine), getDays(allDaysLine), fourPercent->isChecked(),
                              payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));
        QString managerProfit = QString::number(manager->calculateManagerProfit());
        managerProfitValueLabel->setText(managerProfit);
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
