import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

PESplitView {
    id: viewEdit
    orientation: Qt.Horizontal

    property ELFModel elfModel

    ColumnLayout {
        id: elfHeaderColumn
        Layout.fillHeight: true
        width: 400
        spacing: 0

        PEToolBar {
            Layout.fillWidth: true

            PEToolBarText {
                text: qsTr("ELF Header")
            }
        }

        ScrollView {
            id: scroll
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            ColumnLayout {
                id: tableColumnLayout
                width: 0
                spacing: 0

                Connections {
                    target: scroll
                    onAvailableWidthChanged: tableColumnLayout.recalculateWidth()
                }

                signal recalculateWidth()

                onRecalculateWidth: {
                    var minWidth = scroll.availableWidth;
                    for (var i = 0; i < visibleChildren.length; i++) {
                        var child = visibleChildren[i];
                        if (child.implicitWidth > minWidth)
                            minWidth = child.implicitWidth;
                    }

                    width = minWidth;
                }

                Component.onCompleted: recalculateWidth()

                IdentificationEditTable {
                    id: identificationEditTable
                    elfModel: viewEdit.elfModel
                    Layout.fillWidth: true

                    onChildrenRectChanged: tableColumnLayout.recalculateWidth()
                }

                Loader {
                    id: headerEditTableLoader
                    Layout.fillWidth: true
                    sourceComponent: active ? headerEditTableComponent : undefined
                    active: elfModel.header

                }

                Component {
                    id: headerEditTableComponent

                    HeaderEditTable {
                        id: headerEditTable
                        headerModel: viewEdit.elfModel.header
                        width: parent.width

                        onChildrenRectChanged: tableColumnLayout.recalculateWidth()
                    }
                }
            }
        }
    }

    ColumnLayout {
        id: sectionHeaderColumn
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: 0

        PEToolBar {
            id: headersToolBar
            Layout.fillWidth: true

            property int currentIndex: firstButon.checked ? 0 : 1

            RowLayout {
                anchors.fill: parent
                spacing: 0

                PEToolBarButton {
                    id: firstButon
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    autoExclusive: true
                    checkable: true
                    checked: true
                    text: qsTr("Section headers")
                }

                PEToolBarButton {
                    clip: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    autoExclusive: true
                    checkable: true
                    text: qsTr("Program headers")
                }
            }
        }

        StackLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            currentIndex: headersToolBar.currentIndex

            SectionHeadersEdit {
                Layout.fillHeight: true
                Layout.fillWidth: true

                elfModel: viewEdit.elfModel
            }

            ProgramHeadersEdit {
                Layout.fillHeight: true
                Layout.fillWidth: true

                elfModel: viewEdit.elfModel
            }
        }
    }
}
