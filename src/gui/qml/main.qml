import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Dialogs 1.0

import projectelf.models 1.0

import "components"
import "singletons"
import "controls"

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 600
    title: "ProjectELF"

    FileDialog {
        id: openFileDialog
        title: qsTr("Open file")
        folder: shortcuts.home

        onAccepted: {
            openFilesModel.openFile(openFileDialog.fileUrl)
        }
    }

    OpenFilesModel {
        id: openFilesModel
    }

    menuBar: RowLayout {
        id: menuBarRow
        spacing: 0

        MainMenuBar {
            Layout.fillWidth: true

            MenuPrimary {
                title: qsTr("&File")
                Action {
                    text: qsTr("&Open...")
                    onTriggered: openFileDialog.open()
                }
                Action { text: qsTr("&Save") }
                Action { text: qsTr("Save &As...") }
                PEMenuSeparator {}
                Action {
                    text: qsTr("&Quit")
                    onTriggered: Qt.quit()
                }
            }

            MenuPrimary {
                title: qsTr("&Edit")
                Action { text: qsTr("Cu&t") }
                Action { text: qsTr("&Copy") }
                Action { text: qsTr("&Paste") }
            }
            MenuPrimary {
                title: qsTr("&Help")
                Action { text: qsTr("&About") }
                MenuPrimary {
                    title: "ASfgs"
                    Action { text: "AS" }
                }
            }
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

            Connections {
                target: openFilesModel
                onFileOpened: {
                    fileTabs.tabCreated(index);
                }
            }

            Repeater {
                model: openFilesModel

                PEClosableTabButton {
                    text: model.displayName + (model.changed ? "*" : "")

                    onCloseTab: {
                        fileTabs.tabClosed(index)
                        openFilesModel.closeFile(index)
                    }
                }
            }
        }

        StackLayout {
            id: tabs
            width: parent.width
            Layout.fillHeight: true
            Layout.fillWidth: true
            currentIndex: fileTabs.currentIndex

            Repeater {
                model: openFilesModel

                FilePane {
                    elfModel: model.elfModel
                }
            }
        }
    }

    background: Rectangle {
        color: Style._ColorPrimaryLight
    }
}
