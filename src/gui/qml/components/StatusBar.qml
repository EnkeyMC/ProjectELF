import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"

Rectangle {
    id: statusBar
    color: Style._ColorPrimaryDark
    height: Style.statusBar._Height

    RowLayout {
        anchors.fill: parent

        Item {
            width: 5
        }

        PEProgressBar {
            height: parent.height
            indeterminate: true
        }

        Text {
            Layout.leftMargin: 5
            Layout.fillHeight: true
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Loading...")
        }

        Item {
            Layout.fillWidth: true
        }

        Text {
            Layout.fillHeight: true
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Errors")
        }

        Item {
            width: 5
        }
    }
}
