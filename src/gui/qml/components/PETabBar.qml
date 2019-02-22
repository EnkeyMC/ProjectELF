import QtQuick 2.9
import QtQuick.Controls 2.4

import "../singletons"

Rectangle {
    default property alias _tabButtons: control.data
    property alias currentIndex: control.currentIndex

    color: Style._ColorSecondaryDark

    TabBar {
        id: control
        height: parent.height
        position: TabBar.Header

        spacing: 2

        contentItem: ListView {
            model: control.contentModel
            currentIndex: control.currentIndex

            spacing: control.spacing
            orientation: ListView.Horizontal
            boundsBehavior: Flickable.StopAtBounds
            flickableDirection: Flickable.AutoFlickIfNeeded
            snapMode: ListView.SnapToItem

            highlightMoveDuration: 0
            highlightRangeMode: ListView.ApplyRange
            preferredHighlightBegin: 40
            preferredHighlightEnd: width - 40
        }

        background: Rectangle {
            width: control.width
            color: Style._ColorSecondaryDark
        }
    }

}
