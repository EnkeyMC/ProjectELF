import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PEExpandablePane {
    title: headerModel ? (headerModel.valid ? "" : "INVALID ") + "Section #" + headerModel.index + " " + headerModel.dispName : ""
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
            text: headerModel ? headerModel.name : ""
            byteSize: headerModel ? headerModel.nameByteSize : 0
            onEditingFinished: if (headerModel) headerModel.name = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispName : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_type"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.type : ""
            byteSize: headerModel ? headerModel.typeByteSize : 0
            onEditingFinished: if (headerModel) headerModel.type = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispType : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_flags"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.flags : ""
            byteSize: headerModel ? headerModel.flagsByteSize : 0
            onEditingFinished: if (headerModel) headerModel.flags = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispFlags : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_addr"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.addr : ""
            byteSize: headerModel ? headerModel.addrByteSize : 0
            onEditingFinished: if (headerModel) headerModel.addr = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispAddr : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_offset"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.offset : ""
            byteSize: headerModel ? headerModel.offsetByteSize : 0
            onEditingFinished: if (headerModel) headerModel.offset = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispOffset : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_size"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.size : ""
            byteSize: headerModel ? headerModel.sizeByteSize : 0
            onEditingFinished: if (headerModel) headerModel.size = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispSize : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_link"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.link : ""
            byteSize: headerModel ? headerModel.linkByteSize : 0
            onEditingFinished: if (headerModel) headerModel.link = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispLink : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_info"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.info : ""
            byteSize: headerModel ? headerModel.infoByteSize : 0
            onEditingFinished: if (headerModel) headerModel.info = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispInfo : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_addralign"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.addralign : ""
            byteSize: headerModel ? headerModel.addralignByteSize : 0
            onEditingFinished: if (headerModel) headerModel.addralign = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispAddralign : ""
            }
        }



        PETableCell {
            Text {
                text: "sh_entsize"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.entsize : ""
            byteSize: headerModel ? headerModel.entsizeByteSize : 0
            onEditingFinished: if (headerModel) headerModel.entsize = text
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispEntsize : ""
            }
        }
    }
}
