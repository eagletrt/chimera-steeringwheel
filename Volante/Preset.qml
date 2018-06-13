import QtQuick 2.7

Rectangle {
    id: root

    radius: this.width

    property int index
    property int currentIndex

    color: '#333'

    onCurrentIndexChanged: {
        if (currentIndex == root.index) {
            root.state = 'active'
        } else {
            root.state = 'notactive'
        }
    }

    states: [
        State {
            name: 'active'
            PropertyChanges {
                target: root
                color: 'blue'
            }
        }
    ]

    Text {
        id: text
        text: "P" + root.index
        anchors.centerIn: parent
        font.pointSize: 9
        color: "white"
    }
}
