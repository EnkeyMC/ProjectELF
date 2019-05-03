import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PEExpandablePane {
    title: "Section " + headerModel.dispName
    minWidth: sectionHeaderEditTable.implicitWidth

    property ELFSectionHeaderModelItem headerModel

    PETable {
        id: sectionHeaderEditTable
        columns: 3
        width: parent.width

        PETableHeader {
            text: qsTr("Field")
        }

        PETableHeader {
            text: qsTr("HEX Value")
        }

        PETableHeader {
            text: qsTr("Display value")
        }



        PETableCell {
            Text {
                text: "sh_name"
            }
        }

        PETableEditableCell {
            text: headerModel.name
            byteSize: headerModel.nameByteSize
            onEditingFinished: headerModel.name = text
        }

        PETableCell {
            Text {
                text: headerModel.dispName
            }
        }



        PETableCell {
            Text {
                text: "sh_type"
            }
        }

        PETableEditableCell {
            text: headerModel.type
            byteSize: headerModel.typeByteSize
            onEditingFinished: headerModel.type = text
        }

        PETableCell {
            Text {
                text: headerModel.dispType
            }
        }



        PETableCell {
            Text {
                text: "sh_flags"
            }
        }

        PETableEditableCell {
            text: headerModel.flags
            byteSize: headerModel.flagsByteSize
            onEditingFinished: headerModel.flags = text
        }

        PETableCell {
            Text {
                text: headerModel.dispFlags
            }
        }



        PETableCell {
            Text {
                text: "sh_addr"
            }
        }

        PETableEditableCell {
            text: headerModel.addr
            byteSize: headerModel.addrByteSize
            onEditingFinished: headerModel.addr = text
        }

        PETableCell {
            Text {
                text: headerModel.dispAddr
            }
        }



        PETableCell {
            Text {
                text: "sh_offset"
            }
        }

        PETableEditableCell {
            text: headerModel.offset
            byteSize: headerModel.offsetByteSize
            onEditingFinished: headerModel.offset = text
        }

        PETableCell {
            Text {
                text: headerModel.dispOffset
            }
        }



        PETableCell {
            Text {
                text: "sh_size"
            }
        }

        PETableEditableCell {
            text: headerModel.size
            byteSize: headerModel.sizeByteSize
            onEditingFinished: headerModel.size = text
        }

        PETableCell {
            Text {
                text: headerModel.dispSize
            }
        }



        PETableCell {
            Text {
                text: "sh_link"
            }
        }

        PETableEditableCell {
            text: headerModel.link
            byteSize: headerModel.linkByteSize
            onEditingFinished: headerModel.link = text
        }

        PETableCell {
            Text {
                text: headerModel.dispLink
            }
        }



        PETableCell {
            Text {
                text: "sh_info"
            }
        }

        PETableEditableCell {
            text: headerModel.info
            byteSize: headerModel.infoByteSize
            onEditingFinished: headerModel.info = text
        }

        PETableCell {
            Text {
                text: headerModel.dispInfo
            }
        }



        PETableCell {
            Text {
                text: "sh_addralign"
            }
        }

        PETableEditableCell {
            text: headerModel.addralign
            byteSize: headerModel.addralignByteSize
            onEditingFinished: headerModel.addralign = text
        }

        PETableCell {
            Text {
                text: headerModel.dispAddralign
            }
        }



        PETableCell {
            Text {
                text: "sh_entsize"
            }
        }

        PETableEditableCell {
            text: headerModel.entsize
            byteSize: headerModel.entsizeByteSize
            onEditingFinished: headerModel.entsize = text
        }

        PETableCell {
            Text {
                text: headerModel.dispEntsize
            }
        }
    }
}
