#include "mainwindow.h"

#include <QApplication>
#include <QLibraryInfo>
#include <QLocale>
#include <QSettings>
#include <QTranslator>
#include <qapplication.h>
#include <qlogging.h>

#include "utils/misc.h"

/**
 * Function for loading a translation with debug output
 */
void loadTranslation(QTranslator&   translator,
                     const QString& fileName,
                     const QString& directory = QString()) {
  bool isLoaded    = translator.load(fileName, directory);
  bool isInstalled = QCoreApplication::installTranslator(&translator);
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString& locale : uiLanguages) {
    const QString baseName = "QOwnTodolist_" + QLocale(locale).name();
    if (translator.load(":/i18n/" + baseName)) {
      qApp->installTranslator(&translator);
      break;
    }
  }
  qDebug() << "Translation " << fileName << "in" << directory
           << "isLoaded:" << isLoaded << ", isInstalled:" << isInstalled;
}
int main(int argc, char* argv[]) {
  bool      allowOnlyOneAppInstance = true;
  QSettings settings;
  QSettings::setDefaultFormat(QSettings::IniFormat);

  // if allowOnlyOneAppInstance still has the default true let's ask the
  // settings
  if (allowOnlyOneAppInstance) {
    allowOnlyOneAppInstance =
        settings.value(QStringLiteral("allowOnlyOneAppInstance"), true)
            .toBool();
  }
  if (allowOnlyOneAppInstance && true /*!SingleApplication::isSupported()*/) {
    allowOnlyOneAppInstance = false;
    settings.setValue(QStringLiteral("allowOnlyOneAppInstance"), false);

    qWarning() << QCoreApplication::translate(
        "main", "Single application mode is not supported on your "
                "system!");
  }

  QApplication a(argc, argv);

  QTranslator translator;
  QString     locale =
      settings.value(QStringLiteral("interfaceLanguage")).toString();
  if (locale.isEmpty()) {
    locale = QLocale::system().name().section('_', 0, 0);
  }
  qDebug() << __func__ << " - 'locale': " << locale;

  loadTranslation(translator, locale);

  qDebug() << "Current locale: " << QLocale::system().name();

  MainWindow w;
  w.show();
  return a.exec();
}
