import QtQuick 2.9
import QtQuick.Controls 2.4

import "../singletons"

MenuSeparator {
    padding: 5

    contentItem: Rectangle {
        implicitWidth: Style.menuItem._Width
        implicitHeight: 1

        color: Qt.darker(Style._ColorAccent, 1.1)
    }
}
