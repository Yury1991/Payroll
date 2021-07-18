#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialog>
#include <QtWidgets>

class OptionsWindow : public QDialog
{
    Q_OBJECT
public:
    OptionsWindow();
    ~OptionsWindow();
public slots:
    void slotChangePathButtonClicked();
    void slotBackButtonClicked();
private:

    QString path;
    QLabel *currentPathLabel;
    QLabel *pathLabel;
    QPushButton *changePathButton;
    QPushButton *backButton;
    QHBoxLayout *hlayout_1;
    QHBoxLayout *hlayout_2;
    QHBoxLayout *hlayout_3;
    QGridLayout *mainLayout;

};

#endif // OPTIONSWINDOW_H
