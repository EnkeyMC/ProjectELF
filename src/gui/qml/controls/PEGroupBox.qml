import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

GroupBox {
    id: groupBox

    label: Label {
        text: groupBox.title
        width: groupBox.availableWidth
        elide: Text.ElideRight
        color: Style._ColorTextDark
    }

    background: Rectangle {
        color: "transparent"
        border.color: Style._ColorSecondaryLight

        y: groupBox.topPadding - groupBox.bottomPadding
        width: groupBox.width
        height: groupBox.height - groupBox.topPadding + groupBox.bottomPadding
    }
}
