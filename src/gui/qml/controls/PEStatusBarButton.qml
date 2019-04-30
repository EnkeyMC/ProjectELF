import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"

Button {
    id: statusBarButton

    padding: 0
    property string badgeText: ""
    property color badgeColor: "transparent"
    property color badgeTextColor: "black"

    contentItem: RowLayout {
        height: statusBarButton.height
        anchors.horizontalCenter: statusBarButton.horizontalCenter

        Spacer {
            width: 5
        }

        PEBadge {
            Layout.alignment: Qt.AlignVCenter
            text: statusBarButton.badgeText
            color: statusBarButton.badgeColor
            textColor: statusBarButton.badgeTextColor
            visible: text != ""
        }

        Text {

            Layout.fillHeight: true;
            text: statusBarButton.text
            font.pixelSize: Style.statusBarButton._FontSize
            color: Style._ColorTextLight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Spacer {
            width: 5
        }
    }

    background: Rectangle {
        implicitHeight: Style.statusBar._Height
        implicitWidth: 50

        color: (statusBarButton.down ||
                statusBarButton.checked)
             ?
                    Style._ColorAccent
             :
                (statusBarButton.highlighted ||
                statusBarButton.visualFocus ||
                statusBarButton.hovered)
             ?
                    Qt.darker(Style._ColorAccent, 1.1)
             :
                    Style._ColorPrimaryDark
    }
}
