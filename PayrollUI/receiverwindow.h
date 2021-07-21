#ifndef RECEIVERWINDOW_H
#define RECEIVERWINDOW_H

#include "employeewindow.h"

class Receiver;

class ReceiverWindow : public EmployeeWindow
{
    friend class DirectorWindow;
    friend class ManagerWindow;
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
    QLabel *totalSalaryLabel;
    QLineEdit *totalSalaryLine;



    //Объект класса:
    Receiver *receiver;
    //  Компоновка окна
    // Горизонталтные мслои
    QHBoxLayout *profitLayout;
    QHBoxLayout *salaryPercentLayout;
    QHBoxLayout *minSalaryLayout;
    QHBoxLayout *totalSalaryLayout;


    //Вектор горизонтальных слоев
    QVector<QHBoxLayout*> receiverLayouts;
    //Главный слой
    QGridLayout *receiverMainLayout;
    //Виджет
    QWidget *receiverWidget;
};

#endif // RECEIVERWINDOW_H
