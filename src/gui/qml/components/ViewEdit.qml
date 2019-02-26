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
        spacing: 0

        PEToolBar {
            Layout.fillWidth: true

            Text {
                text: qsTr("ELF Header")
                verticalAlignment: Text.AlignVCenter
            }
        }

        ScrollView {
            id: scroll
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            PETable {
                id: table
                width: Math.max(150, scroll.availableWidth)
                columns: 2

                PETableHeader {
                    text: "text"
                }

                PETableHeader {
                    text: "header"
                }

                PETableCell {
                    Text {
                        text: "Preettteeyy"
                    }
                }

                PETableEditableCell {
                    placeholderText: "editable cell"
                }

                PETableCell {
                    Text {
                        text: "llooongg"
                    }
                }

                PETableEditableCell {
                    placeholderText: "editable cell"
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
