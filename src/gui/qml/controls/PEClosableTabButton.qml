import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"

TabButton {
    id: tabButton

    padding: 0
    width: Math.max(100, layout.childrenRect.x + layout.childrenRect.width)

    signal closeTab

    contentItem: RowLayout {
        spacing: 0
        id: layout

        RowLayout {
            spacing: 0
            Layout.fillHeight: true

            Spacer {
                width: 10
            }

            Text {
                text: tabButton.text
                font: tabButton.font
                color: Style._ColorTextDark

                verticalAlignment: Text.AlignVCenter
            }

            Spacer {
                width: 10
            }
        }

        Spacer {
            Layout.fillWidth: true
        }

        Item {
            id: closeBtnContainer
            width: 20
            height: parent.height

            Button {
                id: closeBtn

                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: parent.width
                text: "×"

                onClicked: tabButton.closeTab();

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
        color: !tabButton.checked ? Style._ColorPrimaryLight : Style._ColorSecondaryLight
    }
}
