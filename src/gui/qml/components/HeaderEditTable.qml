import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PETable {
    id: headerEditTable
    columns: 2
    
    property ELFHeaderModelItem headerModel

    PETableHeader {
        text: qsTr("Field")
    }
    
    PETableHeader {
        text: qsTr("Value")
    }
    
    PETableCell {
        Text {
            text: "e_type"
        }
    }
    
    PETableEditableCell {
        text: headerModel.type
        byteSize: headerModel.typeByteSize
        onEditingFinished: headerModel.type = text
    }
    
    PETableCell {
        Text {
            text: "e_machine"
        }
    }
    
    PETableEditableCell {
        text: headerModel.machine
        byteSize: headerModel.machineByteSize
        onEditingFinished: headerModel.machine = text
    }

    PETableCell {
        Text {
            text: "e_version"
        }
    }

    PETableEditableCell {
        text: headerModel.version
        byteSize: headerModel.versionByteSize
        onEditingFinished: headerModel.version = text
    }

    PETableCell {
        Text {
            text: "e_entry"
        }
    }

    PETableEditableCell {
        text: headerModel.entry
        byteSize: headerModel.entryByteSize
        onEditingFinished: headerModel.entry = text
    }

    PETableCell {
        Text {
            text: "e_phoff"
        }
    }

    PETableEditableCell {
        text: headerModel.phoff
        byteSize: headerModel.phoffByteSize
        onEditingFinished: headerModel.phoff = text
    }

    PETableCell {
        Text {
            text: "e_shoff"
        }
    }

    PETableEditableCell {
        text: headerModel.shoff
        byteSize: headerModel.shoffByteSize
        onEditingFinished: headerModel.shoff = text
    }

    PETableCell {
        Text {
            text: "e_flags"
        }
    }

    PETableEditableCell {
        text: headerModel.flags
        byteSize: headerModel.flagsByteSize
        onEditingFinished: headerModel.flags = text
    }

    PETableCell {
        Text {
            text: "e_ehsize"
        }
    }

    PETableEditableCell {
        text: headerModel.ehsize
        byteSize: headerModel.ehsizeByteSize
        onEditingFinished: headerModel.ehsize = text
    }

    PETableCell {
        Text {
            text: "e_phentsize"
        }
    }

    PETableEditableCell {
        text: headerModel.phentsize
        byteSize: headerModel.phentsizeByteSize
        onEditingFinished: headerModel.phentsize = text
    }

    PETableCell {
        Text {
            text: "e_phnum"
        }
    }

    PETableEditableCell {
        text: headerModel.phnum
        byteSize: headerModel.phnumByteSize
        onEditingFinished: headerModel.phnum = text
    }

    PETableCell {
        Text {
            text: "e_shentsize"
        }
    }

    PETableEditableCell {
        text: headerModel.shentsize
        byteSize: headerModel.shentsizeByteSize
        onEditingFinished: headerModel.shentsize = text
    }

    PETableCell {
        Text {
            text: "e_shnum"
        }
    }

    PETableEditableCell {
        text: headerModel.shnum
        byteSize: headerModel.shnumByteSize
        onEditingFinished: headerModel.shnum = text
    }

    PETableCell {
        Text {
            text: "e_shstrndx"
        }
    }

    PETableEditableCell {
        text: headerModel.shstrndx
        byteSize: headerModel.shstrndxByteSize
        onEditingFinished: headerModel.shstrndxByteSize = text
    }
}
