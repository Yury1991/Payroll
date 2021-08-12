#ifndef VIEWSTAFFWINDOW_H
#define VIEWSTAFFWINDOW_H

#include <QDialog>
#include <QtWidgets>



class ViewStaffWindow : public QDialog{
    Q_OBJECT
public:
    ViewStaffWindow();
    ~ViewStaffWindow();
    //Методы
    QPushButton *createButton(const QString &str); //создание кнопки

public slots:    
    void slotEmployeeButtonClicked();
    void slotReceiverButtonClicked();
    void slotDirectorButtonClicked();
    void slotMasterButtonClicked();
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

#endif // VIEWSTAFFWINDOW_H
