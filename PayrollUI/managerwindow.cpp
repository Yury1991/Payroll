#include "managerwindow.h"
#include "staffwindow.h"
#include "manager.h"
#include "fileprogress.h"

ManagerWindow::ManagerWindow(QWidget*parent): EmployeeWindow(parent)
{
    sellProfitLabel = createLabel("Прибыль от продаж: ");
    sellProfitLine = createEmptyLine();   
    managerProfitLabel = createLabel("Прибыль сотрудника: ");
    managerProfitValueLabel = createEmptyLabel();

    rbFourPercent = new QRadioButton("4%");
    rbSevenPercent = new QRadioButton("7%");
    rbSevenPercent->setChecked(true);
    minSalaryLabel = createLabel("Оклад:");
    minSalaryValueLabel = createLabel("45000");

    wDaysLine = createEmptyLine();
    allDaysLine = createEmptyLine();

    //Компоновка
    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    sellProfitLayout = createPackedHLayout(sellProfitLabel, sellProfitLine);
    wDaysLayout = createPackedHLayout(wDaysLabel, wDaysLine);
    allDaysLayout = createPackedHLayout(allDaysLabel, allDaysLine);
    payFundRadio = new QRadioButton("10% в фонд отпускных");
    optionsLayout = createRightPackedHLayout(payFundRadio);
    optionsBox = createGroupBox(tr("Доп. условия:"), optionsLayout);
    payFundLayout = createRightPackedHLayout(optionsBox);
    percentButtonsLayout = createRightPackedHLayout(rbFourPercent, rbSevenPercent);
    gbPercent = createGroupBox(tr("Процент менеджера:"), percentButtonsLayout);
    sellPercentLayout = createRightPackedHLayout(gbPercent);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryValueLabel);
    managerProfitLayout = createPackedHLayout(managerProfitLabel, managerProfitValueLabel);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout = createLeftPackedHLayout(backButton);

    managerLayouts = {dateLayout, fullNameLayout, sellProfitLayout, wDaysLayout, allDaysLayout,
                     payFundLayout,sellPercentLayout, minSalaryLayout, managerProfitLayout, intermediateSalaryLayout, penaltyLayout,
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
        manager = new Manager(fullNameLine->text(), getValue(sellProfitLine), getDays(wDaysLine), getDays(allDaysLine),
                           payFundRadio->isChecked(),rbFourPercent->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));
        managerProfitValueLabel->setText(QString::number(manager->calculateManagerProfit()));
        intermediateSalaryValueLabel->setText(QString::number(manager->calculateIntermediateSalary()));
        totalSalaryLine->setText(QString::number(manager->calculateTotalSalary()));

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
