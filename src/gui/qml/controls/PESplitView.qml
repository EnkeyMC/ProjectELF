import QtQuick 2.9
import QtQuick.Controls 1.4 as QQC1

import "../singletons"

QQC1.SplitView {
    id: splitView

    handleDelegate: Rectangle {
        color: Style._ColorSecondaryLight
        width: 3
    }
}
