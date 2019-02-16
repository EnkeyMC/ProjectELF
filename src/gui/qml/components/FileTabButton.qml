import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

TabButton {
    id: root

    contentItem: RowLayout {
        Item {
            width: 10
        }

        Text {
            text: root.text
            font: root.font
            color: root.checked ? "black" : "white"

            elide: Text.ElideRight
        }

        Item {
            width: 10
        }

        Item {
            width: 20
            height: parent.height

            anchors.margins: 20

            Button {
                anchors.fill: parent
                text: "X"
            }
        }

    }
}
