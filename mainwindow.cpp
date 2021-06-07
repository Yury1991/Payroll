#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    //Установка элементов:
    browseButton = new QPushButton("&Загрузить");
    okButton = new QPushButton("&Ок");
    exitButton = new QPushButton("&Выход");
    //pathComboBox = createComboBox(QDir::currentPath());
    directoryLabel = new QLabel(tr("Путь:"));
    //directoryComboBox = new QComboBox;
    directoryComboBox = createComboBox(QDir::currentPath());
    //Компоновка элементов
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout -> addStretch();
    buttonsLayout -> addWidget(exitButton);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(directoryLabel, 2, 0);
    mainLayout->addWidget(directoryComboBox, 2, 1);
    mainLayout->addWidget(browseButton);
    mainLayout->addWidget(okButton);
    mainLayout->addLayout(buttonsLayout, 5, 0, 1, 3);
    setLayout(mainLayout);

    setWindowTitle(tr("Загрузка данных:"));
    resize(400, 300);

}

void MainWindow::browse()
 {
     QString directory = QFileDialog::getExistingDirectory(this,
                                tr("Browse"), QDir::currentPath());
 }


//Компоновка
/*MainWindow::~MainWindow()
{

}*/

