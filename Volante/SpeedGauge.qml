import QtQuick 2.7

Rectangle {

    property int velocity: CarStatus.velocity

    onVelocityChanged: {
        console.log("Cambio di velocità!");
        console.log(velocity);

        text.text = "" + velocity
    }

    color: "transparent"
    Text {
        id: text
        text: "0"
        font.pointSize: 70
        anchors.horizontalCenter: parent.horizontalCenter 
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -5
        color: "white"
    }

    Text {
        text: "kmh"
        anchors.horizontalCenter: parent.horizontalCenter 
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 50 
        color: "white"
    }
}
