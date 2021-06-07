#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtWidgets>
#include <QString>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    //Конструкторы
    MainWindow(QWidget *parent = nullptr);    
    //~MainWindow();

private:


    // Кнопки:
    QPushButton *browseButton;
    QPushButton *okButton;
    QPushButton *exitButton;

    //Значок:
    QLabel *directoryLabel;

    //Строка поиска
    QComboBox *directoryComboBox;
    QDir currentDir;

 //   QPushButton *createButton(const QString &text, const char *member);
    QComboBox *createComboBox(const QString &text = QString());



private slots:
    //Функция поиска
    void browse();
    //void exit();
    //void ok();
};
#endif // MAINWINDOW_H
