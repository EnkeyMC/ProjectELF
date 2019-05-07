import QtQuick 2.11
import QtQuick.Controls 2.4

import "../singletons"

Rectangle {
    id: tabBar
    default property alias content: control.contentData
    property alias currentIndex: control.currentIndex

    signal tabClosed(int index)

    signal tabCreated(int index)

    onTabClosed: {
        if (currentIndex == index) {
            if (index - 1 < 0)
                currentIndex = index + 1
            else
                currentIndex = index - 1
        }
    }

    onTabCreated: currentIndex = index

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
