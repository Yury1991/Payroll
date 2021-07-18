#include "optionswindow.h"
#include "mainwindow.h"

OptionsWindow::OptionsWindow()
{
    currentPathLabel = new QLabel("Текущий путь: ");
    pathLabel = new QLabel(QCoreApplication::applicationDirPath());
    changePathButton = new QPushButton("Изменить");
    backButton = new QPushButton("Назад");
    connect(changePathButton, &QPushButton::clicked, this, &OptionsWindow::slotChangePathButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &OptionsWindow::slotBackButtonClicked);
    hlayout_1 = new QHBoxLayout;
    hlayout_1->addWidget(currentPathLabel);
    hlayout_1->addWidget(pathLabel);
    hlayout_2 = new QHBoxLayout;
    hlayout_2->addWidget(changePathButton);
    hlayout_3 = new QHBoxLayout;
    hlayout_3->addWidget(backButton);
    mainLayout = new QGridLayout;
    mainLayout->addLayout(hlayout_1, 0, 0);
    mainLayout->addLayout(hlayout_2, 1, 0);
    mainLayout->addLayout(hlayout_3, 2, 0);
    setLayout(mainLayout);
    setWindowTitle("Наcтройки");
    setMinimumSize(250, 200);
}

void OptionsWindow::slotBackButtonClicked(){
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void OptionsWindow::slotChangePathButtonClicked(){
//    QApplication::processEvents();
    QString str = QFileDialog::getExistingDirectory(0, "Select a Directory", pathLabel->text());

    if(!str.isEmpty()){
        pathLabel->setText(str);
        path = str;                 //сохранение пути для  отчетов
    }
}


OptionsWindow::~OptionsWindow()
{

}
