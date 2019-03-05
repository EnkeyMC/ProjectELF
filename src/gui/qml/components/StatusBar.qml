import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

Rectangle {
    id: statusBar
    color: Style._ColorPrimaryDark
    height: Style.statusBar._Height

    RowLayout {
        anchors.fill: parent

        Spacer {
            width: 5
        }

        PEProgressBar {
            height: parent.height
            indeterminate: true
        }

        StatusBarText {
            Layout.leftMargin: 5
            Layout.fillHeight: true
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Loading...")
        }

        Spacer {
            Layout.fillWidth: true
        }

        StatusBarText {
            Layout.fillHeight: true
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Errors")
        }

        Spacer {
            width: 5
        }
    }
}
