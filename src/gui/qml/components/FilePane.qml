import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtGraphicalEffects 1.0

import "../singletons"

Item {
    property int view: View.currentView

    StackLayout {
        width: parent.width
        height: parent.height
        currentIndex: parent.view

        Item {
            Text {
                text: "View"
            }
        }

        Item {
            Text {
                text: "Edit"
            }
        }
    }
}
