#include "headers/Locator.h"
#include <QTranslator>
#include <QLocale>
#include <QString>

Locator::Locator(GravitronSettings& _settings, QGuiApplication& _app):settings(_settings),app(_app) {
    connect(&settings, SIGNAL(languageChanged(const QString&)), this, SLOT(loadLanguage(const QString&)));
    this->translator = new QTranslator();
}

Locator::~Locator() {
    delete translator;
}

void Locator::loadLanguage(const QString& source) {
    QString locale = "gravitron_" + source;
    app.removeTranslator(translator);
    if(translator->load(locale, ":/translations")) {
        app.installTranslator(translator);
    } else {
        translator->load("gravitron_"+settings.language(), ":/translations");
        app.installTranslator(translator);
    }
}
