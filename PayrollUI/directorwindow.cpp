/*#include "directorwindow.h"
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

    profitLayout = createPackedHLayout(profitLabel, profitLine);
    salaryPercentLayout = createPackedHLayout(salaryPercentLabel, salaryPercentLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createPackedHLayout(calculateButton, backButton);
    directorLayout = createMainLayout();   
    directorWidget = createWidget(directorLayout);
    setWindowTitle("Расчет зарплаты директора");

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

*/
