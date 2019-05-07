import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

Column {
    id: expandable
    spacing: 1

    property string title: ""
    property int minWidth: 0
    default property alias __items: expandableItem.data

    Pane {
        id: expandableHeader
        width: parent.width
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

    Column {
        id: expandableItem
        width: parent.width
        height: state == "" ? 0 : implicitHeight
        clip: true

        onStateChanged: indicator.requestPaint()

        states: [
            State {
                name: ""
                PropertyChanges {
                    target: expandableItem
                    height: 0
                }
            },
            State {
                name: "expanded"
                PropertyChanges {
                    target: expandableItem
                    height: expandableItem.implicitHeight
                }
            }
        ]
    }
}
