#include "employeewindow.h"
#include "employee.h"
#include "staffwindow.h"
#include "fileprogress.h"
#include "errorwindow.h"


//Конструктор
EmployeeWindow::EmployeeWindow(QWidget *parent) :  QMainWindow(parent)
{
    dateLabel = createLabel("Дата заполнения:");    
    dateValueLabel = createLabel(createDate());

    fullNameLabel = createLabel("ФИО сотрудника:");
    fullNameLine = createEmptyLine();

    salaryLabel = createLabel("Оклад:");
    salaryLine = createEmptyLine();

    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine();

    calendarWorkingDaysLabel = createLabel("Рабочие дни:");
    calendarWorkingDaysLine = createEmptyLine();

    intermediateSalaryLabel = createLabel("Промежуточная зарплата:");
    intermediateSalaryValueLabel = createLabel("0");



    payFundRadio = new QRadioButton("10% в фонд отпускных");
    optionsLayout = new QHBoxLayout;
    optionsLayout->addWidget(payFundRadio);
    gbOptions = createGroupBox(tr("Доп. условия:"), optionsLayout);

    penaltyLabel = createLabel("Штраф:");
    penaltyLine = createEmptyLine();

    premiumLabel = createLabel("Премия:");
    premiumLine = createEmptyLine();

    adjustmentLabel = createLabel("Корректировка:");
    adjustmentLine = createEmptyLine();

    totalSalaryLabel = createLabel("Итоговая зп:");
    totalSalaryLine = createEmptyLine();


    calculateButton = createCalculateButton();
    writeButton = createWriteButton();
    backButton = createBackButton();


    //Компоновка окна
    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    salaryLayout = createPackedHLayout(salaryLabel, salaryLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    payFundLayout = createRightPackedHLayout(gbOptions);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout= createLeftPackedHLayout(backButton);

    employeeLayouts = {dateLayout, fullNameLayout, salaryLayout, workingDaysLayout, calendarWorkingDaysLayout,
                       payFundLayout, intermediateSalaryLayout, penaltyLayout, premiumLayout, adjustmentLayout,
                       totalSalaryLayout, calculateLayout, backLayout};

    employeeMainLayout = createMainLayout(employeeLayouts);    
    employeeWidget = createWidget(employeeMainLayout);
    setCentralWidget(employeeWidget);
    setWindowTitle("Расчет зарплаты окладчика");
}
//Реализация методов создания элементов интерфейса
QLabel *EmployeeWindow::createLabel(const QString &str){
    QLabel *lbl = new QLabel(str);
    return lbl;
}

QPushButton *EmployeeWindow::createButton(const QString &str){
    QPushButton *button = new QPushButton(str);    
    return button;
}
QPushButton *EmployeeWindow::createBackButton(){
    QPushButton *button = new QPushButton("Назад");
    connect(button, &QPushButton::clicked, this, &EmployeeWindow::slotBackButtonClicked);
    return button;
}

QPushButton *EmployeeWindow::createCalculateButton(){
    QPushButton *button = new QPushButton("Рассчитать");
    connect(button, &QPushButton::clicked, this, &EmployeeWindow::slotCalculateButtonClicked);
    return button;
}

QPushButton *EmployeeWindow::createWriteButton(){
    QPushButton *button = new QPushButton("Записать");
    connect(button, &QPushButton::clicked, this, &EmployeeWindow::slotWriteButtonClicked);
    return button;
}



QLineEdit *EmployeeWindow::createEmptyLine(){
    QLineEdit *line = new QLineEdit(" ");
    line->setAlignment(Qt::AlignRight);
    line->setFixedWidth(200);
    return line;
}

QLabel *EmployeeWindow::createEmptyLabel(){
    QLabel *label = new QLabel(" ");
    return label;
}

QLabel *EmployeeWindow::createEmptyRightLabel(){
    QLabel *label = new QLabel(" ");
    label->setAlignment(Qt::AlignRight);
    return label;
}

QString EmployeeWindow::createDate(){
    QDate date = QDate::currentDate();
    strDate = date.toString();
    return strDate;
}
QHBoxLayout *EmployeeWindow::createRightPackedHLayout(QWidget *pwgt1){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1, 0, Qt::AlignRight);
    return hlayout;
}

QHBoxLayout *EmployeeWindow::createLeftPackedHLayout(QWidget *pwgt1){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1, 0, Qt::AlignLeft);
    return hlayout;
}

