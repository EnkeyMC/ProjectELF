import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

PETableCell {
    property alias text: headerText.text
    property alias horizontalAlignment: headerText.horizontalAlignment

    Text {
        id: headerText
        color: Style._ColorTextLight
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        width: parent.width
        color: Style._ColorSecondaryDark
//        border.color: Qt.lighter(Style._ColorPrimaryLight)
    }
}
