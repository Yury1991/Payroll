#include "masterwindow.h"
#include "staffwindow.h"
#include "master.h"

MasterWindow::MasterWindow()
{
    masterProdLabel = createLabel("Выработка мастера:");
    masterProdLine = createEmptyLine();
    firstMinProfit = new QRadioButton("40000");
    secondMinProfit = new QRadioButton("50000");
    minProfitLayout = createRightPackedHLayout(firstMinProfit, secondMinProfit);
    minProfitBox = createGroupBox("Минимальная выработка мастера:", minProfitLayout);


    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    profitLayout = createRightPackedHLayout(minProfitBox);
    masterProdLayout = createPackedHLayout(masterProdLabel, masterProdLine);
    payFundLayout = createRightPackedHLayout(vacationPayBox);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout = createLeftPackedHLayout(backButton);

    masterLayouts = {dateLayout, fullNameLayout, profitLayout, masterProdLayout, payFundLayout,
                    intermediateSalaryLayout, penaltyLayout, premiumLayout, adjustmentLayout, totalSalaryLayout,
                    calculateLayout, backLayout};
    masterMainLayout = createMainLayout(masterLayouts);
    masterWidget = createWidget(masterMainLayout);
    setCentralWidget(masterWidget);
}

void MasterWindow::slotCalculateButtonClicked(){

    master = new Master(fullNameLine->text(), getValue(masterProdLine), firstMinProfit->isChecked(),
                          payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));
    QString masterProdProfit = QString::number(master->calculateMasterProdProfit());
    QString masterIntermediateProfit = QString::number(master->calculateIntermediateSalary());
    QString masterTotalSalary = QString::number(master->calculateTotalSalary());
    intermediateSalaryValueLabel->setText(masterIntermediateProfit);
    totalSalaryLine->setText(masterTotalSalary);

}

void MasterWindow::slotBackButtonClicked(){
    this->close();
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow->show();
}

void MasterWindow::slotWriteButtonClicked(){

}
MasterWindow::~MasterWindow(){

}
