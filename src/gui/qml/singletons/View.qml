pragma Singleton
import QtQuick 2.0

QtObject {
    readonly property int _ViewOverview: 0
    readonly property int _ViewEdit: 1

    property int currentView: _ViewOverview
}
