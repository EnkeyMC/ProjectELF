import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import projectelf.diagram 1.0

import "../singletons"
import "../controls"

ColumnLayout {
    id: diagramPane
    spacing: 0

    property alias elfModel: diagramScene.model

    PEToolBar {
        Layout.fillWidth: true
        
        PEToolBarText {
            text: qsTr("File structure")
        }
    }

    ScrollView {
        id: scroll
        Layout.fillWidth: true
        Layout.fillHeight: true
        clip: true
        ScrollBar.horizontal.snapMode: ScrollBar.SnapAlways
        ScrollBar.vertical.snapMode: ScrollBar.SnapAlways

        DiagramScene {
            id: diagramScene
            style: Style._DiagramStyle
            implicitWidth: Math.max(minWidth, scroll.availableWidth)
        }
    }
}
