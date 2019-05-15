import QtQuick 2.11
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

    Item {
        id: frame
        Layout.fillWidth: true
        Layout.fillHeight: true

        DiagramScene {
            id: diagramScene
            anchors.fill: parent
            style: Style._DiagramStyle

            scrollXPosition: hbar.position
            scrollYPosition: vbar.position

            onWidthChanged: scrollXPositionChanged(scrollXPosition);
            onHeightChanged: scrollYPositionChanged(scrollYPosition);
        }

        ScrollBar {
            id: vbar
            hoverEnabled: true
            active: hovered || pressed || hbar.active
            orientation: Qt.Vertical
            size: frame.height / diagramScene.contentHeight
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            policy: frame.height > diagramScene.contentHeight ? ScrollBar.AlwaysOff : ScrollBar.AlwaysOn

            position: diagramScene.scrollYPosition
        }

        ScrollBar {
            id: hbar
            hoverEnabled: true
            active: hovered || pressed || hbar.active
            orientation: Qt.Horizontal
            size: frame.width / diagramScene.contentWidth
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            policy: frame.width > diagramScene.contentWidth ? ScrollBar.AlwaysOff : ScrollBar.AlwaysOn

            position: diagramScene.scrollXPosition
        }
    }
}
