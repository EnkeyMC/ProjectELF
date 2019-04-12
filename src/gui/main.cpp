#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

#include "gui/diagram/DiagramScene.h"
#include "version.h"
#include "core/models/ELFModel.h"
#include "core/models/OpenFilesModel.h"
#include "core/models/ELFHeaderModelItem.h"
#include "core/models/ELFProgramHeaderTableModelItem.h"
#include "core/models/ELFSectionHeaderTableModelItem.h"
#include "core/models/ELFProgramHeaderModelItem.h"
#include "core/models/ELFSectionHeaderModelItem.h"
#include "core/models/ELFSectionModelItem.h"
#include "core/models/ELFSegmentModelItem.h"

#define UNCREATABLE_MSG "This type is not creatable in QML."
#define NMSPC_DIAGRAM "projectelf.diagram"
#define NMSPC_MODELS "projectelf.models"

void registerCustomQMLTypes() {
    qmlRegisterType<DiagramScene>(NMSPC_DIAGRAM, 1, 0, "DiagramScene");
    qmlRegisterType<ELFModel>(NMSPC_MODELS, 1, 0, "ELFModel");

    qmlRegisterUncreatableType<ELFHeaderModelItem>
            (NMSPC_MODELS, 1, 0, "ELFHeaderModelItem", UNCREATABLE_MSG);
    qmlRegisterUncreatableType<ELFProgramHeaderTableModelItem>
            (NMSPC_MODELS, 1, 0, "ELFProgramHeaderTableModelItem", UNCREATABLE_MSG);
    qmlRegisterUncreatableType<ELFSectionHeaderTableModelItem>
            (NMSPC_MODELS, 1, 0, "ELFSectionHeaderTableModelItem", UNCREATABLE_MSG);
    qmlRegisterUncreatableType<ELFProgramHeaderModelItem>
            (NMSPC_MODELS, 1, 0, "ELFProgramHeaderModelItem", UNCREATABLE_MSG);
    qmlRegisterUncreatableType<ELFSectionHeaderModelItem>
            (NMSPC_MODELS, 1, 0, "ELFSectionHeaderModelItem", UNCREATABLE_MSG);
    qmlRegisterUncreatableType<ELFSectionModelItem>
            (NMSPC_MODELS, 1, 0, "ELFSectionModelItem", UNCREATABLE_MSG);
    qmlRegisterUncreatableType<ELFSegmentModelItem>
            (NMSPC_MODELS, 1, 0, "ELFSegmentModelItem", UNCREATABLE_MSG);

    qmlRegisterType<OpenFilesModel>(NMSPC_MODELS, 1, 0, "OpenFilesModel");
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
