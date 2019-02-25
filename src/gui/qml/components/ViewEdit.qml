import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

PESplitView {
    orientation: Qt.Horizontal

    ColumnLayout {
        Layout.fillHeight: true
        width: 250

        PEToolBar {
            Layout.fillWidth: true

            Text {
                text: qsTr("ELF Header")
                verticalAlignment: Text.AlignVCenter
            }
        }

        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout {
                spacing: 1

                RowLayout {
                    Rectangle {
                        color: Style._ColorSecondaryDark

                        Text {
                            text: qsTr("text")
                            color: Style._ColorTextLight
                        }
                    }
                }
            }
        }
    }

    ColumnLayout {
        Layout.fillHeight: true
        width: 250

        PEToolBar {
            Layout.fillWidth: true

            Text {
                text: "Section header"
            }
        }
    }

    ColumnLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true

        PEToolBar {
            Layout.fillWidth: true

            Text {
                text: "Sections"
            }
        }
    }
}
