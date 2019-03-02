import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

GroupBox {
    id: peGroupBox

    label: Label {
        text: peGroupBox.title
        width: peGroupBox.availableWidth
        elide: Text.ElideRight
        color: Style._ColorTextDark
    }

    background: Rectangle {
        color: "transparent"
        border.color: Style._ColorSecondaryLight

        y: peGroupBox.topPadding - peGroupBox.bottomPadding
        width: peGroupBox.width
        height: peGroupBox.height - peGroupBox.topPadding + peGroupBox.bottomPadding
    }
}
