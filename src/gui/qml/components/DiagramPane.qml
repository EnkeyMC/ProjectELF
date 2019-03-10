import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import projectelf.diagram 1.0

import "../singletons"
import "../controls"

ColumnLayout {
    id: diagramPane
    spacing: 0

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

        DiagramScene {
            model: DiagramModel {

            }
        }
    }
}
