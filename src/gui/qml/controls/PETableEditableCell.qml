import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

PETableCell {
    id: tableEditableCell
    Layout.minimumWidth: rowLayout.childrenRect.width + leftPadding + rightPadding
    topPadding: 0
    bottomPadding: 0
    height: rowLayout.height

    property alias text: textField.text
    property int byteSize: 0

    signal editingFinished()

    Row {
        id: rowLayout
        width: tableEditableCell.width
        spacing: 0

        Text {
            text: "0x"
            verticalAlignment: Qt.AlignVCenter
            height: rowLayout.height
            font.family: "Courier"
            color: "gray"
        }

        TextField {
            id: textField
            padding: 5
            maximumLength: byteSize*2
            inputMask: "H".repeat(byteSize*2)
            font.family: "Courier"

            onEditingFinished: tableEditableCell.editingFinished()

            background: Rectangle {
                implicitHeight: 20
            }
        }
    }
}

