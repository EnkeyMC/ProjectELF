import QtQuick 2.11
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
        text: headerModel ? headerModel.type : ""
        byteSize: headerModel ? headerModel.typeByteSize : 0
        onEditingFinished: if (headerModel) headerModel.type = text;
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispType : ""
        }
    }


    
    PETableCell {
        Text {
            text: "e_machine"
        }
    }
    
    PETableEditableCell {
        text: headerModel ? headerModel.machine : ""
        byteSize: headerModel ? headerModel.machineByteSize : 0
        onEditingFinished: if (headerModel) headerModel.machine = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispMachine : ""
        }
    }



    PETableCell {
        Text {
            text: "e_version"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.version : ""
        byteSize: headerModel ? headerModel.versionByteSize : 0
        onEditingFinished: if (headerModel) headerModel.version = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispVersion : ""
        }
    }



    PETableCell {
        Text {
            text: "e_entry"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.entry : ""
        byteSize: headerModel ? headerModel.entryByteSize : 0
        onEditingFinished: if (headerModel) headerModel.entry = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispEntry : ""
        }
    }



    PETableCell {
        Text {
            text: "e_phoff"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.phoff : ""
        byteSize: headerModel ? headerModel.phoffByteSize : 0
        onEditingFinished: if (headerModel) headerModel.phoff = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispPhoff : ""
        }
    }



    PETableCell {
        Text {
            text: "e_shoff"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.shoff : ""
        byteSize: headerModel ? headerModel.shoffByteSize : 0
        onEditingFinished: if (headerModel) headerModel.shoff = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispShoff : ""
        }
    }



    PETableCell {
        Text {
            text: "e_flags"
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
            text: "e_ehsize"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.ehsize : ""
        byteSize: headerModel ? headerModel.ehsizeByteSize : 0
        onEditingFinished: if (headerModel) headerModel.ehsize = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispEhsize : ""
        }
    }



    PETableCell {
        Text {
            text: "e_phentsize"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.phentsize : ""
        byteSize: headerModel ? headerModel.phentsizeByteSize : 0
        onEditingFinished: if (headerModel) headerModel.phentsize = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispPhentsize : ""
        }
    }



    PETableCell {
        Text {
            text: "e_phnum"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.phnum : ""
        byteSize: headerModel ? headerModel.phnumByteSize : 0
        onEditingFinished: if (headerModel) headerModel.phnum = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispPhnum : ""
        }
    }



    PETableCell {
        Text {
            text: "e_shentsize"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.shentsize : ""
        byteSize: headerModel ? headerModel.shentsizeByteSize : 0
        onEditingFinished: if (headerModel) headerModel.shentsize = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispShentsize : ""
        }
    }



    PETableCell {
        Text {
            text: "e_shnum"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.shnum : ""
        byteSize: headerModel ? headerModel.shnumByteSize : 0
        onEditingFinished: if (headerModel) headerModel.shnum = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispShnum : ""
        }
    }



    PETableCell {
        Text {
            text: "e_shstrndx"
        }
    }

    PETableEditableCell {
        text: headerModel ? headerModel.shstrndx : ""
        byteSize: headerModel ? headerModel.shstrndxByteSize : 0
        onEditingFinished: if (headerModel) headerModel.shstrndx = text
    }

    PETableCell {
        Text {
            text: headerModel ? headerModel.dispShstrndx : ""
        }
    }
}
