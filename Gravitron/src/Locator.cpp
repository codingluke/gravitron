#include "headers/Locator.h"
#include <QTranslator>
#include <QLocale>
#include <QString>

/**
 * Construct a Locator object.
 * @param _settings The GravitronSettings.
 * @param _app The QGuiApplication.
 */
Locator::Locator(GravitronSettings& _settings, QGuiApplication& _app):settings(_settings),app(_app) {
    connect(&settings, SIGNAL(languageChanged(const QString&)), this, SLOT(loadLanguage(const QString&)));
    this->translator = new QTranslator();
}

/**
 * Destruct the Locator and deletes the translator.
 */
Locator::~Locator() {
    delete translator;
}

/**
 * Load the translations that match the given country code.s
 *
 * @param source The country code.
 */
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
