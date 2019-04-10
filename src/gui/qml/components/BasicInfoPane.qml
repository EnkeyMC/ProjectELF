import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

ColumnLayout {
    id: basicInfoPane

    property ELFModel elfModel: ELFModel {}

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
            spacing: 10
            PEGroupBox {
                id: elfIdentGroup
                width: Math.max(130, infoScrollView.availableWidth)
                title: qsTr("ELF identification")

                Column {
                    id: identValues
                    spacing: 10

                    PEKeyValue {
                        key: qsTr("<strong>Class</strong>")
                        value: basicInfoPane.elfModel.dispFileClass
                    }

                    PEKeyValue {
                        key: qsTr("<strong>Encoding</strong>")
                        value: basicInfoPane.elfModel.dispDataEncoding
                    }

                    PEKeyValue {
                        key: qsTr("<strong>Version</strong>")
                        value: basicInfoPane.elfModel.dispVersion
                    }

                    PEKeyValue {
                        key: qsTr("<strong>OS ABI</strong>")
                        value: basicInfoPane.elfModel.dispOsabi
                    }

                    PEKeyValue {
                        key: qsTr("<strong>ABI Version</strong>")
                        value: basicInfoPane.elfModel.dispAbiversion
                    }
                }
            }

            Loader {
                id: elfHeaderGroupLoader
                sourceComponent: elfHeaderGroupComponent
                active: elfModel.header != undefined
            }

            Component {
                id: elfHeaderGroupComponent

                PEGroupBox {
                    id: elfHeaderGroup
                    width: Math.max(130, infoScrollView.availableWidth)
                    title: qsTr("ELF header")

                    Column {
                        id: headerValues
                        spacing: 10

                        PEKeyValue {
                            key: qsTr("<strong>File type</strong>")
                            value: elfModel.header.dispType
                        }

                        PEKeyValue {
                            key: qsTr("<strong>Architecture</strong>")
                            value: elfModel.header.dispMachine
                        }

                        PEKeyValue {
                            key: qsTr("<strong>Version</strong>")
                            value: elfModel.header.dispVersion
                        }

                        PEKeyValue {
                            key: qsTr("<strong>Entry point</strong>")
                            value: elfModel.header.dispEntry
                        }

                        PEKeyValue {
                            key: qsTr("<strong>Number of segments</strong>")
                            value: elfModel.header.dispPhnum
                        }

                        PEKeyValue {
                            key: qsTr("<strong>Number of sections</strong>")
                            value: elfModel.header.dispShnum
                        }
                    }
                }
            }
        }
    }
}
