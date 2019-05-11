import QtQuick 2.11
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
        active: elfModel && elfModel.header && elfModel.header.sectionHeaderTable

        sourceComponent: Component {
            ListView {
                id: listView
                width: 0
                spacing: 1
                height: scroll.availableHeight
                model: elfModel.header.sectionHeaderTable.sectionHeaderListModel

                Connections {
                    target: scroll
                    onAvailableWidthChanged: listView.recalculateWidth()
                }

                signal recalculateWidth()

                onRecalculateWidth: {
                    var minWidth = scroll.availableWidth;
                    for (var i = 0; i < contentItem.visibleChildren.length; i++) {
                        var child = contentItem.visibleChildren[i];
                        if (child.minWidth > minWidth)
                            minWidth = child.minWidth;
                    }

                    width = minWidth;
                }

                Component.onCompleted: recalculateWidth()


                delegate: SectionHeaderEditTable {
                    headerModel: model.sectionHeaderModel
                    width: parent.width
                    onImplicitWidthChanged: listView.recalculateWidth()
                }
            }
        }
    }
}
