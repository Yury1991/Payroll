#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include <QDialog>
#include <QtWidgets>



class StaffWindow : public QDialog{

    Q_OBJECT

public:
    StaffWindow();
    ~StaffWindow();
    //Методы
    QPushButton *createButton(const QString &str); //создание кнопки
    QString *getButtonName();
    void setButtonName(QString buttonName);
public slots:
    void slotButtonClicked();
private:
    QLabel *staffLabel = new QLabel("Список сотрудников:");
    QPushButton *employeeButton;
    QPushButton *receiverButton;
    QPushButton *directorButton;
    QPushButton *masterButton;
    QPushButton *managerButton;
    QPushButton *backButton;
    QString *buttonName = nullptr;
};

#endif // STAFFWINDOW_H
