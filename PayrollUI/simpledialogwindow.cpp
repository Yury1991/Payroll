#include "simpledialogwindow.h"

SimpleDialogWindow::SimpleDialogWindow()
{

    label = new QLabel(labelName);
    okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, this, &SimpleDialogWindow::slotButtonClicked);
    vlayout = new QVBoxLayout;
    vlayout->addWidget(label);
    vlayout->addWidget(okButton);
    setMinimumSize(200, 100);
    setLayout(vlayout);
    setWindowTitle(windowTitle);
}

void SimpleDialogWindow::slotButtonClicked(){
    this->close();
}

SimpleDialogWindow::~SimpleDialogWindow(){

}
