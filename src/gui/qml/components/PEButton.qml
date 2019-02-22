import QtQuick 2.9
import QtQuick.Controls 2.4

import "../singletons"

Button {
    id: control

    contentItem: Text {
        text: control.text
        font.pixelSize: Style.button._FontSize
        color: Style._ColorTextLight
        horizontalAlignment: Text.AlignHCenter
    }

    background: Rectangle {
        implicitHeight: Style.button._Height
        implicitWidth: 80

        color: (control.down ||
               control.checked)
            ?
                   Style._ColorAccent
            :
               (control.highlighted ||
               control.visualFocus ||
               control.hovered)
            ?
                   Qt.darker(Style._ColorAccent, 1.1)
            :
                   Style._ColorPrimaryDark
    }
}
