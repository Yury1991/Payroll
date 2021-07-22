#include "mainwindow.h"
#include "staffwindow.h"
#include "receiverwindow.h"
#include "employeewindow.h"
#include "directorwindow.h"
#include "managerwindow.h"
#include "masterwindow.h"


StaffWindow::StaffWindow()
{
    employeeButton = createButton("Окладчик");
    receiverButton = createButton("Приемщики");
    directorButton = createButton("Директор");
    masterButton = createButton("Мастера");
    managerButton = createButton("Менеджеры");
    backButton = createButton("Назад");
    connect(employeeButton, &QPushButton::clicked, this, &StaffWindow::slotEmployeeButtonClicked);
    connect(receiverButton , &QPushButton::clicked, this, &StaffWindow::slotReceiverButtonClicked);
    connect(directorButton, &QPushButton::clicked, this, &StaffWindow::slotDirectorButtonClicked);
    connect(masterButton, &QPushButton::clicked, this, &StaffWindow::slotMasterButtonClicked);
    connect(managerButton, &QPushButton::clicked, this, &StaffWindow::slotManagerButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &StaffWindow::slotBackButtonClicked);


    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(staffLabel);
    vlayout->addWidget(employeeButton);
    vlayout->addWidget(receiverButton);
    vlayout->addWidget(directorButton);
    vlayout->addWidget(masterButton);
    vlayout->addWidget(managerButton);
    vlayout->addWidget(backButton);
    setLayout(vlayout);
    setWindowTitle("Окно персонала");
    setMinimumSize(450, 300);
}

QPushButton* StaffWindow::createButton(const QString &str){
    QPushButton *pb = new QPushButton(str);
    pb->setMinimumSize(40, 40);
    return pb;
}

void StaffWindow::slotEmployeeButtonClicked(){
    this->close();
    EmployeeWindow *employeeWindow = new EmployeeWindow();
    employeeWindow->show();
}

void StaffWindow::slotReceiverButtonClicked(){
    this->close();
    ReceiverWindow *receiverWindow = new ReceiverWindow();
    receiverWindow->show();
}

void StaffWindow::slotDirectorButtonClicked(){
    this->close();
    DirectorWindow *directorWindow = new DirectorWindow();
    directorWindow->show();
}
void StaffWindow::slotMasterButtonClicked(){
    this->close();
    MasterWindow *masterWindow = new MasterWindow();
    masterWindow->show();
}

void StaffWindow::slotManagerButtonClicked(){
    this->close();
    ManagerWindow *managerWindow = new ManagerWindow();
    managerWindow->show();
}
void StaffWindow::slotBackButtonClicked(){
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


StaffWindow::~StaffWindow(){

}
