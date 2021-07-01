#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H
#include <QMainWindow>
#include <QDialog>
#include <QtWidgets>
#include "directorwindow.h"


class EmployeeWindow : public QMainWindow
{
    friend class ReceiverWindow;
    friend class DirectorWindow;
    Q_OBJECT
public:
    //Конструкторы:
    EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

     //Методы:
    QHBoxLayout *getHBoxLayout(QHBoxLayout *getHBoxLayout);
    qreal getValue(QLineEdit *line);

    //Методы для создания элементов интерфейса
     QLabel *createLabel(const QString &str);
     QPushButton *createButton(const QString &str);
     QLineEdit *createLine(const QString &str);
     QLineEdit *createEmptyLine();
     QHBoxLayout *createPackedHLayout(QWidget *pwgt1);
     QHBoxLayout *createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QVBoxLayout *createPackedVLayout(QWidget *pwgt1, QWidget *pwgt2);
     QGridLayout *createMainLayout();
     QGridLayout *getMainLayout();
     QWidget *getWidget();

   // QVector<QHBoxLayout> *insertLayout(QHBoxLayout *hlayout);
public slots:
    virtual void slotCalculateButtonClicked();
     void slotBackButtonClicked();

private:
    QLabel *salaryLabel = nullptr;
    QLineEdit *salaryLine = nullptr;
    QLabel *workingDaysLabel= nullptr;
    QLineEdit *workingDaysLine = nullptr;
    QLabel *calendarWorkingDaysLabel = nullptr;
    QLineEdit *calendarWorkingDaysLine = nullptr;
    QLabel *totalSalaryLabel = nullptr;
    QLineEdit *totalSalaryLine = nullptr;
    QPushButton *calculateButton = nullptr;
    QHBoxLayout *salaryLayout = nullptr;
    QHBoxLayout *workingDaysLayout = nullptr;
    QHBoxLayout *calendarWorkingDaysLayout= nullptr;
    QHBoxLayout *totalSalaryLayout= nullptr;
    QVBoxLayout *calculateLayout= nullptr;
   // QVector<QHBoxLayout> *quantityHorizontalLayouts;
    QGridLayout *mainLayout= nullptr;
    QPushButton *backButton;
    QWidget *employeeWidget;


};

#endif // EMPLOYEEWINDOW_H
