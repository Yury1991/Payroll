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

    wDaysLabel = createLabel("Отработанные дни:");
    wDaysLine = createEmptyLine();

    allDaysLabel = createLabel("Рабочие дни:");
    allDaysLine = createEmptyLine();

    wDaysLayout = createPackedHLayout(wDaysLabel, wDaysLine);
    allDaysLayout = createPackedHLayout(allDaysLabel, allDaysLine);

    daysLayout = createPackedGridLayout(wDaysLayout, allDaysLayout);
    daysBox = createGroupBox(tr("Дни"), daysLayout);

    intermediateSalaryLabel = createLabel("Промежуточная зарплата:");
    intermediateSalaryValueLabel = createLabel("0");


    vacationPayLabel = createLabel("Сумма отпускных к вычету:");
    vacationPayLine = createEmptyLine();

    payFundRadio = new QRadioButton("10% в фонд отпускных");
    payFundLayout = createRightPackedHLayout(payFundRadio);
    vacationPayLayout = createPackedHLayout(vacationPayLabel, vacationPayLine);

    vacationPayBalanceLabel = createLabel("Отпускных накоплено всего:");
    vacationPayBalanceLine = createEmptyLine();
    vacationPayBalanceLayout = createPackedHLayout(vacationPayBalanceLabel, vacationPayBalanceLine);
    withdrawVacationPayLabel = createLabel("Частичное снятие отпускных:");
    withdrawVacationPayLine = createEmptyLine();
    withdrawVacationPayLayout = createPackedHLayout(withdrawVacationPayLabel, withdrawVacationPayLine);
    payLayout = createPackedGridLayout(payFundLayout, vacationPayLayout, vacationPayBalanceLayout, withdrawVacationPayLayout);


    vacationPayBox = createGroupBox(tr("Отпускные"), payLayout);



    penaltyLabel = createLabel("Штраф:");
    penaltyLine = createEmptyLine();

    premiumLabel = createLabel("Премия:");
    premiumLine = createEmptyLine();

    adjustmentLabel = createLabel("Корректировка:");
    adjustmentLine = createEmptyLine();

    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    optionsLayout = createPackedGridLayout(penaltyLayout, premiumLayout, adjustmentLayout);

    optionsBox = createGroupBox(tr("Доп. условия"), optionsLayout);
    optionsGroupLayout = createPackedBoxHLayout(optionsBox);

    noteLabel = createLabel("Примечание:");
    noteLine = createEmptyLine();

    totalSalaryLabel = createLabel("Итоговая зп:");
    totalSalaryLine = createEmptyLine();

    calculateButton = createCalculateButton();
    writeButton = createWriteButton();
    backButton = createBackButton();

    //Компоновка окна
    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    salaryLayout = createPackedHLayout(salaryLabel, salaryLine);

    vacationGroupLayout = createPackedBoxHLayout(vacationPayBox);
    daysGroupLayout = createPackedBoxHLayout(daysBox);

    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);

    noteLayout = createPackedHLayout(noteLabel, noteLine);
    spaceLayout = createEmptyHLayout();
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout= createLeftPackedHLayout(backButton);

    employeeLayouts = {dateLayout, fullNameLayout, salaryLayout, daysGroupLayout,
                       vacationGroupLayout, intermediateSalaryLayout, optionsGroupLayout,
                       noteLayout, spaceLayout, totalSalaryLayout, calculateLayout, backLayout};

    employeeMainLayout = createMainLayout(employeeLayouts);    
    employeeWidget = createWidget(employeeMainLayout);
    setCentralWidget(employeeWidget);
    setWindowTitle("Расчет зарплаты окладчика");
}

//Реализация методов создания элементов интерфейса


//Методы для создания кнопок:
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

//Методы для создания линий:
QLineEdit *EmployeeWindow::createEmptyLine(){
    QLineEdit *line = new QLineEdit(" ");
    line->setAlignment(Qt::AlignRight);
    line->setFixedWidth(200);
    return line;
}

//Методы для создания лейбл:
QLabel *EmployeeWindow::createLabel(const QString &str){
    QLabel *lbl = new QLabel(str);
    return lbl;
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
    strDate = date.toString("dd.MM.yyyy");
    return strDate;
}

//Метод для создания слоев:

QHBoxLayout *EmployeeWindow::createEmptyHLayout(){
    QHBoxLayout *hlayout = new QHBoxLayout;
    QLabel *label = new QLabel(" ");
    hlayout->addWidget(label);
    return hlayout;
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
QHBoxLayout *EmployeeWindow::createPackedBoxHLayout(QWidget *pwgt){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt);
    return hlayout;
}

QHBoxLayout *EmployeeWindow::createButtonHLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1);
    hlayout->addWidget(pwgt2);
    return hlayout;
}

QGridLayout *EmployeeWindow::createPackedGridLayout(QHBoxLayout *hlayout1, QHBoxLayout *hlayout2){
    QGridLayout *gLayout = new QGridLayout;
    gLayout->addLayout(hlayout1, 0, 0);
    gLayout->addLayout(hlayout2, 1, 0);
    return gLayout;

}

QGridLayout *EmployeeWindow::createPackedGridLayout(QHBoxLayout *hlayout1, QHBoxLayout *hlayout2, QHBoxLayout *hlayout3){
    QGridLayout *gLayout = new QGridLayout;
    gLayout->addLayout(hlayout1, 0, 0);
    gLayout->addLayout(hlayout2, 1, 0);
    gLayout->addLayout(hlayout3, 3, 0);
    return gLayout;

}
QGridLayout *EmployeeWindow::createPackedGridLayout(QHBoxLayout *hlayout1, QHBoxLayout *hlayout2, QHBoxLayout *hlayout3, QHBoxLayout *hlayout4){
    QGridLayout *gLayout = new QGridLayout;
    gLayout->addLayout(hlayout1, 0, 0);
    gLayout->addLayout(hlayout2, 1, 0);
    gLayout->addLayout(hlayout3, 3, 0);
    gLayout->addLayout(hlayout4, 4, 0);
    return gLayout;
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

QGroupBox *EmployeeWindow::createGroupBox(QString const &str, QGridLayout *glayout){
    QGroupBox *gb = new QGroupBox(str);
    gb->setAlignment(Qt::AlignCenter);
    gb->setLayout(glayout);
    return gb;
}

//Создание виджета:
QWidget *EmployeeWindow::createWidget(QGridLayout *layout){
    QWidget *pwgt = new QWidget;
    pwgt->setLayout(layout);
    pwgt->setMinimumSize(550, 500);
    pwgt->setContentsMargins(5, 5, 5, 5);
    return pwgt;
}



//Реализация методов считывания строк
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
    if((getValue(wDaysLine) > getValue(allDaysLine)) || (getValue(salaryLine) == 0)
        || (getValue(allDaysLine) == 0)){
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
    }
    else{
        employee = new Employee(fullNameLine->text(), getValue(salaryLine), getDays(wDaysLine), getDays(allDaysLine),
                                payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));
        QString intermediateSalary = QString::number(employee->calculateIntermediateSalary());
        QString totalSalary = QString::number(employee->calculateTotalSalary());
        QString vacationPay = QString::number(employee->getVacationPay());
        vacationPayLine->setText(vacationPay);
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
    employee = new Employee(fullNameLine->text(), getValue(salaryLine), getValue(wDaysLine), getValue(allDaysLine),
                            payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));

    QString totalSalary = QString::number(employee->calculateTotalSalary());
    if((getValue(wDaysLine) > getValue(allDaysLine)) || (getValue(salaryLine) == 0)
        || (getValue(allDaysLine) == 0)){
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
