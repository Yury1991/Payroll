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
     QHBoxLayout *createEmptyHLayout();
     QHBoxLayout *createButtonHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QHBoxLayout *createRightPackedHLayout(QWidget *pwgt1);
     QHBoxLayout *createLeftPackedHLayout(QWidget *pwgt1);
     QHBoxLayout *createPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QHBoxLayout *createCentralPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QHBoxLayout *createRightPackedHLayout(QWidget *pwgt1, QWidget *pwgt2);
     QGridLayout *createPackedGridLayout(QHBoxLayout *hlayout1, QHBoxLayout *hlayout2);
     QGridLayout *createPackedGridLayout(QHBoxLayout *hlayout1, QHBoxLayout *hlayout2, QHBoxLayout *hlayout3);
     QGridLayout *createPackedGridLayout(QHBoxLayout *hlayout1, QHBoxLayout *hlayout2, QHBoxLayout *hlayout3, QHBoxLayout *hlayout4);
     QGroupBox *createGroupBox(QString const &str, QHBoxLayout *hlayout);
     QGroupBox *createGroupBox(QString const &str, QGridLayout *glayout);
     QHBoxLayout *createPackedBoxHLayout(QWidget *pwgt);
     QHBoxLayout *createGroupLayout();
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
    QLabel *vacationPayLabel;
    QLineEdit *vacationPayLine;
    QLabel *vacationPayBalanceLabel;
    QLineEdit *vacationPayBalanceLine;
    QLabel *withdrawVacationPayLabel;
    QLineEdit *withdrawVacationPayLine;
    QLabel *intermediateSalaryLabel;
    QLabel *intermediateSalaryValueLabel;
    QLabel *penaltyLabel;
    QLineEdit *penaltyLine;
    QLabel *premiumLabel;
    QLineEdit *premiumLine;
    QLabel *adjustmentLabel;
    QLineEdit *adjustmentLine;
    QLabel *noteLabel;
    QLineEdit *noteLine;
    QLabel *totalSalaryLabel;
    QLineEdit *totalSalaryLine;

    //Компоновка
    QGroupBox *daysBox;
    QGroupBox *vacationPayBox;
    QGroupBox *optionsBox;

    QRadioButton *payFundRadio;



    //Кнопки:
    QPushButton *calculateButton;
    QPushButton *backButton;
    QPushButton *writeButton;
    //Объект класса
    Employee *employee;
    //Компоновка
    //Горизонтальные слои
    QHBoxLayout *spaceLayout;
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
    QHBoxLayout *vacationPayLayout;
    QHBoxLayout *vacationPayBalanceLayout;
    QHBoxLayout *withdrawVacationPayLayout;
    QHBoxLayout *noteLayout;
    QHBoxLayout *totalSalaryLayout;
    QHBoxLayout *calculateLayout;
    QHBoxLayout *backLayout;

    QGridLayout *optionsLayout;
    QGridLayout *daysLayout;
    QGridLayout *payLayout;

    QHBoxLayout *daysGroupLayout;
    QHBoxLayout *vacationGroupLayout;
    QHBoxLayout *optionsGroupLayout;



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
