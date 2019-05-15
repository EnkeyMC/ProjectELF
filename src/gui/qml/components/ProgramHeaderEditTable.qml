import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PEExpandablePane {
    title: headerModel ? (headerModel.valid ? "" : "INVALID ") + "Segment #" + headerModel.index + " " + headerModel.dispType : ""
    valid: headerModel ? headerModel.valid : true
    minWidth: programHeaderEditTable.implicitWidth

    property ELFProgramHeaderModelItem headerModel

    PETable {
        id: programHeaderEditTable
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
                text: "p_type"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.type : ""
            byteSize: headerModel ? headerModel.typeByteSize : 0
            onEditingFinished: if (headerModel) headerModel.type = text
            enabled: headerModel ? headerModel.valid : false
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispType : ""
            }
        }



        PETableCell {
            Text {
                text: "p_flags"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.flags : ""
            byteSize: headerModel ? headerModel.flagsByteSize : 0
            onEditingFinished: if (headerModel) headerModel.flags = text
            enabled: headerModel ? headerModel.valid : false
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispFlags : ""
            }
        }



        PETableCell {
            Text {
                text: "p_offset"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.offset : ""
            byteSize: headerModel ? headerModel.offsetByteSize : 0
            onEditingFinished: if (headerModel) headerModel.offset = text
            enabled: headerModel ? headerModel.valid : false
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispOffset : ""
            }
        }



        PETableCell {
            Text {
                text: "p_vaddr"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.vaddr : ""
            byteSize: headerModel ? headerModel.vaddrByteSize : 0
            onEditingFinished: if (headerModel) headerModel.vaddr = text
            enabled: headerModel ? headerModel.valid : false
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispVaddr : ""
            }
        }



        PETableCell {
            Text {
                text: "p_paddr"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.paddr : ""
            byteSize: headerModel ? headerModel.paddrByteSize : 0
            onEditingFinished: if (headerModel) headerModel.paddr = text
            enabled: headerModel ? headerModel.valid : false
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispPaddr : ""
            }
        }



        PETableCell {
            Text {
                text: "p_filesz"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.filesz : ""
            byteSize: headerModel ? headerModel.fileszByteSize : 0
            onEditingFinished: if (headerModel) headerModel.filesz = text
            enabled: headerModel ? headerModel.valid : false
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispFilesz : ""
            }
        }



        PETableCell {
            Text {
                text: "p_memsz"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.memsz : ""
            byteSize: headerModel ? headerModel.memszByteSize : 0
            onEditingFinished: if (headerModel) headerModel.memsz = text
            enabled: headerModel ? headerModel.valid : false
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispMemsz : ""
            }
        }



        PETableCell {
            Text {
                text: "p_align"
            }
        }

        PETableEditableCell {
            text: headerModel ? headerModel.align : ""
            byteSize: headerModel ? headerModel.alignByteSize : 0
            onEditingFinished: if (headerModel) headerModel.align = text
            enabled: headerModel ? headerModel.valid : false
        }

        PETableCell {
            Text {
                text: headerModel ? headerModel.dispAlign : ""
            }
        }
    }
}
