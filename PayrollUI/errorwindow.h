#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H
#include "simpledialogwindow.h"



class ErrorWindow : public SimpleDialogWindow
{
    Q_OBJECT
public:
    ErrorWindow();
    ~ErrorWindow();
public slots:
    void slotButtonClicked();
private:
    const QString labelName = "Ошибка";
    const QString windowTitle = "Ошибка";
};

#endif // ERRORWINDOW_H
