import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtGraphicalEffects 1.0
import projectelf.models 1.0

import "../singletons"
import "../controls"

Rectangle {
    id: dropdown
    height: open ? Math.min(issueListView.contentHeight, 400) : 0
    color: Style._ColorSecondaryDark
    z: 100
    property bool open: false
    
    signal toggle()
    signal open()
    signal close()
    
    onToggle: open = !open
    
    onOpen: open = true
    
    onClose: open = false
    
    MouseArea {
        anchors.fill: parent
        z: -1
    }
}
