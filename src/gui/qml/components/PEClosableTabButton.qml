import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"

TabButton {
    id: control

    padding: 0
    width: Math.max(100, layout.childrenRect.x + layout.childrenRect.width)

    contentItem: RowLayout {
        id: layout

        Item {
            width: 10
        }

        Text {
            text: control.text
            font: control.font
            color: Style._ColorTextDark

            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }

        Item {
            width: 10
        }

        Item {
            width: 20
            height: parent.height

            anchors.margins: 20

            Button {
                id: closeBtn

                anchors.fill: parent
                text: "×"

                contentItem: Text {
                    text: closeBtn.text
                    font.pixelSize: 18
                    color: closeBtn.hovered ? Style._ColorAccent : Style._ColorTextDark
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }

                background: Rectangle {
                    visible: false
                }
            }
        }
    }

    background: Rectangle {
        implicitHeight: Style.tabBar._Height
        color: control.checked ? Style._ColorPrimaryLight : Style._ColorSecondaryLight
    }
}
