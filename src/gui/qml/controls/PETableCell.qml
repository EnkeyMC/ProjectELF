import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

Pane {
    topPadding: 5
    bottomPadding: 5
    leftPadding: 10
    rightPadding: 10

    Layout.fillWidth: true

    background: Rectangle {
        color: Qt.lighter(Style._ColorPrimaryLight)
    }
}
