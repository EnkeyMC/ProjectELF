import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"

RowLayout {
    id: btns

    Button {
        text: qsTr("Overview")
        checkable: true
        checked: true
        autoExclusive: true

        onClicked: View.currentView = View._ViewOverview
    }

    Button {
        text: qsTr("Edit")
        checkable: true
        autoExclusive: true

        onClicked: View.currentView = View._ViewEdit
    }
}

