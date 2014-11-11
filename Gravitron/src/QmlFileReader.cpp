#include "headers/QmlFileReader.h"
#include <QFile>
#include <QTextStream>

QMLFileReader::QMLFileReader(QObject *parent) :
    QObject(parent)
{

}

QString QMLFileReader::read()
{
    QString fileContent;
    if (mSource.isEmpty()){
        emit error("source is empty");
        fileContent = QString();
    } else {
        QFile file(mSource);

        if ( file.open(QIODevice::ReadOnly) ) {
            QString line;
            QTextStream t( &file );
            do {
                line = t.readLine();
                fileContent += line;
             } while (!line.isNull());

            file.close();
        } else {
            emit error("Unable to open the file");
            fileContent = QString();
        }
    }
    return fileContent;
}

/*bool QMLFileReader::write(const QString& data)
{
    if (mSource.isEmpty())
        return false;

    QFile file(mSource);
    if (!file.open(QFile::WriteOnly | QFile::Truncate))
        return false;

    QTextStream out(&file);
    out << data;

    file.close();

    return true;
}*/
