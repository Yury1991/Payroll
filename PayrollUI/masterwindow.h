#ifndef MASTERWINDOW_H
#define MASTERWINDOW_H
#include "employeewindow.h"


class Master;

class MasterWindow : public EmployeeWindow
{
    Q_OBJECT
public:
    MasterWindow();
    ~MasterWindow();
public slots:
    void slotCalculateButtonClicked() override;
    void slotBackButtonClicked() override;
    void slotWriteButtonClicked() override;
private:

    Master *master;
    QLabel *masterProdLabel;
    QLineEdit *masterProdLine;
    QRadioButton *firstMinProfit;
    QRadioButton *secondMinProfit;
    QGroupBox *minProfitBox;

    QHBoxLayout *minProfitLayout;
    QHBoxLayout *profitLayout;
    QHBoxLayout *masterProdLayout;

    QVector<QHBoxLayout*> masterLayouts;
    QGridLayout *masterMainLayout;
    QWidget *masterWidget;
};

#endif // MASTERWINDOW_H
