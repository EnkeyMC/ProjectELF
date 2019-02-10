import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("ProjectELF")

    menuBar: RowLayout {
        MenuBar {
            Layout.fillWidth: true

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

        ButtonGroup {
            buttons: btns.children
        }

        RowLayout {
            id: btns

            RadioButton {
                text: qsTr("View")
                checked: true
            }

            RadioButton {
                text: qsTr("Edit")
            }
        }
    }

    footer: Rectangle {
        color: "#cccccc"
        width: mainWindow.width
        height: 30

        Behavior on color { PropertyAnimation{} }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onHoveredChanged: parent.color = "#222222"
        }
    }

    ColumnLayout {
        anchors.fill: parent

        TabBar {
            id: fileTabs

            TabButton {
                text: qsTr("file1")
            }

            TabButton {
                text: qsTr("file2")
            }
        }

        StackLayout {
            width: parent.width
            Layout.fillHeight: true
            Layout.fillWidth: true
            currentIndex: fileTabs.currentIndex

            Item {
                id: fileTab
                Text {
                    id: text1
                    text: qsTr("longer longer longer longer longer longer longer text")
                }
            }

            Item {
                id: file2Tab
            }
        }
    }
}
