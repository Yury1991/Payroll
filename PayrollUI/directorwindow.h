#ifndef DIRECTORWINDOW_H
#define DIRECTORWINDOW_H

#include "receiverwindow.h"

class Director;

class DirectorWindow : public ReceiverWindow
{
public:
    DirectorWindow(QWidget *parent = nullptr);
    ~DirectorWindow();
    QWidget *getWidget();
public slots:
    void slotCalculateButtonClicked() override;
    void slotBackButtonClicked() override;
//    void slotWriteButtonClicked() override;
private:
    QLabel *directorFeeLabel;
    QLabel *directorFeeValueLabel;

    Director *director;
    //Компоновка окна
    QHBoxLayout *directorFeeLayout;
    //Вектор горизонтальных слоев
    QVector< QHBoxLayout*> directorLayouts;
    QGridLayout *directorLayout;

    //Виджет
    QWidget *directorWidget;
};

#endif // DIRECTORWINDOW_H


