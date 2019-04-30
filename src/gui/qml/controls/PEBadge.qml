import QtQuick 2.9
import QtQuick.Controls 2.4


Rectangle {
    id: badge
    smooth: true

    property alias text: label.text
    property alias textColor: label.color

    radius: height / 2

    height: 14
    width: label.text.length > 1 ? label.paintedWidth + height / 2 : height

    Label {
        id: label
        font.pixelSize: 10
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
