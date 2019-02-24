import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

Rectangle {
    color: Style._ColorPrimaryDark
    width: 200
    height: Style.mainMenuBar._Height


    RowLayout {
        id: btns
        anchors.fill: parent
        spacing: 0

        PEButton {
            Layout.fillWidth: true
            text: qsTr("Overview")
            checkable: true
            checked: true
            autoExclusive: true

            onClicked: View.currentView = View._ViewOverview
        }

        PEButton {
            Layout.fillWidth: true
            text: qsTr("Edit")
            checkable: true
            autoExclusive: true

            onClicked: View.currentView = View._ViewEdit
        }
    }
}

