import QtQuick 2.11
import projectelf.models 1.0

import "../controls"

PETable {
    id: identificationEditTable
    columns: 3

    property ELFModel elfModel

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
            text: "ei_mag0"
        }
    }

    PETableEditableCell {
        text: elfModel.mag0
        byteSize: elfModel.mag0ByteSize
        onEditingFinished: elfModel.mag0 = text
    }

    PETableCell {
        Text {
            text: elfModel.dispMag0
        }
    }


    PETableCell {
        Text {
            text: "ei_mag1"
        }
    }

    PETableEditableCell {
        text: elfModel.mag1
        byteSize: elfModel.mag1ByteSize
        onEditingFinished: elfModel.mag1 = text
    }

    PETableCell {
        Text {
            text: elfModel.dispMag1
        }
    }


    PETableCell {
        Text {
            text: "ei_mag2"
        }
    }

    PETableEditableCell {
        text: elfModel.mag2
        byteSize: elfModel.mag2ByteSize
        onEditingFinished: elfModel.mag2 = text
    }

    PETableCell {
        Text {
            text: elfModel.dispMag2
        }
    }


    PETableCell {
        Text {
            text: "ei_mag3"
        }
    }

    PETableEditableCell {
        text: elfModel.mag3
        byteSize: elfModel.mag3ByteSize
        onEditingFinished: elfModel.mag3 = text
    }

    PETableCell {
        Text {
            text: elfModel.dispMag3
        }
    }


    PETableCell {
        Text {
            text: "ei_class"
        }
    }

    PETableEditableCell {
        text: elfModel.fileClass
        byteSize: elfModel.fileClassByteSize
        onEditingFinished: elfModel.fileClass = text
    }

    PETableCell {
        Text {
            text: elfModel.dispFileClass
        }
    }


    PETableCell {
        Text {
            text: "ei_data"
        }
    }

    PETableEditableCell {
        text: elfModel.dataEncoding
        byteSize: elfModel.dataEncodingByteSize
        onEditingFinished: elfModel.dataEncoding = text
    }

    PETableCell {
        Text {
            text: elfModel.dispDataEncoding
        }
    }


    PETableCell {
        Text {
            text: "ei_version"
        }
    }

    PETableEditableCell {
        text: elfModel.version
        byteSize: elfModel.versionByteSize
        onEditingFinished: elfModel.version = text
    }

    PETableCell {
        Text {
            text: elfModel.dispVersion
        }
    }


    PETableCell {
        Text {
            text: "ei_osabi"
        }
    }

    PETableEditableCell {
        text: elfModel.osabi
        byteSize: elfModel.osabiByteSize
        onEditingFinished: elfModel.osabi = text
    }

    PETableCell {
        Text {
            text: elfModel.dispOsabi
        }
    }


    PETableCell {
        Text {
            text: "ei_abiversion"
        }
    }

    PETableEditableCell {
        text: elfModel.abiversion
        byteSize: elfModel.abiversionByteSize
        onEditingFinished: elfModel.abiversion = text
    }

    PETableCell {
        Text {
            text: elfModel.dispAbiversion
        }
    }
}
