import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

ColumnLayout {
    PEToolBar {
        Layout.fillWidth: true
        
        Text {
            leftPadding: 15
            anchors.fill: parent
            text: qsTr("File structure")
            verticalAlignment: Text.AlignVCenter
        }
    }
}
