import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../js/utils.js" as Utils

Menu {
    id: menu

    readonly property int _StyleDark: 0
    readonly property int _StyleLight: 1

    property int style: _StyleDark

    delegate: MenuItem {
        id: menuItem

        implicitHeight: Style.menuItem._Height
        implicitWidth: Style.menuItem._Width

        arrow: Canvas {
            x: parent.width - width
            implicitWidth: Style.menuItem._Height
            implicitHeight: Style.menuItem._Height
            visible: menuItem.subMenu
            onPaint: {
                var ctx = getContext("2d")
                ctx.fillStyle = menu.style === menu._StyleDark ? Style._ColorTextLight : Style._ColorTextDark
                ctx.moveTo(10, 10)
                ctx.lineTo(width - 10, height / 2)
                ctx.lineTo(10, height - 10)
                ctx.closePath()
                ctx.fill()
            }
        }

        contentItem: Label {
            leftPadding: menuItem.indicator.width
            rightPadding: menuItem.arrow.width
            text: Utils.formatMnemonicString(menuItem.text)
            textFormat: Text.RichText
            font: menuItem.font
            opacity: enabled ? 1.0 : 0.3
            color: menu.style === menu._StyleDark ? Style._ColorTextLight : Style._ColorTextDark
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            implicitHeight: Style.menuItem._Height
            implicitWidth: Style.menuItem._Width
            opacity: enabled ? 1 : 0.3
            color: Style._ColorAccent
            visible: menuItem.highlighted
        }
    }

    background: Rectangle {
        implicitHeight: Style.menuItem._Height
        implicitWidth: Style.menuItem._Width
        color: Style._ColorPrimaryDark
    }
}
