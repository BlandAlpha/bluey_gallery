#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QQuickWindow>
#include <QNetworkProxy>
#include <QSslConfiguration>
#include <QProcess>
#include <QtQml/qqmlextensionplugin.h>
#include <QLoggingCategory>

// #include <QSqlDataBase>

#include "src/component/FileWatcher.h"
#include "src/component/OpenGLItem.h"
#include "src/helper/SettingsHelper.h"
#include "src/helper/TranslateHelper.h"
#include "src/charactermodel.h"
#include "src/episodemodel.h"
#include "src/databasemanager.h"
#include "src/helper/pathhelper.h"

#ifdef FLUENTUI_BUILD_STATIC_LIB
#if (QT_VERSION > QT_VERSION_CHECK(6, 2, 0))
Q_IMPORT_QML_PLUGIN(FluentUIPlugin)
#endif
#include <FluentUI.h>
#endif

#ifdef WIN32
#include "src/app_dmp.h"
#endif

int main(int argc, char *argv[])
{
    const char *uri = "bluey_gallery";
    int major = 1;
    int minor = 0;
#ifdef WIN32
    ::SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
    qputenv("QT_QPA_PLATFORM","windows:darkmode=2");
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    qputenv("QT_QUICK_CONTROLS_STYLE","Basic");
#else
    qputenv("QT_QUICK_CONTROLS_STYLE","Default");
#endif
#ifdef Q_OS_LINUX
    //fix bug UOSv20 does not print logs
    qputenv("QT_LOGGING_RULES","");
    //fix bug UOSv20 v-sync does not work
    qputenv("QSG_RENDER_LOOP","basic");
#endif
    // QGuiApplication::setOrganizationName("Guoao Liu");
    // QGuiApplication::setOrganizationDomain("https://zhuzichu520.github.io");
    // QGuiApplication::setApplicationName("BlueyGallery");
    // QGuiApplication::setApplicationDisplayName("Bluey Gallery");
    QGuiApplication::setQuitOnLastWindowClosed(false);
    SettingsHelper::getInstance()->init(argv);
    PathHelper pathHelper;
    // Log::setup(argv,uri);
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
#endif
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
#endif
    QGuiApplication app(argc, argv);
    // qmlRegisterType<FileWatcher>(uri, major, minor, "FileWatcher");
    qmlRegisterType<CharacterModel>("Characters", 1, 0, "CharacterModel");
    qmlRegisterType<EpisodeModel>("Episodes", 1, 0, "EpisodeModel");
    qmlRegisterType<DatabaseManager>("DBManager", 1, 0, "DatabaseManager");
    QQmlApplicationEngine engine;
    TranslateHelper::getInstance()->init(&engine);
    engine.rootContext()->setContextProperty("SettingsHelper",SettingsHelper::getInstance());
    engine.rootContext()->setContextProperty("TranslateHelper",TranslateHelper::getInstance());
    engine.rootContext()->setContextProperty("PathHelper", &pathHelper);
#ifdef FLUENTUI_BUILD_STATIC_LIB
    FluentUI::getInstance()->registerTypes(&engine);
#endif
    const QUrl url(QStringLiteral("qrc:/App.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    const int exec = QGuiApplication::exec();
    if (exec == 931) {
        QProcess::startDetached(qApp->applicationFilePath(), qApp->arguments());
    }
    return exec;
}
