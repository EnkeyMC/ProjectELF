import QtQuick 2.9
import QtQuick.Controls 2.4

import "../singletons"

Button {
    id: button

    property color bgrColor: Style._ColorPrimaryDark
    property color bgrHoveredColor: Qt.darker(Style._ColorAccent, 1.1)
    property color bgrCheckedColor: Style._ColorAccent
    property alias color: buttonText.color

    contentItem: Text {
        id: buttonText
        text: button.text
        font.pixelSize: Style.button._FontSize
        color: Style._ColorTextLight
        horizontalAlignment: Text.AlignHCenter
    }

    background: Rectangle {
        implicitHeight: Style.button._Height
        implicitWidth: 80

        color: (button.down ||
               button.checked)
            ?
                   button.bgrCheckedColor
            :
               (button.highlighted ||
               button.visualFocus ||
               button.hovered)
            ?
                   button.bgrHoveredColor
            :
                   button.bgrColor
    }
}
