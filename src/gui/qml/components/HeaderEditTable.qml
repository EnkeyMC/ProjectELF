import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PETable {
    id: headerEditTable
    columns: 3
    
    property ELFHeaderModelItem headerModel

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
            text: headerModel.dispType
        }
    }


    
    PETableCell {
        Text {
            text: "e_machine"
        }
    }
    
    PETableEditableCell {
        text: headerModel.machine
        dispText: headerModel.dispMachine
        byteSize: headerModel.machineByteSize
        onEditingFinished: headerModel.machine = text
    }

    PETableCell {
        Text {
            text: headerModel.dispMachine
        }
    }



    PETableCell {
        Text {
            text: "e_version"
        }
    }

    PETableEditableCell {
        text: headerModel.version
        dispText: headerModel.dispVersion
        byteSize: headerModel.versionByteSize
        onEditingFinished: headerModel.version = text
    }

    PETableCell {
        Text {
            text: headerModel.dispVersion
        }
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
            text: headerModel.dispEntry
        }
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
            text: headerModel.dispPhoff
        }
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
            text: headerModel.dispShoff
        }
    }



    PETableCell {
        Text {
            text: "e_flags"
        }
    }

    PETableEditableCell {
        text: headerModel.flags
        dispText: headerModel.dispFlags
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
            text: "e_ehsize"
        }
    }

    PETableEditableCell {
        text: headerModel.ehsize
        dispText: headerModel.dispEhsize
        byteSize: headerModel.ehsizeByteSize
        onEditingFinished: headerModel.ehsize = text
    }

    PETableCell {
        Text {
            text: headerModel.dispEhsize
        }
    }



    PETableCell {
        Text {
            text: "e_phentsize"
        }
    }

    PETableEditableCell {
        text: headerModel.phentsize
        dispText: headerModel.dispPhentsize
        byteSize: headerModel.phentsizeByteSize
        onEditingFinished: headerModel.phentsize = text
    }

    PETableCell {
        Text {
            text: headerModel.dispPhentsize
        }
    }



    PETableCell {
        Text {
            text: "e_phnum"
        }
    }

    PETableEditableCell {
        text: headerModel.phnum
        dispText: headerModel.dispPhnum
        byteSize: headerModel.phnumByteSize
        onEditingFinished: headerModel.phnum = text
    }

    PETableCell {
        Text {
            text: headerModel.dispPhnum
        }
    }



    PETableCell {
        Text {
            text: "e_shentsize"
        }
    }

    PETableEditableCell {
        text: headerModel.shentsize
        dispText: headerModel.dispShentsize
        byteSize: headerModel.shentsizeByteSize
        onEditingFinished: headerModel.shentsize = text
    }

    PETableCell {
        Text {
            text: headerModel.dispShentsize
        }
    }



    PETableCell {
        Text {
            text: "e_shnum"
        }
    }

    PETableEditableCell {
        text: headerModel.shnum
        dispText: headerModel.dispShnum
        byteSize: headerModel.shnumByteSize
        onEditingFinished: headerModel.shnum = text
    }

    PETableCell {
        Text {
            text: headerModel.dispShnum
        }
    }



    PETableCell {
        Text {
            text: "e_shstrndx"
        }
    }

    PETableEditableCell {
        text: headerModel.shstrndx
        dispText: headerModel.dispShstrndx
        byteSize: headerModel.shstrndxByteSize
        onEditingFinished: headerModel.shstrndx = text
    }

    PETableCell {
        Text {
            text: headerModel.dispShstrndx
        }
    }
}
