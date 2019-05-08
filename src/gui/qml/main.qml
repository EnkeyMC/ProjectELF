import QtQuick 2.11
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

    onClosing: {
        if (openFilesModel.hasUnsavedChanges()) {
            close.accepted = false;
            closeWithUnsavedChangesDialog.open();
        }
    }

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

    Dialogs.MessageDialog {
        id: saveBeforeCloseDialog
        icon: Dialogs.StandardIcon.Warning
        title: qsTr("Save changes")
        text: qsTr("File you are trying to close has unsaved chagnes. Do you wish to save them?")
        standardButtons: Dialogs.StandardButton.Save | Dialogs.StandardButton.Discard | Dialogs.StandardButton.Cancel

        property int indexToClose

        onAccepted: {
            openFilesModel.saveFile(indexToClose);
            fileTabs.tabClosed(indexToClose)
            openFilesModel.closeFile(indexToClose);
        }

        onDiscard: {
            fileTabs.tabClosed(indexToClose)
            openFilesModel.closeFile(indexToClose);
        }
    }

    Dialogs.MessageDialog {
        id: closeWithUnsavedChangesDialog
        icon: Dialogs.StandardIcon.Warning
        title: qsTr("Discard unsaved changes")
        text: qsTr("You have open files with unsaved changes. Do you really wish to quit without saving?")
        standardButtons: Dialogs.StandardButton.Yes | Dialogs.StandardButton.No

        onYes: Qt.quit();
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
                    enabled: openFilesModel.size > 0
                }
                Action {
                    text: qsTr("Save &As...")
                    onTriggered: saveFileDialog.open()
                    enabled: openFilesModel.size > 0
                }
                PEMenuSeparator {}
                Action {
                    text: qsTr("&Quit")
                    onTriggered: mainWindow.close()
                }
            }

            MenuPrimary {
                title: qsTr("&Help")
                Action { text: qsTr("&About") }
            }
        }

        PEButton {
            text: qsTr("Reload structure")
            enabled: openFilesModel.size > 0

            onClicked: {
                openFilesModel.reloadStructure(fileTabs.currentIndex)
            }
        }

        Rectangle {
            width: 11
            Layout.fillHeight: true
            color: Style._ColorPrimaryDark

            Rectangle {
                x: 5
                width: 1
                y: 5
                height: parent.height - 10
                color: Qt.darker(Style._ColorAccent, 1.1)
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
                    text: model.displayName + (changed ? "*" : "")
                    property bool changed: model.changed

                    onCloseTab: {
                        if (changed) {
                            saveBeforeCloseDialog.indexToClose = index
                            saveBeforeCloseDialog.open();
                        }
                        else {
                            fileTabs.tabClosed(index)
                            openFilesModel.closeFile(index)
                        }
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
