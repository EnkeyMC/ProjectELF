import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

ColumnLayout {
    id: diagramPane

    PEToolBar {
        Layout.fillWidth: true
        
        PEToolBarText {
            text: qsTr("File structure")
        }
    }
}
