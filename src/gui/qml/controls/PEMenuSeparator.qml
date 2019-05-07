import QtQuick 2.11
import QtQuick.Controls 2.4

import "../singletons"

MenuSeparator {
    id: menuSeparator
    padding: 5

    contentItem: Rectangle {
        implicitWidth: Style.menuItem._Width
        implicitHeight: 1

        color: Qt.darker(Style._ColorAccent, 1.1)
    }
}
