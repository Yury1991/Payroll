#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QtGlobal>
#include <QFile>
#include <QDate>
#include <QTextStream>


class LogMessage
{
public:
    LogMessage();
    ~LogMessage();

    void messageToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg);
/*private:
    QFile file;
    QString strDateTime;
  */

};

#endif // LOGMESSAGE_H
