import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

Column {
    id: peTermDefinition

    property string term: ""
    property string definition: ""

    Label {
        text: peTermDefinition.term
        textFormat: Text.RichText
    }
    
    Label {
        text: peTermDefinition.definition
        textFormat: Text.RichText
        leftPadding: 20
    }
}
