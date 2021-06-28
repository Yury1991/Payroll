#include "employeewindow.h"
#include "employee.h"

EmployeeWindow::EmployeeWindow(QWidget *parent) :  QDialog(parent)
{
    salaryLabel = createLabel("Оклад:");
    salaryLine = createEmptyLine();
    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine();
    calendarWorkingDaysLabel = createLabel("Календарные дни:");
    calendarWorkingDaysLine = createEmptyLine();
    totalSalaryLabel = createLabel("Итоговая зп:");
    totalSalaryLine = createEmptyLine();
    calculateButton = createButton("Рассчитать");

    connect(calculateButton, &QPushButton::clicked, this, &EmployeeWindow::slotCalculateButtonClicked);

    //Компоновка окна
    salaryLayout = createPackedLayout(salaryLabel, salaryLine);
    workingDaysLayout = createPackedLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    totalSalaryLayout = createPackedLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createPackedLayout(calculateButton);
    mainLayout = createMainLayout();
    mainLayout->addLayout(salaryLayout, 0 , 0);
    mainLayout->addLayout(workingDaysLayout, 1 , 0);
    mainLayout->addLayout(calendarWorkingDaysLayout, 2 , 0);
    mainLayout->addLayout(totalSalaryLayout, 3 , 0);
    mainLayout->addLayout(calculateLayout, 4, 0);

    setLayout(mainLayout);
    setWindowTitle("Расчет зарплаты окладчика");
    setMinimumSize(350, 350);


}

QLabel *EmployeeWindow::createLabel(const QString &str){
    QLabel *lbl = new QLabel(str);
    return lbl;
}
QPushButton *EmployeeWindow::createButton(const QString &str){
    QPushButton *button = new QPushButton(str);
    return button;
}
QLineEdit *EmployeeWindow::createLine(const QString &str){
    QLineEdit *line = new QLineEdit(str);
    return line;
}
QLineEdit *EmployeeWindow::createEmptyLine(){
    QLineEdit *line = new QLineEdit(" ");
    return line;
}
QHBoxLayout *EmployeeWindow::createPackedLayout(QWidget *pwgt1){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1);
    return hlayout;
}

QHBoxLayout *EmployeeWindow::createPackedLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1);
    hlayout->addWidget(pwgt2);
    return hlayout;
}


QGridLayout *EmployeeWindow::createMainLayout(){
    QGridLayout *gridLayout = new QGridLayout;
    return gridLayout;
}

QGridLayout *EmployeeWindow::getMainLayout(){
    return mainLayout;
}

qreal EmployeeWindow::getValue(QLineEdit *line){
    qreal value;
    value = line->text().toDouble();
    return value;
}

void EmployeeWindow::slotCalculateButtonClicked(){
    Employee *employee = new Employee();
    employee->setMinSalary(getValue(salaryLine));
    employee->setWorkingDays(getValue(workingDaysLine));
    employee->setCalendarWorkingDays(getValue(calendarWorkingDaysLine));
    QString res = QString::number(employee->calculateTotalSalary());
    delete employee;
    totalSalaryLine->setText(res);
}

EmployeeWindow::~EmployeeWindow(){

}
