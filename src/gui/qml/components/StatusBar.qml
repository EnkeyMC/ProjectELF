import QtQuick 2.10
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
            badgeColor: Qt.darker(Style._ColorAccent, 1.3)
            badgeTextColor: Style._ColorTextLight
            checked: dropdown.open

            onClicked: dropdown.toggle();

            PEDropdown {
                id: dropdown
                anchors.bottom: parent.top
                anchors.right: parent.right
                width: 200
                color: Style._ColorPrimaryDark

                Pane {
                    padding: 1
                    anchors.fill: parent
                    background: Rectangle {
                        color: dropdown.color
                    }

                    ListView {
                        id: issueListView
                        model: statusBar.issueListModel
                        anchors.fill: parent
                        clip: true
                        spacing: 1
                        boundsBehavior: Flickable.StopAtBounds
                        boundsMovement: Flickable.StopAtBounds
                        ScrollBar.vertical: ScrollBar{}

                        header: Label {
                            padding: 10
                            text: "No issues"
                            color: Qt.darker(Style._ColorTextLight, 1.3)
                            visible: issueListView.count == 0
                            height: issueListView.count == 0 ? contentHeight + 2*padding : 0
                            width: parent.width

                            background: Rectangle {
                                color: Style._ColorSecondaryDark
                            }
                        }

                        delegate: IssueItem {
                            width: parent.width
                            issueModel: model
                        }
                    }
                }
            }
        }
    }
}
