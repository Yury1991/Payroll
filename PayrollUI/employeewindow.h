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
    friend class MasterWindow;
    Q_OBJECT
public:
    //Конструкторы:
    EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

    //Функциональные методы:
     QString createDate();

     //Считывание данных со строк:
     qreal getValue(QLineEdit *line);       //считывание данных типа qreal/double  - денежные значения
     ushort getDays(QLineEdit *line);       //считывание данных типа ushort  - дни календаря

     //Методы для создания элементов интерфейса:
     QLabel *createLabel(const QString &str);
     QLabel *createEmptyLabel();
     QLabel *createEmptyRightLabel();
     QPushButton *createBackButton();
     QPushButton *createCalculateButton();
     QPushButton *createWriteButton();
     QLineEdit *createEmptyLine();


     // Создание компоновок:
     QHBoxLayout *createButtonHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QHBoxLayout *createRightPackedHLayout(QWidget *pwgt1);
     QHBoxLayout *createLeftPackedHLayout(QWidget *pwgt1);
     QHBoxLayout *createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QHBoxLayout *createCentralPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QHBoxLayout *createRightPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QGroupBox *createGroupBox(QString const &str, QHBoxLayout *hlayout);
     QGridLayout *createMainLayout(QVector<QHBoxLayout*> layouts);
     //Создание виджета:
     QWidget *createWidget(QGridLayout *layout);     
public slots:
     virtual void slotCalculateButtonClicked();
     virtual void slotBackButtonClicked();
     virtual void slotWriteButtonClicked();
private:
    QString strDate;  
    QLabel *dateLabel;
    QLabel *dateValueLabel;
    QLabel *fullNameLabel;
    QLineEdit *fullNameLine;
    QLabel *salaryLabel;
    QLineEdit *salaryLine;
    QLabel *wDaysLabel;
    QLineEdit *wDaysLine;
    QLabel *allDaysLabel;
    QLineEdit *allDaysLine;
    QLabel *intermediateSalaryLabel;
    QLabel *intermediateSalaryValueLabel;
    QLabel *penaltyLabel;
    QLineEdit *penaltyLine;
    QLabel *premiumLabel;
    QLineEdit *premiumLine;
    QLabel *adjustmentLabel;
    QLineEdit *adjustmentLine;
    QLabel *totalSalaryLabel;
    QLineEdit *totalSalaryLine;
    QGroupBox *optionsBox;
    QRadioButton *payFundRadio;
    QPushButton *calculateButton;
    QPushButton *backButton;
    QPushButton *writeButton;
    //Объект класса
    Employee *employee;
    //Компоновка
    //Горизонтальные слои
    QHBoxLayout *dateLayout;
    QHBoxLayout *fullNameLayout;
    QHBoxLayout *salaryLayout;
    QHBoxLayout *wDaysLayout;
    QHBoxLayout *allDaysLayout;
    QHBoxLayout *intermediateSalaryLayout;
    QHBoxLayout *penaltyLayout;
    QHBoxLayout *premiumLayout;
    QHBoxLayout *adjustmentLayout;
    QHBoxLayout *payFundLayout;
    QHBoxLayout *totalSalaryLayout;
    QHBoxLayout *calculateLayout;
    QHBoxLayout *backLayout;
    QHBoxLayout *optionsLayout;
    //Вектор горизонтальных слоев:
    QVector<QHBoxLayout*> employeeLayouts;
    //Главный слой:
    QGridLayout *employeeMainLayout;
    //Виджет:
    QWidget *employeeWidget;
    //Ошибка ввода:
    const QString inputError = " Указано неверное значение!";
};

#endif // EMPLOYEEWINDOW_H
