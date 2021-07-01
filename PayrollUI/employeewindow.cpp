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

    //Компоновка окна
    salaryLayout = createPackedHLayout(salaryLabel, salaryLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout= createPackedHLayout(calculateButton);
    backLayout= createPackedHLayout(backButton);

    employeeLayout = new QGridLayout;
    employeeLayout->addLayout(salaryLayout, 0, 0);
    employeeLayout->addLayout(workingDaysLayout, 1, 0);
    employeeLayout->addLayout(calendarWorkingDaysLayout, 2, 0);
    employeeLayout->addLayout(totalSalaryLayout, 3, 0);
    employeeLayout->addLayout(calculateLayout, 4, 0);
    employeeLayout->addLayout(backLayout, 5, 0);

    //employeeWidget = createWidget(employeeLayout);
    employeeWidget = new QWidget;
    employeeWidget->setLayout(employeeLayout);
    employeeWidget->setMinimumSize(350, 350);
    setCentralWidget(employeeWidget);
    setWindowTitle("Расчет зарплаты окладчика");
}

QLabel *EmployeeWindow::createLabel(const QString &str){
    QLabel *lbl = new QLabel(str);
    return lbl;
}
QPushButton *EmployeeWindow::createButton(const QString &str){
    QPushButton *button = new QPushButton(str);
    connect(button, &QPushButton::clicked, this, &EmployeeWindow::slotButtonClicked);
    setButtonName(button->text());
    return button;
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

QWidget *EmployeeWindow::createWidget(QGridLayout *layout){
    QWidget *pwgt = new QWidget;
    pwgt->setLayout(layout);
    pwgt->setMinimumSize(350, 350);
    setCentralWidget(pwgt);
    return pwgt;
}

QWidget *EmployeeWindow::getWidget(){
    return employeeWidget;
}


QString *EmployeeWindow::getButtonName(){
    return buttonName;
}
void EmployeeWindow::setButtonName(QString buttonName){
    this->buttonName = &buttonName;
}

qreal EmployeeWindow::getValue(QLineEdit *line){
    qreal value;
    value = line->text().toDouble();
    return value;
}
void EmployeeWindow::slotButtonClicked(){
    this->close();
    if(buttonName == calculateButton->text()){
        Employee *employee = new Employee();
        employee->setMinSalary(getValue(salaryLine));
        employee->setWorkingDays(getValue(workingDaysLine));
        employee->setCalendarWorkingDays(getValue(calendarWorkingDaysLine));
        QString res = QString::number(employee->calculateTotalSalary());
        totalSalaryLine->setText(res);
        totalSalaryLine->displayText();
    }
    else{
        StaffWindow *staffWindow = new StaffWindow();
        staffWindow->show();
    }
}





EmployeeWindow::~EmployeeWindow(){

}
