#include "directorwindow.h"
#include "staffwindow.h"
#include "director.h"

DirectorWindow::DirectorWindow(QWidget *parent): ReceiverWindow(parent)
{   
    directorFeeLabel = createLabel("Доплата директора:");
    directorFeeValueLabel = createEmptyLabel();

    //Компоновка окна:
    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    profitLayout = createPackedHLayout(profitLabel, profitLine);
    salaryPercentLayout = createPackedHLayout(salaryPercentLabel, salaryPercentValueLabel);
    wDaysLayout = createPackedHLayout(wDaysLabel, wDaysLine);
    allDaysLayout = createPackedHLayout(allDaysLabel, allDaysLine);
    payFundLayout = createRightPackedHLayout(vacationPayBox);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryValueLabel);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    directorFeeLayout = createPackedHLayout(directorFeeLabel, directorFeeValueLabel);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout = createLeftPackedHLayout(backButton);

    directorLayouts = {dateLayout, fullNameLayout, profitLayout, wDaysLayout, allDaysLayout,
                      payFundLayout, salaryPercentLayout, minSalaryLayout, directorFeeLayout, intermediateSalaryLayout,
                      penaltyLayout, premiumLayout, adjustmentLayout,totalSalaryLayout, calculateLayout, backLayout};
    directorLayout = createMainLayout(directorLayouts);
    directorWidget = createWidget(directorLayout);
    setCentralWidget(directorWidget);
    setWindowTitle("Расчет зарплаты директора");
}

void DirectorWindow::slotCalculateButtonClicked() {
    if((getValue(wDaysLine) > getValue(allDaysLine)) || (getValue(profitLine) == 0)
            || (getValue(allDaysLine) == 0)){
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
        minSalaryValueLabel->setText("");
        salaryPercentValueLabel->setText("");
    }
    else{    
        director = new Director(fullNameLine->text(), getValue(profitLine), getDays(wDaysLine), getDays(allDaysLine),
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

