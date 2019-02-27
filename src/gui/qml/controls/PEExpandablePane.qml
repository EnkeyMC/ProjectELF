import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

ColumnLayout {
    id: expandable
    spacing: 0

    default property alias __items: expandableItem.data

    Pane {
        Layout.fillWidth: true

        RowLayout {
            Text {
                text: qsTr("text")
            }
        }

        background: Rectangle {
            color: Style._ColorSecondaryDark

            MouseArea {
                anchors.fill: parent
                onClicked: expandableItem.state == 'expanded' ? expandableItem.state = '' : expandableItem.state = 'expanded'
            }
        }
    }

    Item {
        id: expandableItem
        Layout.fillWidth: true
        height: 0
        clip: true

        states: [
            State {
                name: "expanded"
                PropertyChanges {
                    target: expandableItem
                    height: expandableItem.childrenRect.height
                }
            }
        ]

        transitions: [
            Transition {
                to: "expanded"
                NumberAnimation {
                    duration: 400
                    properties: "height"
                    easing.type: Easing.InOutCubic
                }
            },
            Transition {
                to: ""
                NumberAnimation {
                    duration: 400
                    properties: "height"
                    easing.type: Easing.InOutCubic
                }
            }
        ]
    }
}
