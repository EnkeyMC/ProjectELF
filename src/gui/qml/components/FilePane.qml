import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"

StackLayout {
    id: filePane
    width: parent.width
    height: parent.height
    currentIndex: View.currentView

    property alias elfModel: viewOverview.elfModel

    ViewOverview {
        id: viewOverview
    }

    ViewEdit {
        elfModel: filePane.elfModel
    }
}
