#ifndef RECEIVERWINDOW_H
#define RECEIVERWINDOW_H

#include "employeewindow.h"

class Receiver;

class ReceiverWindow : public EmployeeWindow
{
    friend class DirectorWindow;    
public:
    //Конструкторы
     ReceiverWindow(QWidget *parent = nullptr);
    ~ReceiverWindow();   
public slots:
     void slotCalculateButtonClicked() override;
     void slotBackButtonClicked() override;
     void slotWriteButtonClicked() override;
 private:    
    //Элементы интерфейса:
    QLabel *profitLabel;
    QLineEdit *profitLine;
    QLabel *salaryPercentLabel;
    QLabel *salaryPercentValueLabel;
    QLabel *minSalaryLabel;
    QLabel *minSalaryValueLabel;
    //Объект класса:
    Receiver *receiver;
    //  Компоновка окна
    // Горизонталтная компонвка
    QHBoxLayout *profitLayout;
    QHBoxLayout *salaryPercentLayout;
    QHBoxLayout *minSalaryLayout;
    //Вектор горизонтальных слоев для данного объекта
    QVector<QHBoxLayout*> receiverLayouts;
    //Главный слой для данного объекта
    QGridLayout *receiverMainLayout;
    //Виджет для данного объекта
    QWidget *receiverWidget;
};

#endif // RECEIVERWINDOW_H
