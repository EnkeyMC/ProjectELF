import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

Column {
    id: termDefinition

    property string key: ""
    property string value: ""

    Label {
        id: key
        text: termDefinition.key
        textFormat: Text.RichText
    }
    
    Label {
        id: value
        text: termDefinition.value
        textFormat: Text.RichText
        leftPadding: 20
    }
}
