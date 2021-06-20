#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include <QDialog>
#include <QtWidgets>
#include "mainwindow.h"

class MainWindow;


class StaffWindow : public QDialog{

    Q_OBJECT
private:
    QLabel *staffLabel;
    QPushButton *employeeButton;
    QPushButton *receiverButton;
    QPushButton *directorButton;
    QPushButton *masterButton;
    QPushButton *managerButton;
public:
    StaffWindow();
    ~StaffWindow();
    //Методы
    QPushButton* createButton(const QString &str); //создание кнопки
public slots:
    void slotReceiverButtonClicked();
};

#endif // STAFFWINDOW_H
