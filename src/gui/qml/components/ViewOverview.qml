import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

PESplitView {
    id: viewOverview
    orientation: Qt.Horizontal

    property alias elfModel: diagramPane.elfModel

    DiagramPane {
        id: diagramPane
        Layout.fillWidth: true
        Layout.minimumWidth: 200
    }

    BasicInfoPane {
        Layout.minimumWidth: 150
        width: 200

        elfModel: viewOverview.elfModel
    }
}
