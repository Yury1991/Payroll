#ifndef FILEPROGRESS_H
#define FILEPROGRESS_H
#include "simpledialogwindow.h"

class FileProgress : public SimpleDialogWindow
{
    Q_OBJECT
public:
    FileProgress();
    ~FileProgress();

public slots:
    void slotButtonClicked();
private:
  const QString labelName = "Запись добавлена в файл";
  const QString windowTitle = "Успешно";

};

#endif // FILEPROGRESS_H
