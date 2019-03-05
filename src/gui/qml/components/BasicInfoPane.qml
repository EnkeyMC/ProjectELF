import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

ColumnLayout {
    id: basicInfoPane

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
                id: elfHeaderGroup
                width: Math.max(130, infoScrollView.availableWidth)
                title: qsTr("ELF header")

                Column {
                    id: headerValues
                    spacing: 10

                    PEKeyValue {
                        key: qsTr("<strong>Class</strong>")
                        value: qsTr("64-bit")
                    }

                    PEKeyValue {
                        key: qsTr("<strong>Encoding</strong>")
                        value: qsTr("Little Endian")
                    }

                    PEKeyValue {
                        key: qsTr("<strong>Architecture</strong>")
                        value: qsTr("ARM")
                    }

                    PEKeyValue {
                        key: qsTr("<strong>Number of sections</strong>")
                        value: qsTr("12")
                    }
                }
            }
        }
    }
}
