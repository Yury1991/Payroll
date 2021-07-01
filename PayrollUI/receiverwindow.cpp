#include "receiverwindow.h"
#include "receiver.h"


ReceiverWindow::ReceiverWindow(QWidget*parent): EmployeeWindow(parent){
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
    connect(calculateButton, &QPushButton::clicked, this, &ReceiverWindow::slotCalculateButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &EmployeeWindow::slotBackButtonClicked);
    profitLayout = createPackedHLayout(profitLabel, profitLine);
    salaryPercentLayout = createPackedHLayout(salaryPercentLabel, salaryPercentLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createPackedVLayout(calculateButton, backButton);
    receiverLayout = createMainLayout();
    receiverLayout->addLayout(profitLayout, 0, 0);
    receiverLayout->addLayout(salaryPercentLayout, 1, 0);
    receiverLayout->addLayout(minSalaryLayout, 2, 0);
    receiverLayout->addLayout(totalSalaryLayout, 3, 0);
    receiverLayout->addLayout(minSalaryLayout, 4, 0);
    receiverLayout->addLayout(totalSalaryLayout, 5, 0);
    receiverLayout->addLayout(calculateLayout, 6, 0);
    receiverWidget = new QWidget;
    receiverWidget->setLayout(receiverLayout);
    receiverWidget->setWindowTitle("Расчет зарплаты приемщиков");
    receiverWidget->setMinimumSize(350, 350);
    setCentralWidget(receiverWidget);
}

void ReceiverWindow::slotCalculateButtonClicked(){
    Receiver *receiver = new Receiver();
    receiver->setProfit(getValue(profitLine));
    receiver->calculateSalaryPercent();
    receiver->setWorkingDays(getValue(workingDaysLine));
    receiver->setCalendarWorkingDays(getValue(calendarWorkingDaysLine));
    receiver->calculateMinSalary();
    QString res = QString::number(receiver->calculateTotalSalary());
    totalSalaryLine->setText(res);
    totalSalaryLine->displayText();
}
QLabel *ReceiverWindow::createLabel(const QString &str){
    QLabel *lbl = new QLabel(str);
    return lbl;
}
QPushButton *ReceiverWindow::createButton(const QString &str){
    QPushButton *button = new QPushButton(str);
    return button;
}
QLineEdit *ReceiverWindow::createLine(const QString &str){
    QLineEdit *line = new QLineEdit(str);
    return line;
}
QLineEdit *ReceiverWindow::createEmptyLine(){
    QLineEdit *line = new QLineEdit(" ");
    return line;
}

QHBoxLayout *ReceiverWindow::createPackedHLayout(QWidget *pwgt1){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1);
    return hlayout;
}

QHBoxLayout *ReceiverWindow::createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1);
    hlayout->addWidget(pwgt2);
    return hlayout;
}

QGridLayout *ReceiverWindow::createMainLayout(){
    QGridLayout *gridLayout = new QGridLayout;
    return gridLayout;
}

QGridLayout *ReceiverWindow::getMainLayout(){
    return mainLayout;
}

QWidget *ReceiverWindow::getWidget(){
    return receiverWidget;
}

ReceiverWindow::~ReceiverWindow(){

}
