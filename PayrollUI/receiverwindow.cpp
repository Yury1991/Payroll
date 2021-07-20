#include "receiverwindow.h"
#include "receiver.h"
#include "staffwindow.h"
#include "errorwindow.h"
#include "fileprogress.h"

//Конструктор
ReceiverWindow::ReceiverWindow(QWidget*parent)
    : EmployeeWindow(parent)
{
    dateLabel = createLabel("Дата заполнения:");
    dateValueLabel = createLabel(createDate());

    fullNameLabel = createLabel("ФИО сотрудника:");
    fullNameLine = createEmptyLine();

    profitLabel = createLabel("Выработка предприятия:");
    profitLine = createEmptyLine();

    workingDaysLabel = createLabel("Отработанные дни:");
    workingDaysLine = createEmptyLine();

    calendarWorkingDaysLabel = createLabel("Рабочие дни");
    calendarWorkingDaysLine = createEmptyLine();



    salaryPercentLabel = createLabel("Процент от выработки: ");
    salaryPercentValueLabel  = new QLabel("");

    minSalaryLabel = createLabel("Оклад: ");
    minSalaryValueLabel = createEmptyLabel();

    totalSalaryLabel = createLabel("Итоговая зарплата: ");
    totalSalaryLine = createEmptyLine();

    calculateButton = createButton("Рассчитать");    
    backButton = createButton("Назад");
    writeButton = createButton("Записать");
    connect(calculateButton, &QPushButton::clicked, this, &ReceiverWindow::slotCalculateButtonClicked);
    connect(writeButton, &QPushButton::clicked, this, &ReceiverWindow::slotWriteButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &ReceiverWindow::slotBackButtonClicked);

    //Компоновка окна

    dateLayout = createPackedHLayout(dateLabel, dateValueLabel);
    fullNameLayout = createPackedHLayout(fullNameLabel, fullNameLine);
    profitLayout = createPackedHLayout(profitLabel, profitLine);
    salaryPercentLayout = createPackedHLayout(salaryPercentLabel, salaryPercentValueLabel);
    workingDaysLayout = createPackedHLayout(workingDaysLabel, workingDaysLine);
    calendarWorkingDaysLayout = createPackedHLayout(calendarWorkingDaysLabel, calendarWorkingDaysLine);
    payFundLayout = createPackedHLayout(payFundRadio);
    intermediateSalaryLayout = createPackedHLayout(intermediateSalaryLabel, intermediateSalaryValueLabel);
    penaltyLayout = createPackedHLayout(penaltyLabel, penaltyLine);
    premiumLayout = createPackedHLayout(premiumLabel, premiumLine);
    adjustmentLayout = createPackedHLayout(adjustmentLabel, adjustmentLine);
    minSalaryLayout = createPackedHLayout(minSalaryLabel, minSalaryValueLabel);
    totalSalaryLayout = createPackedHLayout(totalSalaryLabel, totalSalaryLine);
    calculateLayout = createButtonHLayout(calculateButton, writeButton);
    backLayout = createPackedHLayout(backButton);

    receiverLayouts = {dateLayout, fullNameLayout, profitLayout,  workingDaysLayout, calendarWorkingDaysLayout,
                       payFundLayout,intermediateSalaryLayout, penaltyLayout, premiumLayout, adjustmentLayout, salaryPercentLayout, minSalaryLayout,
                       totalSalaryLayout, calculateLayout, backLayout};

    receiverMainLayout = createMainLayout(receiverLayouts);
    receiverWidget = createWidget(receiverMainLayout);
    setWindowTitle("Расчет зарплаты приемщиков");
    setCentralWidget(receiverWidget);
}


// Реализация перегрузки слотов:
void ReceiverWindow::slotCalculateButtonClicked(){
    if((getValue(workingDaysLine) > getValue(calendarWorkingDaysLine)) || (getValue(profitLine) == 0)
            || (getValue(calendarWorkingDaysLine) == 0)){
        totalSalaryLine->setText(inputError);
        totalSalaryLine->displayText();
        minSalaryValueLabel->setText("");
        salaryPercentValueLabel->setText("");
    }
    else{
        receiver = new Receiver(fullNameLine->text(), getValue(profitLine), getValue(workingDaysLine), getValue(calendarWorkingDaysLine),
                                payFundRadio->isChecked(), getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));
        QString salaryPercentValue = QString::number(receiver->calculateSalaryPercent());
        QString minSalaryValue = QString::number(receiver->calculateMinSalary());
        QString intermediateSalary = QString::number(receiver->calculateIntermediateSalary());
        QString totalSalaryValue = QString::number(receiver->calculateTotalSalary());
        minSalaryValueLabel->setText(minSalaryValue);
        salaryPercentValueLabel->setText(salaryPercentValue);
        intermediateSalaryValueLabel->setText(intermediateSalary);
        totalSalaryLine->setText(totalSalaryValue);
        totalSalaryLine->displayText();
    }
}
void ReceiverWindow::slotWriteButtonClicked(){
    receiver = new Receiver(fullNameLine->text(), getValue(profitLine), getValue(workingDaysLine), getValue(calendarWorkingDaysLine),
                            payFundRadio->isChecked(),getValue(penaltyLine), getValue(premiumLine), getValue(adjustmentLine));

    QString salaryPercentValue = QString::number(receiver->calculateSalaryPercent());
    QString minSalaryValue = QString::number(receiver->calculateMinSalary());
    QString totalSalaryValue = QString::number(receiver->calculateTotalSalary());


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
            str += receiver->getPosition();            
            str += " ФИО: ";
            str += receiver->getFullName();            
            str += " Отработанные дни: ";
            str += QString::number(receiver->getWorkingDays());            
            str += " Процент приемщика: ";
            str += salaryPercentValue;
            str += " Минимальный оклад: ";
            str += minSalaryValue;
            str +=  " Итоговая зарплата: ";
            str += totalSalaryValue;
            stream << str << Qt::endl;
            file.close();
            FileProgress *fileProgress = new FileProgress();
            fileProgress->show();
        }
    }
}

void ReceiverWindow::slotBackButtonClicked()
{
    this->close();
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow-> show();
}


//Деструктор:
ReceiverWindow::~ReceiverWindow(){

}
