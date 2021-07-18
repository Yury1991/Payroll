#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include "employeewindow.h"
#include "receiverwindow.h"

class ManagerWindow : public ReceiverWindow
{
    Q_OBJECT
public:
    ManagerWindow();
    ~ManagerWindow();
private:
    QLabel *sellProfitLabel;
    QLineEdit *sellProfitLine;
    QLabel *managerProfitLabel;
    QLabel *managerProfitValueLabel;
    QRadioButton *payFundRadio;


    //Компоновка окна
    QHBoxLayout *sellProfitLayout;
    QHBoxLayout *managerProfitLayout;
    QHBoxLayout *payFundLayout;

    //Вектор горизонтальных слоев
    QVector<QHBoxLayout*> managerLayouts;

    //Главный слой
    QGridLayout *managerMainLayout;

    QWidget *managerWidget;

};

#endif // MANAGERWINDOW_H
