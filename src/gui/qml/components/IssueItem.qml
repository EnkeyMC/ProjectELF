import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import projectelf.models 1.0

import "../singletons"
import "../controls"

Label {
    padding: 10
    text: model.description
    color: Style._ColorTextLight
    wrapMode: Label.WordWrap

    property QtObject issueModel: QtObject{
        property string description: ""
    }

    background: Rectangle {
        color: Style._ColorSecondaryDark
    }
}
