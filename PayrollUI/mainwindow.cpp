#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    calculateButton = createButton("Рассчитать зарплату");
    exitButton = createButton("Выход");

    connect(calculateButton, SIGNAL(clicked()), this, SLOT(slotCalculateButtonClicked()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(calculateButton);
    vlayout->addWidget(exitButton);
    setLayout(vlayout);
    resize(300, 300);
}

QPushButton* MainWindow::createButton(const QString &str){
    QPushButton *pb= new QPushButton(str);
    pb->setMinimumSize(40, 40);
    return pb;
}


void MainWindow::slotCalculateButtonClicked(){
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow->show();
}





MainWindow::~MainWindow()
{
}

