#include "mainwindow.h"
#include "staffwindow.h"
#include "receiverwindow.h"
#include "employeewindow.h"
//#include "directorwindow.h"


StaffWindow::StaffWindow()
{

    employeeButton = createButton("Окладчик");
    receiverButton = createButton("Приемщики");
    directorButton = createButton("Директор");
    masterButton = createButton("Мастера");
    managerButton = createButton("Менеджеры");
    backButton = createButton("Назад");


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
    connect(pb, &QPushButton::clicked, this, &StaffWindow::slotButtonClicked);
    setButtonName(pb->text());
    return pb;
}
QString *StaffWindow::getButtonName(){
    return buttonName;
}
void StaffWindow::setButtonName(QString buttonName){
    this->buttonName = &buttonName;
}


void StaffWindow::slotButtonClicked(){
    if(buttonName == (employeeButton->text())){
        EmployeeWindow *employeeWindow = new EmployeeWindow();
        employeeWindow->show();
    }
    else if(buttonName == receiverButton->text()){
        ReceiverWindow *receiverWindow = new ReceiverWindow();
        receiverWindow->show();
    }
    else{
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
    }
    this->close();
}





StaffWindow::~StaffWindow(){

}
