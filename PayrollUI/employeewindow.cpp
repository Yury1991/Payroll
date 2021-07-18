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
    fullNameLine = createEmptyLine(200);

    salaryLabel = createLabel("Оклад:");
    salaryLine = createEmptyLine(200);

    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine(200);

    calendarWorkingDaysLabel = createLabel("Рабочие дни:");
    calendarWorkingDaysLine = createEmptyLine(200);

    totalSalaryLabel = createLabel("Итоговая зп:");
    totalSalaryLine = createEmptyLine(200);
    payFundRadio = new QRadioButton("10% в фонд отпускных");

    calculateButton = createButton("Рассчитать");
    writeButton = createButton("Записать");

    backButton = createButton("Назад");
    connect(calculateButton, &QPushButton::clicked, this, &EmployeeWindow::slotCalculateButtonClicked);
    connect(writeButton, &QPushButton::clicked, this, &EmployeeWindow::slotWriteButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &EmployeeWindow::slotBackButtonClicked);

    //Компоновка окна
    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    salaryLayout = createPackedHLayout(salaryLabel, salaryLine);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    payFundLayout = createPackedHLayout(payFundRadio);
    payFundLayout->setAlignment(Qt::AlignRight);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout= createPackedHLayout(backButton);

    employeeLayouts = {dateLayout, fullNameLayout, salaryLayout, workingDaysLayout, calendarWorkingDaysLayout,
                       payFundLayout, totalSalaryLayout, calculateLayout, backLayout};

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

QLineEdit *EmployeeWindow::createEmptyLine(const int &width){
    QLineEdit *line = new QLineEdit(" ");
    line->setAlignment(Qt::AlignRight);
    line->setFixedWidth(width);
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
QHBoxLayout *EmployeeWindow::createPackedHLayout(QWidget *pwgt1){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1, 0, Qt::AlignCenter);
    return hlayout;
}

QHBoxLayout *EmployeeWindow::createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2){
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(pwgt1, 0, Qt::AlignLeft);
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

//Реализация слотов:

void EmployeeWindow::slotCalculateButtonClicked(){
    if((getValue(workingDaysLine) > getValue(calendarWorkingDaysLine)) || (getValue(salaryLine) == 0)
        || (getValue(calendarWorkingDaysLine) == 0)){
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
    }
    else{
        employee = new Employee(fullNameLine->text(), getValue(salaryLine), getValue(workingDaysLine), getValue(calendarWorkingDaysLine), payFundRadio->isChecked());
        //Employee(QString fullName, double minSalary, unsigned short workingDays, unsigned short calendarWorkingDays);

        QString res = QString::number(employee->calculateTotalSalary());
        totalSalaryLine->setText(res);
        totalSalaryLine->displayText();

    }
}

void EmployeeWindow::slotBackButtonClicked(){
    this->close();
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow->show();
}

void EmployeeWindow::slotWriteButtonClicked(){
    employee = new Employee(fullNameLine->text(), getValue(salaryLine), getValue(workingDaysLine), getValue(calendarWorkingDaysLine), payFundRadio->isChecked());
    //Employee(QString fullName, double minSalary, unsigned short workingDays, unsigned short calendarWorkingDays);
    QString res = QString::number(employee->calculateTotalSalary());
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
            str += res;
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
