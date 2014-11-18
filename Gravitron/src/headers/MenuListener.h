#ifndef MENULISTENER_H
#define MENULISTENER_H
#include <QObject>
#include <QString>
#include "GravitronSettings.h"

class MenuListener : public QObject
{
    Q_OBJECT

    public:
        MenuListener(QObject *parent = 0);
        MenuListener(GravitronSettings *settings, QObject *parent = 0);

    signals:
        void error(const QString& msg);

    public slots:
        void startSinglePlayerGame();

    private:
        GravitronSettings *settings;

};
#endif // MENULISTENER_H
