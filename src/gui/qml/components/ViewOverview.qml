import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

PESplitView {
    orientation: Qt.Horizontal

    DiagramPane {
        Layout.fillWidth: true
        Layout.minimumWidth: 200
    }

    BasicInfoPane {
        Layout.minimumWidth: 150
        width: 200
    }
}
