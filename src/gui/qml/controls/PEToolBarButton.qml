import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PEButton {
    id: toolBarButton
    clip: true
    bgrColor: Style._ColorSecondaryLight
    bgrHoveredColor: Qt.darker(Style._ColorSecondaryLight, 1.2)
    bgrCheckedColor: Qt.darker(Style._ColorSecondaryLight, 1.1)
    color: Style._ColorTextDark
}
