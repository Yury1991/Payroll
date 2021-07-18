#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H
#include <QMainWindow>
#include <QDialog>
#include <QtWidgets>

class Employee;
class EmployeeWindow : public QMainWindow
{
    friend class ReceiverWindow;
    friend class DirectorWindow;
    friend class ManagerWindow;

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
  //   unsigned short getValue(QLineEdit *line);
     qreal getValue(QLineEdit *line);

     //Методы для создания элементов интерфейса
     QLabel *createLabel(const QString &str);
     QPushButton *createButton(const QString &str);
     QLineEdit *createEmptyLine(const int &width);
     QLabel *createEmptyLabel();
     QLabel *createEmptyRightLabel();
     QString createDate();
     QHBoxLayout *createButtonHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QHBoxLayout *createPackedHLayout(QWidget *pwgt1);
     QHBoxLayout *createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QWidget *createWidget(QGridLayout *layout);
     QGridLayout *createMainLayout(QVector<QHBoxLayout*> layouts);

public slots:
//     virtual void slotButtonClicked();
     virtual void slotCalculateButtonClicked();
     virtual void slotBackButtonClicked();
     virtual void slotWriteButtonClicked();

private:
    QString strDate;
  //  QDate date;
    QLabel *dateLabel;
    QLabel *dateValueLabel;
    QLabel *fullNameLabel;
    QLineEdit *fullNameLine;
    QLabel *salaryLabel;
    QLineEdit *salaryLine;
    QLabel *workingDaysLabel;
    QLineEdit *workingDaysLine;
    QLabel *calendarWorkingDaysLabel;
    QLineEdit *calendarWorkingDaysLine;
    QLabel *totalSalaryLabel;
    QLineEdit *totalSalaryLine;

    QRadioButton *payFundRadio;

    QPushButton *calculateButton;
    QPushButton *backButton;
    QPushButton *writeButton;
    QString *buttonName;

    //Объект класса
    Employee *employee;
    //Компоновка;
    //Горизонтальные слои
    QHBoxLayout *dateLayout;
    QHBoxLayout *fullNameLayout;
    QHBoxLayout *salaryLayout;
    QHBoxLayout *workingDaysLayout;
    QHBoxLayout *calendarWorkingDaysLayout;
    QHBoxLayout *payFundLayout;
    QHBoxLayout *totalSalaryLayout;
    QHBoxLayout *calculateLayout;
    QHBoxLayout *backLayout;
    //Вектор горизонтальных слоев:
    QVector<QHBoxLayout*> employeeLayouts;
    //Главный слой
    QGridLayout *employeeMainLayout;
    //Виджет
    QWidget *employeeWidget;

    //Ошибка ввода
    const QString inputError = " Указано неверное значение!";

};

#endif // EMPLOYEEWINDOW_H
