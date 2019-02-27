import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

ColumnLayout {
    PEToolBar {
        Layout.fillWidth: true
        
        PEToolBarText {
            text: qsTr("Basic information")
        }
    }
    
    ScrollView {
        id: infoScrollView
        Layout.fillWidth: true
        Layout.fillHeight: true
        clip: true
        padding: 10
        
        Column {
            PEGroupBox {
                width: Math.max(130, infoScrollView.availableWidth)
                title: qsTr("ELF header")

                Column {
                    spacing: 10

                    PETermDefinition {
                        term: qsTr("<strong>Class</strong>")
                        definition: qsTr("64-bit")
                    }

                    PETermDefinition {
                        term: qsTr("<strong>Encoding</strong>")
                        definition: qsTr("Little Endian")
                    }

                    PETermDefinition {
                        term: qsTr("<strong>Architecture</strong>")
                        definition: qsTr("ARM")
                    }

                    PETermDefinition {
                        term: qsTr("<strong>Number of sections</strong>")
                        definition: qsTr("12")
                    }
                }
            }
        }
    }
}
