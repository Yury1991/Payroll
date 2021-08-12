#include "mainwindow.h"
#include "staffwindow.h"
#include "optionswindow.h"
#include "viewstaffwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    calculateButton = createButton("Рассчитать зарплату");
    viewButton = createButton("Просмотр зарплаты");
    settingsButton = createButton("Настройки");
    exitButton = createButton("Выход");

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::slotCalculateButtonClicked);
    connect(viewButton, &QPushButton::clicked, this, &MainWindow::slotViewButtonClicked);
    connect(settingsButton, &QPushButton::clicked, this, &MainWindow::slotSettingsButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::close);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(calculateButton);
    vlayout->addWidget(viewButton);
    vlayout->addWidget(settingsButton);
    vlayout->addWidget(exitButton);
    setLayout(vlayout);
    setWindowTitle("Расчет зарплаты персонала");
    resize(350, 100);
}

QPushButton* MainWindow::createButton(const QString &str){
    QPushButton *pb = new QPushButton(str);
    pb->setMinimumSize(40, 40);
    return pb;
}


void MainWindow::slotCalculateButtonClicked(){
    this->close();
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow->show();
}

void MainWindow::slotViewButtonClicked(){
    this->close();
    ViewStaffWindow *vsw = new ViewStaffWindow;
    vsw->show();
}



void MainWindow::slotSettingsButtonClicked(){
    this->close();
    OptionsWindow *optionsWindow = new OptionsWindow();
    optionsWindow->show();
}


MainWindow::~MainWindow()
{
}

