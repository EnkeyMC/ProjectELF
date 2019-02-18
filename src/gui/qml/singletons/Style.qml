pragma Singleton
import QtQuick 2.0

QtObject {

    // COLORS
    readonly property color _ColorPrimaryLight: "#E6EBEF"
    readonly property color _ColorPrimaryDark: "#2C3F4C"
    readonly property color _ColorSecondaryLight: "#C4CCD1"
    readonly property color _ColorSecondaryDark: "#5F6E78"
    readonly property color _ColorAccent: "#4796CC"

    readonly property color _ColorTextLight: "#FFFFFF"
    readonly property color _ColorTextDark: "#000000"

    readonly property QtObject mainMenuBar: QtObject {
        readonly property int _Height: 25
        readonly property int _FontSize: 13
    }

    readonly property QtObject menuItem: QtObject {
        readonly property int _Height: 25
        readonly property int _Width: 200
    }
}
