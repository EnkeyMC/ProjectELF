import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

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
}
