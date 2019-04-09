import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

PESplitView {
    id: viewEdit
    orientation: Qt.Horizontal

    property QtObject elfModel

    ColumnLayout {
        id: elfHeaderColumn
        Layout.fillHeight: true
        width: 250
        spacing: 0

        PEToolBar {
            Layout.fillWidth: true

            PEToolBarText {
                text: qsTr("ELF Header")
            }
        }

        ScrollView {
            id: scroll
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            PEExpandablePane {
                title: "Expandable"
                width: Math.max(150, scroll.availableWidth)

                PETable {
                    id: table
                    columns: 2
                    width: parent.width

                    PETableHeader {
                        text: "Key"
                    }

                    PETableHeader {
                        text: "Value"
                    }

                    PETableCell {
                        Text {
                            text: "Key1"
                        }
                    }

                    PETableEditableCell {
                        placeholderText: "editable cell"
                    }

                    PETableCell {
                        Text {
                            text: "Key2"
                        }
                    }

                    PETableEditableCell {
                        placeholderText: "editable cell"
                    }
                }
            }
        }
    }

    ColumnLayout {
        id: sectionHeaderColumn
        Layout.fillHeight: true
        width: 250

        PEToolBar {
            Layout.fillWidth: true

            PEToolBarText {
                text: "Section header"
            }
        }
    }

    ColumnLayout {
        id: sectionsColumn
        Layout.fillHeight: true
        Layout.fillWidth: true

        PEToolBar {
            Layout.fillWidth: true

            PEToolBarText {
                text: "Sections"
            }
        }
    }
}
