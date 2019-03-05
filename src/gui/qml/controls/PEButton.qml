import QtQuick 2.9
import QtQuick.Controls 2.4

import "../singletons"

Button {
    id: button

    contentItem: Text {
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
                   Style._ColorAccent
            :
               (button.highlighted ||
               button.visualFocus ||
               button.hovered)
            ?
                   Qt.darker(Style._ColorAccent, 1.1)
            :
                   Style._ColorPrimaryDark
    }
}
