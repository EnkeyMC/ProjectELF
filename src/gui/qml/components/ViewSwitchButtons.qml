import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

Rectangle {
    id: viewSwitchButtons
    color: Style._ColorPrimaryDark
    width: 200
    height: Style.mainMenuBar._Height


    RowLayout {
        id: btns
        anchors.fill: parent
        spacing: 0

        PEButton {
            id: btnOverview
            Layout.fillWidth: true
            text: qsTr("Overview")
            checkable: true
            checked: View.currentView == View._ViewOverview
            autoExclusive: true

            onClicked: View.currentView = View._ViewOverview
        }

        PEButton {
            id: btnEdit
            Layout.fillWidth: true
            text: qsTr("Edit")
            checkable: true
            checked: View.currentView == View._ViewEdit
            autoExclusive: true

            onClicked: View.currentView = View._ViewEdit
        }
    }
}

