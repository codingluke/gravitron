
#ifndef LOCATER_H
#define LOCATER_H

#include "GravitronSettings.h"
#include <QObject>
#include <QGuiApplication>

class Locater : public QObject {

    Q_OBJECT

    private:
        GravitronSettings& settings;
        QGuiApplication& app;
        QTranslator *translator;

    public:
        Locater(GravitronSettings& settings, QGuiApplication& app);
        ~Locater();

    public slots:
        void loadLanguare(const QString& source);
};

#endif // LOCATER_H
