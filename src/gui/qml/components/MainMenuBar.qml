import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"
import "../js/utils.js" as Utils

MenuBar {
    id: mainMenuBar

    background: Rectangle {
        color: Style._ColorPrimaryDark
        implicitHeight: Style.mainMenuBar._Height
    }

    delegate: MenuBarItem {
        id: menuBarItem

        contentItem: Label {
            text: Utils.formatMnemonicString(menuBarItem.text)
            textFormat: Text.RichText
            opacity: enabled ? 1.0 : 0.3
            color: Style._ColorTextLight
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: Style.mainMenuBar._FontSize
        }

        background: Rectangle {
            implicitHeight: Style.mainMenuBar._Height
            color: Style._ColorAccent
            visible: menuBarItem.down || menuBarItem.highlighted
        }
    }
}
