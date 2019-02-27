import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../singletons"
import "../controls"

Item {
    id: expandableItem
    height: 0
    clip: true
    
    PETable {
        id: table
        columns: 2
        width: parent.width
        
        PETableHeader {
            text: "text"
        }
        
        PETableHeader {
            text: "header"
        }
        
        PETableCell {
            Text {
                text: "Preettteeyy"
            }
        }
        
        PETableEditableCell {
            placeholderText: "editable cell"
        }
        
        PETableCell {
            Text {
                text: "llooongg"
            }
        }
        
        PETableEditableCell {
            placeholderText: "editable cell"
        }
    }
    
    states: [
        State {
            name: "expanded"
            PropertyChanges {
                target: expandableItem
                height: expandableItem.childrenRect.height
            }
        }
        
    ]
    
    
}
