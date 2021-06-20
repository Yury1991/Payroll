#include "staffwindow.h"
#include "receiverwindow.h"


StaffWindow::StaffWindow()
{
    staffLabel = new QLabel("Список сотрудников:");
    employeeButton = createButton("Окладчик");
    receiverButton = createButton("Приемщики");
    directorButton = createButton("Директор");
    masterButton = createButton("Мастера");
    managerButton = createButton("Менеджеры");


    connect(receiverButton, SIGNAL(clicked()), this, SLOT(slotReceiverButtonClicked()));


    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(staffLabel);
    vlayout->addWidget(employeeButton);
    vlayout->addWidget(receiverButton);
    vlayout->addWidget(directorButton);
    vlayout->addWidget(managerButton);
    setLayout(vlayout);
    setMinimumSize(400, 300);

}

QPushButton* StaffWindow::createButton(const QString &str){
    QPushButton *pb= new QPushButton(str);
    pb->setMinimumSize(40, 40);
    return pb;
}

void StaffWindow::slotReceiverButtonClicked(){
    ReceiverWindow *receiverWindow = new ReceiverWindow();
    receiverWindow->show();
}

StaffWindow::~StaffWindow(){

}
