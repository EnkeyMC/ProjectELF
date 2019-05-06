import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

ScrollView {
    id: scroll
    clip: true

    property ELFModel elfModel

    Loader {
        active: elfModel.header !== undefined && elfModel.header.sectionHeaderTable !== undefined && elfModel.header.sectionHeaderTable !== null

        sourceComponent: Component {
            Column {
                id: tableColumnLayout
                width: 0
                spacing: 1

                Connections {
                    target: scroll
                    onAvailableWidthChanged: tableColumnLayout.recalculateWidth()
                }

                signal recalculateWidth()

                onRecalculateWidth: {
                    var minWidth = scroll.availableWidth;
                    for (var i = 0; i < visibleChildren.length; i++) {
                        var child = visibleChildren[i];
                        if (child.minWidth > minWidth)
                            minWidth = child.minWidth;
                    }

                    width = minWidth;
                }

                Component.onCompleted: recalculateWidth()

                Repeater {
                    model: elfModel.header.sectionHeaderTable.sectionHeaderListModel

                    SectionHeaderEditTable {
                        headerModel: model.sectionHeaderModel
                        width: parent.width
                        onImplicitWidthChanged: tableColumnLayout.recalculateWidth()
                    }
                }
            }
        }
    }
}
