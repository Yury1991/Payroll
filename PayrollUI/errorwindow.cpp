#include "errorwindow.h"

ErrorWindow::ErrorWindow()
{
    label = new QLabel(labelName);
    okButton = new QPushButton("ОК");
    vlayout = new QVBoxLayout;
    vlayout->addWidget(label);
    vlayout->addWidget(okButton);
    setLayout(vlayout);
    setWindowTitle(windowTitle);
}

void ErrorWindow::slotButtonClicked(){
    this->close();
}



ErrorWindow::~ErrorWindow(){

}
