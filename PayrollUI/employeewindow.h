#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H
#include <QMainWindow>
#include <QDialog>
#include <QtWidgets>



class EmployeeWindow : public QMainWindow
{
    friend class ReceiverWindow;
    friend class DirectorWindow;

    Q_OBJECT
public:
    //Конструкторы:
    EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

     //Методы доступа:
     QHBoxLayout *getHBoxLayout(QHBoxLayout *getHBoxLayout);
     QWidget *getWidget();
     QString *getButtonName();
     void setButtonName(QString buttonName);
     qreal getValue(QLineEdit *line);

     //Методы для создания элементов интерфейса
     QLabel *createLabel(const QString &str);
     QPushButton *createButton(const QString &str);
     QLineEdit *createEmptyLine();
     QHBoxLayout *createPackedHLayout(QWidget *pwgt1);
     QHBoxLayout *createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QWidget *createWidget(QGridLayout *layout);
public slots:     
     virtual void slotButtonClicked();
private:
    QLabel *salaryLabel;
    QLineEdit *salaryLine;
    QLabel *workingDaysLabel;
    QLineEdit *workingDaysLine;
    QLabel *calendarWorkingDaysLabel;
    QLineEdit *calendarWorkingDaysLine;
    QLabel *totalSalaryLabel;
    QLineEdit *totalSalaryLine;

    QPushButton *calculateButton;
    QPushButton *backButton;
    QString *buttonName;
    //Компоновка;
    QHBoxLayout *salaryLayout;
    QHBoxLayout *workingDaysLayout;
    QHBoxLayout *calendarWorkingDaysLayout;
    QHBoxLayout *totalSalaryLayout;
    QHBoxLayout *calculateLayout;
    QHBoxLayout *backLayout;
    QGridLayout *employeeLayout;
    QWidget *employeeWidget;





};

#endif // EMPLOYEEWINDOW_H
