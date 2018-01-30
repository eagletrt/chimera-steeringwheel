import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

TableView {
    id: responseView
    width:175
    height: 280
    frameVisible: false

    TableViewColumn {
        id: responseColumn
        title: "Response"
        role: "response"
        movable: false
        resizable: false
        width: 100
    }

    TableViewColumn {
        id: valueColumn
        title: "Value"
        role: "value"
        movable: false
        resizable: false
        width: 75
    }
}
