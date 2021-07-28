#include "logmessage.h"


LogMessage::LogMessage()
{

}

void LogMessage::messageToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg){
    QFile file("protocol.log");
    if(!file.open(QIODevice::WriteOnly| QIODevice::Text| QIODevice::Append))
        return;

    QString strDateTime = QDateTime::currentDateTime().toString("dd.MM.yy-hhL:mm");
    QTextStream out(&file);
    switch(type){
    case QtDebugMsg:
            out << strDateTime << "Debug: " << msg << ", " << context.file << Qt::endl;
        break;
    case QtWarningMsg:
            out << strDateTime << "Warning: " << msg << ", " << context.file << Qt::endl;
        break;
    case QtCriticalMsg:
        out << strDateTime << "Critical: " << msg << ", " << context.file << Qt::endl;
        break;
    case QtFatalMsg:
        out << strDateTime << "Fatal: " << msg << ", " << context.file << Qt::endl;
        abort();
    }
}

LogMessage::~LogMessage()
{

}
