import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Rectangle {
    id: statusBar
    color: "#cccccc"
    height: 20

    RowLayout {
        anchors.fill: parent

        Item {
            width: 5
        }

        ProgressBar {
            height: statusBar.height
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
