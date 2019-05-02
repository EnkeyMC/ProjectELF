import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PESplitView {
    id: viewEdit
    orientation: Qt.Horizontal

    property ELFModel elfModel

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

            HeaderEditTable {
                id: headerEditTable
                headerModel: elfModel.header
                width: Math.max(150, scroll.availableWidth)
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
