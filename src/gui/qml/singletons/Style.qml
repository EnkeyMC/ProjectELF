pragma Singleton
import QtQuick 2.0
import projectelf.diagram 1.0

QtObject {

    // COLORS
    readonly property color _ColorPrimaryLight: "#E6EBEF"
    readonly property color _ColorPrimaryDark: "#2C3F4C"
    readonly property color _ColorSecondaryLight: "#C4CCD1"
    readonly property color _ColorSecondaryDark: "#5F6E78"
    readonly property color _ColorAccent: "#4796CC"

    readonly property color _ColorSuccess: "#61cd2e"
    readonly property color _ColorWarning: "#e4b363"
    readonly property color _ColorError: "#db162f"

    readonly property color _ColorTextLight: "#FFFFFF"
    readonly property color _ColorTextDark: "#000000"

    readonly property DiagramStyle _DiagramStyle: DiagramStyle {}

    readonly property QtObject mainMenuBar: QtObject {
        readonly property int _Height: 25
        readonly property int _FontSize: 13
    }

    readonly property QtObject menuItem: QtObject {
        readonly property int _Height: 25
        readonly property int _Width: 200
    }

    readonly property QtObject button: QtObject {
        readonly property int _Height: 25
        readonly property int _FontSize: 13
    }

    readonly property QtObject tabBar: QtObject {
        readonly property int _Height: 25
        readonly property int _Spacing: 2
        readonly property int _TopPadding: 2
    }

    readonly property QtObject statusBar: QtObject {
        readonly property int _Height: 20
    }

    readonly property QtObject statusBarButton: QtObject {
        readonly property int _FontSize: 11
    }

    readonly property QtObject progressBar: QtObject {
        readonly property int _Height: 8
    }

    readonly property QtObject toolBar: QtObject {
        readonly property int _Height: 30
    }

    readonly property QtObject badge: QtObject {
        readonly property int _FontSize: 11
    }
}
