import QtQuick 2.7

Rectangle {
    id: root

    property int defaultPadding: 40

    property int defaultDuration: 1000
    property string defaultBgColor: "white"
    property string deafultTextColor: "black"

    signal show(string line, int duration, string bgColor, string textColor)

    color: "white"
    radius: 10
    visible: false
    onShow: {
        metrics.text = line;
        root.width = metrics.boundingRect.width + defaultPadding;
        root.height = metrics.boundingRect.height;
        showAnimation = duration;
        root.color = bgColor;
        message.color = textColor;
        message.text = line;
        if (animation.running)
            animation.restart();
        else
            animation.start();
    }

    TextMetrics {
        id: metrics
        font.pointSize: 32
    }

    SequentialAnimation {
        id: animation

        running: false

        ParallelAnimation {
            PropertyAnimation {
                target: root
                properties: "visible"
                from: false
                to: true
                duration: 0
            }

        }

        ParallelAnimation {
            PropertyAnimation {
                id: showAnimation
                target: root
                properties: "visible"
                from: true
                to: false
                duration: 1000
            }

        }

    }

    Text {
        id: message

        anchors.centerIn: parent
        font.pointSize: 32
    }

}
