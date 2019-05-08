import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"

ColumnLayout {
    id: filePane
    width: parent.width
    height: parent.height
    spacing: 0
    property alias elfModel: viewOverview.elfModel

    StackLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true

        currentIndex: View.currentView

        ViewOverview {
            id: viewOverview
        }

        ViewEdit {
            elfModel: filePane.elfModel
        }
    }

    StatusBar {
        Layout.fillWidth: true
        issueListModel: filePane.elfModel ? filePane.elfModel.issueListModel : undefined
    }
}

