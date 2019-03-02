import QtQuick 2.9
import QtQuick.Controls 2.4

import "../singletons"

Rectangle {
    default property alias content: control.contentChildren
    property alias currentIndex: control.currentIndex

    color: Style._ColorSecondaryDark
    height: Style.tabBar._Height + Style.tabBar._TopPadding

    TabBar {
        id: control
        height: parent.height
        position: TabBar.Header
        width: parent.width

        spacing: Style.tabBar._Spacing
        topPadding: Style.tabBar._TopPadding

        background: Rectangle {
            width: control.width
            color: Style._ColorSecondaryDark
        }
    }
}
