#include "mainwindow.h"
#include "staffwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    calculateButton = createButton("Рассчитать зарплату");
    exitButton = createButton("Выход");

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::slotCalculateButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::close);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(calculateButton);
    vlayout->addWidget(exitButton);
    setLayout(vlayout);
    setWindowTitle("Расчет зарплаты персонала");
    resize(300, 300);
}

QPushButton* MainWindow::createButton(const QString &str){
    QPushButton *pb= new QPushButton(str);
    pb->setMinimumSize(40, 40);
    return pb;
}


void MainWindow::slotCalculateButtonClicked(){
    this->close();
    StaffWindow *staffWindow = new StaffWindow();
    staffWindow->show();
}





MainWindow::~MainWindow()
{
}

