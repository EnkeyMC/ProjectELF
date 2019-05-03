import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

PETableCell {
    id: tableEditableCell
    Layout.minimumWidth: rowLayout.childrenRect.width + leftPadding + rightPadding
    Layout.fillHeight: true
    topPadding: 0
    bottomPadding: 0

    property alias text: textField.text
//    property alias dispText: dispText.text
    property string dispText: ""
    property int byteSize: 0

    signal editingFinished()

    Row {
        id: rowLayout
        width: tableEditableCell.width
        spacing: 0
        height: parent.height

        Text {
            text: "0x"
            verticalAlignment: Qt.AlignVCenter
            height: rowLayout.height
            font.family: "Courier"
            font.pixelSize: Style._DefaultFontSize
            color: "gray"
        }

        TextField {
            id: textField
            padding: 0
            verticalAlignment: Qt.AlignVCenter
            height: rowLayout.height
            maximumLength: byteSize*2
            inputMask: "H".repeat(byteSize*2)
            font.family: "Courier"
            font.pixelSize: Style._DefaultFontSize
            selectByMouse: true

            onEditingFinished: tableEditableCell.editingFinished()

            background: Rectangle {
                implicitHeight: 10
            }
        }
    }
}

