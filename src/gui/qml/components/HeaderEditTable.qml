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
        maximumLength: headerModel.typeByteSize
        inputMask: "H".repeat(headerModel.typeByteSize)
        onEditingFinished: headerModel.type = text
    }
    
    PETableCell {
        Text {
            text: "e_machine"
        }
    }
    
    PETableEditableCell {
        text: headerModel.machine
        maximumLength: headerModel.machineByteSize
        inputMask: "H".repeat(headerModel.machineByteSize)
        onEditingFinished: headerModel.machine = text
    }


    PETableCell {
        Text {
            text: "e_version"
        }
    }

    PETableEditableCell {
        text: headerModel.version
        maximumLength: headerModel.versionByteSize
        inputMask: "H".repeat(headerModel.versionByteSize)
        onEditingFinished: headerModel.version = text
    }
}
