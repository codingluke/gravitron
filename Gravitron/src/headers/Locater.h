
#ifndef LOCATOR_H
#define LOCATOR_H

#include "GravitronSettings.h"
#include <QObject>
#include <QGuiApplication>

class Locator : public QObject {

    Q_OBJECT

    private:
        GravitronSettings& settings;
        QGuiApplication& app;
        QTranslator *translator;

    public:
        Locator(GravitronSettings& settings, QGuiApplication& app);
        ~Locator();

    public slots:
        void loadLanguage(const QString& source);
};

#endif // LOCATOR_H
