#include "mainwindow.h"
#include "viewstaffwindow.h"
#include "receiverwindow.h"
#include "employeewindow.h"
#include "directorwindow.h"
#include "managerwindow.h"
#include "masterwindow.h"


ViewStaffWindow::ViewStaffWindow()
{
    employeeButton = createButton("Окладчик");
    receiverButton = createButton("Приемщики");
    directorButton = createButton("Директор");
    masterButton = createButton("Мастера");
    managerButton = createButton("Менеджеры");
    backButton = createButton("Назад");
    connect(employeeButton, &QPushButton::clicked, this, &ViewStaffWindow::slotEmployeeButtonClicked);
    connect(receiverButton , &QPushButton::clicked, this, &ViewStaffWindow::slotReceiverButtonClicked);
    connect(directorButton, &QPushButton::clicked, this, &ViewStaffWindow::slotDirectorButtonClicked);
    connect(masterButton, &QPushButton::clicked, this, &ViewStaffWindow::slotMasterButtonClicked);
    connect(managerButton, &QPushButton::clicked, this, &ViewStaffWindow::slotManagerButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &ViewStaffWindow::slotBackButtonClicked);


    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(staffLabel);
    vlayout->addWidget(employeeButton);
    vlayout->addWidget(receiverButton);
    vlayout->addWidget(directorButton);
    vlayout->addWidget(masterButton);
    vlayout->addWidget(managerButton);
    vlayout->addWidget(backButton);
    setLayout(vlayout);
    setWindowTitle("Окно персонала для просмотра");
    setMinimumSize(450, 300);
}

QPushButton* ViewStaffWindow::createButton(const QString &str){
    QPushButton *pb = new QPushButton(str);
    pb->setMinimumSize(40, 40);
    return pb;
}

void ViewStaffWindow::slotEmployeeButtonClicked(){
    this->close();
    EmployeeWindow *employeeWindow = new EmployeeWindow();
    employeeWindow->show();
}

void ViewStaffWindow::slotReceiverButtonClicked(){
    this->close();
    ReceiverWindow *receiverWindow = new ReceiverWindow();
    receiverWindow->show();
}

void ViewStaffWindow::slotDirectorButtonClicked(){
    this->close();
    DirectorWindow *directorWindow = new DirectorWindow();
    directorWindow->show();
}
void ViewStaffWindow::slotMasterButtonClicked(){
    this->close();
    MasterWindow *masterWindow = new MasterWindow();
    masterWindow->show();
}

void ViewStaffWindow::slotManagerButtonClicked(){
    this->close();
    ManagerWindow *managerWindow = new ManagerWindow();
    managerWindow->show();
}
void ViewStaffWindow::slotBackButtonClicked(){
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


ViewStaffWindow::~ViewStaffWindow(){

}
