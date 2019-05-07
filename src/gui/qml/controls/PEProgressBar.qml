import QtQuick 2.11
import QtQuick.Controls 2.4

import "../singletons"

ProgressBar {
    id: progressBar

    property alias color: bgr.color

    background: Rectangle {
        id: bgr
        implicitHeight: Style.progressBar._Height
        color: Qt.darker(Style._ColorPrimaryDark, 1.3)
        radius: Style.progressBar._Height / 2
    }

    contentItem: Item {
        id: content
        implicitWidth: 200
        implicitHeight: Style.progressBar._Height

        Rectangle {
            id: contentProgress
            width: progressBar.visualPosition * parent.width
            height: parent.height
            radius: Style.progressBar._Height / 2
            color: Style._ColorAccent

            visible: !progressBar.indeterminate
        }

        Rectangle {
            id: contentIndeterminate
            property int xEnd: parent.width / 3
            width: xEnd - x
            height: parent.height
            radius: Style.progressBar._Height / 2
            color: Style._ColorAccent
            antialiasing: false


            visible: progressBar.indeterminate

            ParallelAnimation {
                running: true

                SequentialAnimation {
                    loops: Animation.Infinite


                    NumberAnimation {
                        target: contentIndeterminate
                        property: "x"
                        from: 0
                        to: 0
                        duration: 300
                        easing.type: Easing.Linear
                    }

                    NumberAnimation {
                        target: contentIndeterminate
                        property: "x"
                        from: 0
                        to: content.width
                        duration: 1000
                        easing.type: Easing.Linear
                    }

                }


                SequentialAnimation {
                    loops: Animation.Infinite

                    NumberAnimation {
                        target: contentIndeterminate
                        property: "xEnd"
                        from: 0
                        to: content.width
                        duration: 1000
                        easing.type: Easing.Linear
                    }


                    NumberAnimation {
                        target: contentIndeterminate
                        property: "xEnd"
                        from: content.width
                        to: content.width
                        duration: 300
                        easing.type: Easing.Linear
                    }
                }

            }
        }
    }
}
