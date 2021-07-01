#include "employeewindow.h"
#include "employee.h"
#include "staffwindow.h"

EmployeeWindow::EmployeeWindow(QWidget *parent) :  QMainWindow(parent)
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
    backButton = createButton("Назад");

    connect(calculateButton, &QPushButton::clicked, this, &EmployeeWindow::slotCalculateButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &EmployeeWindow::slotBackButtonClicked);

    //Компоновка окна
    salaryLayout = createPackedHLayout(salaryLabel, salaryLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout= createPackedVLayout(calculateButton, backButton);
    mainLayout = createMainLayout();
    mainLayout->addLayout(salaryLayout, 0 , 0);
    mainLayout->addLayout(workingDaysLayout, 1 , 0);
    mainLayout->addLayout(calendarWorkingDaysLayout, 2 , 0);
    mainLayout->addLayout(totalSalaryLayout, 3 , 0);
    mainLayout->addLayout(calculateLayout, 4, 0);
    employeeWidget = new QWidget;
    employeeWidget->setLayout(mainLayout);
    employeeWidget->setWindowTitle("Расчет зарплаты окладчика");
    employeeWidget->setMinimumSize(350, 350);
    setCentralWidget(employeeWidget);
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
QHBoxLayout *EmployeeWindow::createPackedHLayout(QWidget *pwgt1){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1);
    return hlayout;
}

QHBoxLayout *EmployeeWindow::createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1);
    hlayout->addWidget(pwgt2);
    return hlayout;
}

QVBoxLayout *EmployeeWindow::createPackedVLayout(QWidget *pwgt1, QWidget *pwgt2){
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(pwgt1);
    vlayout->addWidget(pwgt2);
    return vlayout;
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

QWidget *EmployeeWindow::getWidget(){
    return employeeWidget;
}

void EmployeeWindow::slotCalculateButtonClicked(){
    Employee *employee = new Employee();
    employee->setMinSalary(getValue(salaryLine));
    employee->setWorkingDays(getValue(workingDaysLine));
    employee->setCalendarWorkingDays(getValue(calendarWorkingDaysLine));
    QString res = QString::number(employee->calculateTotalSalary());   
    totalSalaryLine->setText(res);
    totalSalaryLine->displayText();
}

void EmployeeWindow::slotBackButtonClicked(){
    this->close();
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow->show();
}

EmployeeWindow::~EmployeeWindow(){

}
