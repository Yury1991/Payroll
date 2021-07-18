#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDialog>
#include <QtWidgets>

class MainWindow : public QDialog
{
    Q_OBJECT
public:
    //Конструкторы:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Методы
    QPushButton* createButton(const QString &str); //создание кнопки
public slots:
    virtual void slotCalculateButtonClicked();
    void slotSettingsButtonClicked();
private:
    QPushButton *calculateButton;   //кнопка рассчитать
    QPushButton *settingsButton;     //кнопка параметры
    QPushButton *exitButton;        //кнопка выхода
};
#endif // MAINWINDOW_H
