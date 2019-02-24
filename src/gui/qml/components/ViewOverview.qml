import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4 as QQC1
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

QQC1.SplitView {
    orientation: Qt.Horizontal

    ColumnLayout {
        width: 200
        Layout.minimumWidth: 150

        PEToolBar {
            Layout.fillWidth: true

            Text {
                leftPadding: 15
                anchors.fill: parent
                text: qsTr("Basic information")
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

    ColumnLayout {
        Layout.fillWidth: true
        Layout.minimumWidth: 200

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

    handleDelegate: Rectangle {
        color: Style._ColorSecondaryLight
        width: 3
    }
}
