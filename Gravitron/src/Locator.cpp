#include "headers/Locater.h"
#include <QTranslator>
#include <QLocale>
#include <QString>

Locater::Locater(GravitronSettings& _settings, QGuiApplication& _app):settings(_settings),app(_app) {
    connect(&settings, SIGNAL(languareChanged(const QString&)), this, SLOT(loadLanguare(const QString&)));
    this->translator = new QTranslator();
}

Locater::~Locater() {
    delete translator;
}

void Locater::loadLanguare(const QString& source) {
    QString locale = "gravitron_" + source;
    app.removeTranslator(translator);
    if(translator->load(locale, ":/translations")) {
        app.installTranslator(translator);
    } else {
        //qWarning() << "No languare for your loaction.";
        translator->load("gravitron_"+settings.languare(), ":/translations");
        app.installTranslator(translator);
    }
}
