import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtGraphicalEffects 1.0

import "components"

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("ProjectELF")

    menuBar: RowLayout {
        MainMenuBar {
            Layout.fillWidth: true
        }

        ViewSwitchButtons {
            id: viewSwitch
        }
    }

    footer: StatusBar {
        width: mainWindow.width
    }

    ColumnLayout {
        spacing: 0
        anchors.fill: parent

        TabBar {
            id: fileTabs
            position: TabBar.Header

            FileTabButton {
                text: qsTr("file1")
            }

            FileTabButton {
                text: qsTr("file2")
            }
        }

        StackLayout {
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
}
