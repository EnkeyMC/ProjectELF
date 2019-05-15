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
        text: elfModel ? elfModel.mag0 : ""
        byteSize: elfModel ? elfModel.mag0ByteSize : 0
        onEditingFinished: if (elfModel) elfModel.mag0 = text;
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispMag0 : ""
        }
    }


    PETableCell {
        Text {
            text: "ei_mag1"
        }
    }

    PETableEditableCell {
        text: elfModel ? elfModel.mag1 : ""
        byteSize: elfModel ? elfModel.mag1ByteSize : 0
        onEditingFinished: if (elfModel) elfModel.mag1 = text;
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispMag1 : ""
        }
    }


    PETableCell {
        Text {
            text: "ei_mag2"
        }
    }

    PETableEditableCell {
        text: elfModel ? elfModel.mag2 : ""
        byteSize: elfModel ? elfModel.mag2ByteSize : 0
        onEditingFinished: if (elfModel) elfModel.mag2 = text
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispMag2 : ""
        }
    }


    PETableCell {
        Text {
            text: "ei_mag3"
        }
    }

    PETableEditableCell {
        text: elfModel ? elfModel.mag3 : ""
        byteSize: elfModel ? elfModel.mag3ByteSize : 0
        onEditingFinished: if (elfModel) elfModel.mag3 = text;
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispMag3 : ""
        }
    }


    PETableCell {
        Text {
            text: "ei_class"
        }
    }

    PETableEditableCell {
        text: elfModel ? elfModel.fileClass : ""
        byteSize: elfModel ? elfModel.fileClassByteSize : 0
        onEditingFinished: if (elfModel) elfModel.fileClass = text;
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispFileClass : ""
        }
    }


    PETableCell {
        Text {
            text: "ei_data"
        }
    }

    PETableEditableCell {
        text: elfModel ? elfModel.dataEncoding : ""
        byteSize: elfModel ?  elfModel.dataEncodingByteSize : 0
        onEditingFinished: if (elfModel) elfModel.dataEncoding = text;
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispDataEncoding : ""
        }
    }


    PETableCell {
        Text {
            text: "ei_version"
        }
    }

    PETableEditableCell {
        text: elfModel ? elfModel.version : ""
        byteSize: elfModel ? elfModel.versionByteSize : 0
        onEditingFinished: if (elfModel) elfModel.version = text;
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispVersion : ""
        }
    }


    PETableCell {
        Text {
            text: "ei_osabi"
        }
    }

    PETableEditableCell {
        text: elfModel ? elfModel.osabi : ""
        byteSize: elfModel ? elfModel.osabiByteSize : 0
        onEditingFinished: if (elfModel) elfModel.osabi = text;
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispOsabi : ""
        }
    }


    PETableCell {
        Text {
            text: "ei_abiversion"
        }
    }

    PETableEditableCell {
        text: elfModel ? elfModel.abiversion : ""
        byteSize: elfModel ? elfModel.abiversionByteSize : 0
        onEditingFinished: if (elfModel) elfModel.abiversion = text ;
    }

    PETableCell {
        Text {
            text: elfModel ? elfModel.dispAbiversion : ""
        }
    }
}
