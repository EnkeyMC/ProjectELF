import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

ColumnLayout {
    id: expandable
    spacing: 0

    property string title: ""
    default property alias __items: expandableItem.data

    Pane {
        Layout.fillWidth: true
        leftPadding: 10
        rightPadding: 10
        topPadding: 5
        bottomPadding: 5

        RowLayout {
            Canvas {
                id: indicator
                width: 7
                height: 7

                onPaint: {
                    var ctx = getContext("2d")
                    ctx.reset()
                    ctx.fillStyle = Style._ColorTextLight

                    if (expandableItem.state == 'expanded') {
                        ctx.moveTo(0, 0)
                        ctx.lineTo(width, 0)
                        ctx.lineTo(width/2, height)
                    } else {
                        ctx.moveTo(0, 0)
                        ctx.lineTo(width, height/2)
                        ctx.lineTo(0, height)
                    }

                    ctx.closePath()
                    ctx.fill()
                }
            }

            Text {
                text: expandable.title
                color: Style._ColorTextLight
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

        onStateChanged: indicator.requestPaint()

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
