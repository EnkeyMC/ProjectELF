import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"

Item {
    id: filePane
    property int view: View.currentView

    StackLayout {
        id: viewStack
        width: parent.width
        height: parent.height
        currentIndex: parent.view

        ViewOverview {

        }

        ViewEdit {

        }
    }
}
