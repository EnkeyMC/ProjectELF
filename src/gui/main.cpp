#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

#include <gui/diagram/DiagramScene.h>
#include "version.h"

void registerCustomQMLTypes() {
    qmlRegisterType<DiagramScene>("projectelf.diagram", 1, 0, "DiagramScene");
    qmlRegisterType<DiagramModel>("projectelf.diagram", 1, 0, "DiagramModel");
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
