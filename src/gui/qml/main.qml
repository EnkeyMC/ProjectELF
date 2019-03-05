import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "components"
import "singletons"
import "controls"

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("ProjectELF")

    menuBar: RowLayout {
        id: menuBarRow
        spacing: 0

        MainMenuBar {
            Layout.fillWidth: true
        }

        ViewSwitchButtons {
            Layout.fillHeight: true
            id: viewSwitch
        }
    }

    footer: StatusBar {
        width: mainWindow.width
    }

    ColumnLayout {
        id: mainView
        spacing: 0
        anchors.fill: parent

        PETabBar {
            id: fileTabs
            Layout.fillWidth: true

            PEClosableTabButton {
                text: qsTr("file1fdsfdsafdasf")
            }

            PEClosableTabButton {
                text: qsTr("file2")
            }

            PEClosableTabButton {
                text: qsTr("file3")
            }
        }

        StackLayout {
            id: tabs
            width: parent.width
            Layout.fillHeight: true
            Layout.fillWidth: true
            currentIndex: fileTabs.currentIndex

            FilePane {
            }

            FilePane {
            }
        }
    }

    background: Rectangle {
        color: Style._ColorPrimaryLight
    }
}
