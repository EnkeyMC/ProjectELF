#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

#include <gui/diagram/DiagramScene.h>
#include "version.h"
#include "core/models/ELFModel.h"
#include "core/models/OpenFilesModel.h"
#include "core/models/ELFHeaderModelItem.h"

void registerCustomQMLTypes() {
    qmlRegisterType<DiagramScene>("projectelf.diagram", 1, 0, "DiagramScene");

    qmlRegisterType<ELFModel>("projectelf.models", 1, 0, "ELFModel");
    qmlRegisterUncreatableType<ELFHeaderModelItem>("project.models", 1, 0, "ELFHeaderModelItem",
                                                   "This type is not creatable in QML.");
    qmlRegisterType<OpenFilesModel>("projectelf.models", 1, 0, "OpenFilesModel");
}

int main(int argc, char *argv[])
{
    if (argc == 2 && std::string(argv[1]) == "-v") {
        std::cout << "Version: " << Version::toString() << std::endl;
        return EXIT_SUCCESS;
    }

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    registerCustomQMLTypes();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return EXIT_FAILURE;

    return app.exec();
}
