import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

Rectangle {
    id: statusBar
    color: Style._ColorPrimaryDark
    height: Style.statusBar._Height

    property ELFIssueListModel issueListModel: ELFIssueListModel{}

    RowLayout {
        anchors.fill: parent

        Spacer {
            width: 5
        }

        Spacer {
            Layout.fillWidth: true
        }

        PEStatusBarButton {
            Layout.fillHeight: true
            text: qsTr("Issues")
            badgeText: issueListView.count
            badgeColor: Style._ColorError
            badgeTextColor: Style._ColorTextLight

            onClicked: dropdown.toggle();

            Rectangle {
                id: dropdown
                height: open ? Math.min(issueListView.contentHeight, 400) : 0
                width: 200
                color: Style._ColorSecondaryDark
                z: 100
                anchors.bottom: parent.top
                anchors.right: parent.right

                property bool open: false

                signal toggle()
                signal open()
                signal close()

                onToggle: open = !open

                onOpen: open = true

                onClose: open = false

                MouseArea {
                    anchors.fill: parent
                    z: 101
                }

                ListView {
                    id: issueListView
                    model: statusBar.issueListModel
                    anchors.fill: parent
                    z: 102
                    clip: true

                    delegate: Text {
                        text: model.description
                        color: Style._ColorTextLight
                    }
                }
            }
        }
    }
}
