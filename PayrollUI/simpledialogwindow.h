#ifndef SIMPLEDIALOGWINDOW_H
#define SIMPLEDIALOGWINDOW_H

#include <QDialog>
#include <QtWidgets>

class SimpleDialogWindow : public QDialog
{
    Q_OBJECT
    friend class FileProgress;
    friend class ErrorWindow;
public:
    SimpleDialogWindow();
    ~SimpleDialogWindow();

public slots:
    void slotButtonClicked();
private:
    QString labelName = " ";
    QString windowTitle = " ";
    QLabel *label;
    QPushButton *okButton;
    QVBoxLayout *vlayout;

};


#endif // SIMPLEDIALOGWINDOW_H
