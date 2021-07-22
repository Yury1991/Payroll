#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include "employeewindow.h"
#include "receiverwindow.h"

class Manager;

class ManagerWindow : public EmployeeWindow
{
    Q_OBJECT
public:
    ManagerWindow();
    ~ManagerWindow();



public slots:
    void slotCalculateButtonClicked() override;
    void slotBackButtonClicked() override;
    void slotWriteButtonClicked() override;
private:
    QLabel *sellProfitLabel;
    QLineEdit *sellProfitLine;
    QLabel *minSalaryLabel;
    QLabel *minSalaryValueLabel;
    QLabel *managerProfitLabel;
    QLabel *managerProfitValueLabel;
    QRadioButton *payFundRadio;
    QLabel *sellPercentLabel;
    QRadioButton *rbFourPercent;
    QRadioButton *rbSevenPercent;

    Manager *manager;


    QGroupBox *gbPercent;

    //Компоновка окна
    QHBoxLayout *sellProfitLayout;
    QHBoxLayout *minSalaryLayout;
    QHBoxLayout *managerProfitLayout;    
    QHBoxLayout *sellPercentLayout;
    QHBoxLayout *percentButtonsLayout;


    //Вектор горизонтальных слоев
    QVector<QHBoxLayout*> managerLayouts;

    //Главный слой
    QGridLayout *managerMainLayout;

    QWidget *managerWidget;

};

#endif // MANAGERWINDOW_H
