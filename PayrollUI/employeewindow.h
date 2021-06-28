#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QDialog>
#include <QtWidgets>



class EmployeeWindow : public QDialog
{
    friend class ReceiverWindow;
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
     QHBoxLayout *createPackedLayout(QWidget *pwgt1);
     QHBoxLayout *createPackedLayout(QWidget *pwgt1, QWidget *pwgt2);
     QGridLayout *createMainLayout();
     QGridLayout *getMainLayout();

   // QVector<QHBoxLayout> *insertLayout(QHBoxLayout *hlayout);
public slots:
    virtual void slotCalculateButtonClicked();

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
    QHBoxLayout *calculateLayout= nullptr;
   // QVector<QHBoxLayout> *quantityHorizontalLayouts;
    QGridLayout *mainLayout= nullptr;


};

#endif // EMPLOYEEWINDOW_H
