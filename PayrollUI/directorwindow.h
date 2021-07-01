/*#ifndef DIRECTORWINDOW_H
#define DIRECTORWINDOW_H

#include "receiverwindow.h"

class ReceiverWindow;

class DirectorWindow : public ReceiverWindow
{
public:
    DirectorWindow(QWidget *parent = nullptr);
    ~DirectorWindow();
    QWidget *getWidget();
public slots:
    void slotCalculateButtonClicked();
    void slotBackButtonClicked();
private:
    QWidget *directorWidget;
    QGridLayout *directorLayout;
};

#endif // DIRECTORWINDOW_H

*/
