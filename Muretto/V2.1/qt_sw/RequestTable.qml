import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

TableView {
    id: requesteView
    width:175
    height: 280
    frameVisible: false


    TableViewColumn {
        id: requestColumn
        title: "Request"
        role: "request"
        movable: false
        resizable: false
        width: 100
    }

    TableViewColumn {
        id: timeColumn
        title: "Time"
        role: "time"
        movable: false
        resizable: false
        width: 75
    }
}


