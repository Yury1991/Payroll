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

public slots:    
    void slotEmployeeButtonClicked();
    void slotReceiverButtonClicked();
    void slotDirectorButtonClicked();
  /*void slotMasterButtonClicked();*/
    void slotManagerButtonClicked();
    void slotBackButtonClicked();
private:
    QLabel *staffLabel = new QLabel("Список сотрудников:");
    QPushButton *employeeButton;
    QPushButton *receiverButton;
    QPushButton *directorButton;
    QPushButton *masterButton;
    QPushButton *managerButton;                                      
    QPushButton *backButton;    
};

#endif // STAFFWINDOW_H
