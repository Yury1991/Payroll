#include "directorwindow.h"
#include "staffwindow.h"
#include "director.h"

DirectorWindow::DirectorWindow(QWidget *parent): ReceiverWindow(parent)
{
    profitLabel = createLabel("Выработка предприятия");
    profitLine = createEmptyLine(200);
    salaryPercentLabel = createLabel("Процент от выработки: ");
    salaryPercentValueLabel  = createEmptyLabel();
    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine(200);
    calendarWorkingDaysLabel = createLabel("Рабочие дни:");
    calendarWorkingDaysLine = createEmptyLine(200);
    minSalaryLabel = createLabel("Оклад: ");
    minSalaryValueLabel = createEmptyLabel();
    directorFeeLabel = createLabel("Доплата директора:");
    directorFeeValueLabel = createEmptyLabel();
    totalSalaryLabel = createLabel("Итоговая зарплата: ");
    totalSalaryLine = createEmptyLine(200);

    calculateButton = createButton("Рассчитать");
    writeButton = createButton("Записать");
    backButton = createButton("Назад");
    connect(calculateButton, &QPushButton::clicked, this, &DirectorWindow::slotCalculateButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &DirectorWindow::slotBackButtonClicked);

    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    profitLayout = createPackedHLayout(profitLabel, profitLine);
    salaryPercentLayout = createPackedHLayout(salaryPercentLabel, salaryPercentValueLabel);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    payFundLayout = createPackedHLayout(payFundRadio);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryValueLabel);
    directorFeeLayout = createPackedHLayout(directorFeeLabel, directorFeeValueLabel);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout = createPackedHLayout(backButton);

    directorLayouts = {dateLayout, fullNameLayout, profitLayout, workingDaysLayout, calendarWorkingDaysLayout,
                      payFundLayout, salaryPercentLayout, minSalaryLayout, directorFeeLayout, totalSalaryLayout, calculateLayout, backLayout};
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
        director = new Director(fullNameLine->text(), getValue(profitLine), getValue(workingDaysLine), getValue(calendarWorkingDaysLine),
                                payFundRadio->isChecked());
        QString directorFeeValue = QString::number(director->getDirectorFee());
        QString salaryPercentValue = QString::number(director->calculateSalaryPercent());
        QString directorMinSalaryValue = QString::number(director->calculateMinSalary());
        QString totalSalaryValue = QString::number(director->calculateTotalSalary());
        minSalaryValueLabel->setText(directorMinSalaryValue);
        directorFeeValueLabel->setText(directorFeeValue);
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

QWidget *DirectorWindow::getWidget(){
    return directorWidget;
}

DirectorWindow::~DirectorWindow(){

}

