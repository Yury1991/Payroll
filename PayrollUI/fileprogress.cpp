#include "fileprogress.h"

FileProgress::FileProgress()
{
    label = new QLabel(labelName);
    okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, this, &FileProgress::slotButtonClicked);
    vlayout = new QVBoxLayout;
    vlayout->addWidget(label);
    vlayout->addWidget(okButton);
    setMinimumSize(200, 100);
    setLayout(vlayout);
    setWindowTitle(windowTitle);
}


void FileProgress::slotButtonClicked(){
    this->close();
}

FileProgress::~FileProgress()
{

}

