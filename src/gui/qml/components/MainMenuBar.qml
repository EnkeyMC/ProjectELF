import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"

MenuBar {    
    Menu {
        title: qsTr("&File")
        Action { text: qsTr("&Open...") }
        Action { text: qsTr("&Save") }
        Action { text: qsTr("Save &As...") }
        MenuSeparator { }
        Action { text: qsTr("&Quit") }
    }
    Menu {
        title: qsTr("&Edit")
        Action { text: qsTr("Cu&t") }
        Action { text: qsTr("&Copy") }
        Action { text: qsTr("&Paste") }
    }
    Menu {
        title: qsTr("&Help")
        Action { text: qsTr("&About") }
    }

    background: Rectangle {
        color: Style._ColorPrimaryDark
    }

    delegate: MenuBarItem {
        id: menuBarItem

        contentItem: Text {
            text: menuBarItem.text
            opacity: enabled ? 1.0 : 0.3
            color: "white"
            verticalAlignment: Text.AlignVCenter
        }
    }
}
