#include "directorwindow.h"
#include "staffwindow.h"
#include "director.h"

DirectorWindow::DirectorWindow(QWidget *parent): ReceiverWindow(parent)
{
    profitLabel = createLabel("Выработка предприятия");
    profitLine = createEmptyLine();
    salaryPercentLabel = createLabel("Процент от выработки: ");
    salaryPercentValueLabel  = createEmptyLabel();
    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine();
    calendarWorkingDaysLabel = createLabel("Рабочие дни:");
    calendarWorkingDaysLine = createEmptyLine();
    minSalaryLabel = createLabel("Оклад: ");
    minSalaryValueLabel = createEmptyLabel();
    directorFeeLabel = createLabel("Доплата директора:");
    directorFeeValueLabel = createEmptyLabel();
    totalSalaryLabel = createLabel("Итоговая зарплата: ");
    totalSalaryLine = createEmptyLine();

    calculateButton = createCalculateButton();
    writeButton = createWriteButton();
    backButton = createBackButton();


    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    profitLayout = createPackedHLayout(profitLabel, profitLine);
    salaryPercentLayout = createPackedHLayout(salaryPercentLabel, salaryPercentValueLabel);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    payFundLayout = createRightPackedHLayout(gbOptions);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryValueLabel);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    directorFeeLayout = createPackedHLayout(directorFeeLabel, directorFeeValueLabel);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout = createLeftPackedHLayout(backButton);

    directorLayouts = {dateLayout, fullNameLayout, profitLayout, workingDaysLayout, calendarWorkingDaysLayout,
                      payFundLayout, salaryPercentLayout, minSalaryLayout, directorFeeLayout, intermediateSalaryLayout,
                      penaltyLayout, premiumLayout, adjustmentLayout,totalSalaryLayout, calculateLayout, backLayout};
    directorLayout = createMainLayout(directorLayouts);
    directorWidget = createWidget(directorLayout);
    setCentralWidget(directorWidget);
    setWindowTitle("Расчет зарплаты директора");
}

void DirectorWindow::slotCalculateButtonClicked() {
    if((getValue(workingDaysLine) > getValue(calendarWorkingDaysLine)) || (getValue(profitLine) == 0)
            || (getValue(calendarWorkingDaysLine) == 0)){
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
        minSalaryValueLabel->setText("");
        salaryPercentValueLabel->setText("");
    }
    else{    
        director = new Director(fullNameLine->text(), getValue(profitLine), getDays(workingDaysLine), getDays(calendarWorkingDaysLine),
                                payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));
        QString directorFeeValue = QString::number(director->getDirectorFee());
        QString salaryPercentValue = QString::number(director->calculateSalaryPercent());
        QString directorMinSalaryValue = QString::number(director->calculateMinSalary());
        QString intermediateSalaryValue = QString::number(director->calculateIntermediateSalary());
        QString totalSalaryValue = QString::number(director->calculateTotalSalary());
        minSalaryValueLabel->setText(directorMinSalaryValue);
        directorFeeValueLabel->setText(directorFeeValue);
        intermediateSalaryValueLabel->setText(intermediateSalaryValue);
        salaryPercentValueLabel->setText(salaryPercentValue);
        totalSalaryLine->setText(totalSalaryValue);
        totalSalaryLine->displayText();
    }
}

void DirectorWindow::slotBackButtonClicked(){
    this->close();
    StaffWindow *sw = new StaffWindow();
    sw->show();
}
void DirectorWindow::slotWriteButtonClicked(){
    this->close();
    StaffWindow *sw = new StaffWindow();
    sw->show();
}

QWidget *DirectorWindow::getWidget(){
    return directorWidget;
}

DirectorWindow::~DirectorWindow(){

}

