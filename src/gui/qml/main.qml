import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Dialogs 1.3 as Dialogs

import projectelf.models 1.0

import "components"
import "singletons"
import "controls"

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 600
    minimumWidth: 600
    minimumHeight: 480
    title: "ProjectELF"

    Dialogs.FileDialog {
        id: openFileDialog
        title: qsTr("Open file")
        folder: shortcuts.home

        onAccepted: {
            openFilesModel.openFile(openFileDialog.fileUrl)
        }
    }

    Dialogs.FileDialog {
        id: saveFileDialog
        title: qsTr("Save As")
        folder: shortcuts.home
        selectExisting: false

        onAccepted: {
           openFilesModel.saveFileAs(fileTabs.currentIndex, fileUrl)
        }
    }

    Dialogs.MessageDialog {
        id: errorDialog
        icon: Dialogs.StandardIcon.Critical
        standardButtons: Dialogs.StandardButton.Ok
    }

    OpenFilesModel {
        id: openFilesModel
        onError: {
            errorDialog.title = title;
            errorDialog.text = description;
            errorDialog.open();
        }
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
                Action {
                    text: qsTr("&Save")
                    onTriggered: openFilesModel.saveFile(fileTabs.currentIndex)
                }
                Action {
                    text: qsTr("Save &As...")
                    onTriggered: saveFileDialog.open()
                }
                PEMenuSeparator {}
                Action {
                    text: qsTr("&Quit")
                    onTriggered: Qt.quit()
                }
            }

            MenuPrimary {
                title: qsTr("&Help")
                Action { text: qsTr("&About") }
            }
        }

        ViewSwitchButtons {
            Layout.fillHeight: true
            id: viewSwitch
        }
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
