import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

TextField {
    id: tableEditableCell
    Layout.fillWidth: true
    padding: 5
    
    background: Rectangle {
        implicitHeight: 20
    }
}
