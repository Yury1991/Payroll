#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include "employeewindow.h"
#include "receiverwindow.h"

class Manager;

class ManagerWindow : public ReceiverWindow
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
    QLabel *managerProfitLabel;
    QLabel *managerProfitValueLabel;
    QRadioButton *payFundRadio;
    QLabel *sellPercentLabel;
    QRadioButton *fourPercent;
    QRadioButton *sevenPercent;

    Manager *manager;


    QGroupBox *gbPercent;

    //Компоновка окна
    QHBoxLayout *sellProfitLayout;
    QHBoxLayout *managerProfitLayout;
    QHBoxLayout *payFundLayout;
    QHBoxLayout *sellPercentLayout;
    QHBoxLayout *percentButtonsLayout;
    QHBoxLayout *gbLayout;

    //Вектор горизонтальных слоев
    QVector<QHBoxLayout*> managerLayouts;

    //Главный слой
    QGridLayout *managerMainLayout;

    QWidget *managerWidget;

};

#endif // MANAGERWINDOW_H
