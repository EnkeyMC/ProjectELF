import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PEExpandablePane {
    title: "Segment #" + headerModel.index
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
                text: "p_flags"
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
                text: "p_offset"
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
                text: "p_vaddr"
            }
        }

        PETableEditableCell {
            text: headerModel.vaddr
            byteSize: headerModel.vaddrByteSize
            onEditingFinished: headerModel.vaddr = text
        }

        PETableCell {
            Text {
                text: headerModel.dispVaddr
            }
        }



        PETableCell {
            Text {
                text: "p_paddr"
            }
        }

        PETableEditableCell {
            text: headerModel.paddr
            byteSize: headerModel.paddrByteSize
            onEditingFinished: headerModel.paddr = text
        }

        PETableCell {
            Text {
                text: headerModel.dispPaddr
            }
        }



        PETableCell {
            Text {
                text: "p_filesz"
            }
        }

        PETableEditableCell {
            text: headerModel.filesz
            byteSize: headerModel.fileszByteSize
            onEditingFinished: headerModel.filesz = text
        }

        PETableCell {
            Text {
                text: headerModel.dispFilesz
            }
        }



        PETableCell {
            Text {
                text: "p_memsz"
            }
        }

        PETableEditableCell {
            text: headerModel.memsz
            byteSize: headerModel.memszByteSize
            onEditingFinished: headerModel.memsz = text
        }

        PETableCell {
            Text {
                text: headerModel.dispMemsz
            }
        }



        PETableCell {
            Text {
                text: "p_align"
            }
        }

        PETableEditableCell {
            text: headerModel.align
            byteSize: headerModel.alignByteSize
            onEditingFinished: headerModel.align = text
        }

        PETableCell {
            Text {
                text: headerModel.dispAlign
            }
        }
    }
}