QHBoxLayout *EmployeeWindow::createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1, 0, Qt::AlignLeft);
    hlayout->addWidget(pwgt2, 0, Qt::AlignRight);
    return hlayout;
}

QHBoxLayout *EmployeeWindow::createCentralPackedHLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1, 0, Qt::AlignCenter);
    hlayout->addWidget(pwgt2, 0, Qt::AlignCenter);
    return hlayout;
}
QHBoxLayout *EmployeeWindow::createRightPackedHLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1, 0, Qt::AlignRight);
    hlayout->addWidget(pwgt2, 0, Qt::AlignRight);
    return hlayout;
}

QHBoxLayout *EmployeeWindow::createButtonHLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1);
    hlayout->addWidget(pwgt2);
    return hlayout;
}

QGridLayout *EmployeeWindow::createMainLayout(QVector<QHBoxLayout*> layouts){
    QGridLayout *mainLayout = new QGridLayout;
    for(int i = 0; i < layouts.size(); i++){
        if(layouts[i] != payFundLayout)
            mainLayout->addLayout(layouts[i], i, 0);
        else{
            mainLayout->addLayout(layouts[i], i, 0, Qt::AlignRight);
        }
    }
    layouts.clear();
    employeeLayouts.clear();
    return mainLayout;
}

QGroupBox *EmployeeWindow::createGroupBox(QString const &str, QHBoxLayout *hlayout){
    QGroupBox *gb = new QGroupBox(str);
    gb->setAlignment(Qt::AlignCenter);
    gb->setLayout(hlayout);
    return gb;
}

QWidget *EmployeeWindow::createWidget(QGridLayout *layout){
    QWidget *pwgt = new QWidget;
    pwgt->setLayout(layout);
    pwgt->setMinimumSize(450, 400);
    pwgt->setContentsMargins(5, 5, 5, 5);
    return pwgt;
}

//Реализация методов доступа:

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

ushort EmployeeWindow::getDays(QLineEdit *line){
    ushort value;
    value = line->text().toUShort();
    return value;
}

//Реализация слотов:

void EmployeeWindow::slotCalculateButtonClicked(){
    if((getValue(workingDaysLine) > getValue(calendarWorkingDaysLine)) || (getValue(salaryLine) == 0)
        || (getValue(calendarWorkingDaysLine) == 0)){
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
    }
    else{
        employee = new Employee(fullNameLine->text(), getValue(salaryLine), getDays(workingDaysLine), getDays(calendarWorkingDaysLine),
                                payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));
                QString intermediateSalary = QString::number(employee->calculateIntermediateSalary());
        QString totalSalary = QString::number(employee->calculateTotalSalary());
        intermediateSalaryValueLabel->setText(intermediateSalary);
        totalSalaryLine->setText(totalSalary);
        totalSalaryLine->displayText();

    }
}

void EmployeeWindow::slotBackButtonClicked(){
    this->close();
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow->show();
}

void EmployeeWindow::slotWriteButtonClicked(){
    employee = new Employee(fullNameLine->text(), getValue(salaryLine), getValue(workingDaysLine), getValue(calendarWorkingDaysLine),
                            payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));


    QString totalSalary = QString::number(employee->calculateTotalSalary());
    if((getValue(workingDaysLine) > getValue(calendarWorkingDaysLine)) || (getValue(salaryLine) == 0)
        || (getValue(calendarWorkingDaysLine) == 0)){
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
    }
    else{
        QString str;
        QString fileName;
        fileName = "Отчет ";
        fileName += strDate;
        QFile file(fileName);
        QTextStream stream(&file);
        if(file.open(QIODevice::ReadOnly)){
                str = stream.readAll();
                file.close();
                if(stream.status() != QTextStream::Ok){
                    this->close();
                    ErrorWindow *errorWindow = new  ErrorWindow();
                    errorWindow->show();
                }
            }
        if(file.open(QIODevice::WriteOnly)){
            str += "Дата: ";
            str += strDate;
            str += " Должность: ";
            str += employee->getPosition();            
            str += " ФИО: ";
            str += employee->getFullName();            
            str += " Отработанные дни:";
            str += QString::number(employee->getWorkingDays());           
            str += " Минимальный оклад: ";
            str += QString::number(employee->getMinSalary());            
            str += " Итоговая зарплата: ";
            str += totalSalary;
            stream << str << Qt::endl;
            file.close();
            FileProgress *fileProgress = new FileProgress();
            fileProgress->show();
        }
    }    
}


//Деструктор:

EmployeeWindow::~EmployeeWindow(){

}
