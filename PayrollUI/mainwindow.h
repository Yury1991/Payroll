#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtWidgets>

class MainWindow : public QDialog
{
    Q_OBJECT

private:
    QPushButton *calculateButton;   //кнопка рассчитать
    QPushButton *exitButton;        //кнопка выхода
public:
    //Конструкторы:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Методы
    QPushButton* createButton(const QString &str); //создание кнопки
public slots:
    virtual void slotCalculateButtonClicked();

};
#endif // MAINWINDOW_H
