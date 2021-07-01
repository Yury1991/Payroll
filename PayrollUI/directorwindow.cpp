#include "directorwindow.h"
#include "staffwindow.h"
#include "director.h"

DirectorWindow::DirectorWindow(QWidget *parent): ReceiverWindow(parent)
{
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
    connect(calculateButton, &QPushButton::clicked, this, &DirectorWindow::slotCalculateButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &DirectorWindow::slotBackButtonClicked);
    profitLayout = createPackedHLayout(profitLabel, profitLine);
    salaryPercentLayout = createPackedHLayout(salaryPercentLabel, salaryPercentLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createPackedVLayout(calculateButton, backButton);
    directorLayout = createMainLayout();
    directorLayout->addLayout(profitLayout, 0, 0);
    directorLayout->addLayout(salaryPercentLayout, 1, 0);
    directorLayout->addLayout(minSalaryLayout, 2, 0);
    directorLayout->addLayout(totalSalaryLayout, 3, 0);
    directorLayout->addLayout(minSalaryLayout, 4, 0);
    directorLayout->addLayout(totalSalaryLayout, 5, 0);
    directorLayout->addLayout(calculateLayout, 6, 0);
    directorWidget = new QWidget;
    directorWidget->setLayout(directorLayout);
    directorWidget->setMinimumSize(350, 350);
    directorWidget->setWindowTitle("Расчет зарплаты директора");
    setCentralWidget(directorWidget);
    directorWidget->show();
}
void DirectorWindow::slotCalculateButtonClicked() {
    Director *director = new Director();
    director->setMinSalary(getValue(salaryLine));
    director->setWorkingDays(getValue(workingDaysLine));
    director->setCalendarWorkingDays(getValue(calendarWorkingDaysLine));
    QString res = QString::number(director->calculateTotalSalary());
    totalSalaryLine->setText(res);
    totalSalaryLine->displayText();
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

