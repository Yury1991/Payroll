#include "mainwindow.h"
#include "staffwindow.h"
#include "receiverwindow.h"
#include "employeewindow.h"
#include "director.h"


StaffWindow::StaffWindow()
{
    staffLabel = new QLabel("Список сотрудников:");
    employeeButton = createButton("Окладчик");
    receiverButton = createButton("Приемщики");
    directorButton = createButton("Директор");
    masterButton = createButton("Мастера");
    managerButton = createButton("Менеджеры");
    backButton = createButton("Назад");

    connect(receiverButton, &QPushButton::clicked, this, &StaffWindow::slotReceiverButtonClicked);
    connect(employeeButton, &QPushButton::clicked, this, &StaffWindow::slotEmployeeButtonClicked);
    connect(backButton, &QPushButton::clicked, this, &StaffWindow::slotBackButtonClicked);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(staffLabel);
    vlayout->addWidget(employeeButton);
    vlayout->addWidget(receiverButton);
    vlayout->addWidget(directorButton);
    vlayout->addWidget(managerButton);
    vlayout->addWidget(backButton);
    setLayout(vlayout);
    setWindowTitle("Окно персонала");
    setMinimumSize(400, 300);
}

QPushButton* StaffWindow::createButton(const QString &str){
    QPushButton *pb = new QPushButton(str);
    pb->setMinimumSize(40, 40);
    return pb;
}

void StaffWindow::slotReceiverButtonClicked(){
    this->close();
    ReceiverWindow *receiverWindow = new ReceiverWindow();
    receiverWindow->getWidget()->show();
}

void StaffWindow::slotEmployeeButtonClicked(){
    this->close();
    EmployeeWindow *employeeWindow = new EmployeeWindow();
    employeeWindow->getWidget()->show();
}

void StaffWindow::slotDirectorButtonClicked(){
    this->close();
    DirectorWindow *directorWindow = new  DirectorWindow();
    directorWindow->getWidget()->show();
}

void StaffWindow::slotBackButtonClicked(){
    this->close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

StaffWindow::~StaffWindow(){

}
