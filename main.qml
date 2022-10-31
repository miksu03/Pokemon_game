import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Pokemon The Game")

    Text {
        id: text1
        x: 150
        y: 60
        width: 350
        height: 60
        text: qsTr("Pokemon The Game")
        font.pixelSize: 36
    }

    Rectangle {
        id: rectangle
        x: 150
        y: 160
        width: 350
        height: 60
        color: "#dcecff"

        Text {
            id: startText
            visible: true
            text: qsTr("Start")
            anchors.fill: parent
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            clip: false

            MouseArea {
                id: start
                anchors.fill: parent
                scrollGestureEnabled: false

                Connections {
                    target: start
                    onClicked: console.log("start.clicked")
                }
            }
        }
    }

    Rectangle {
        id: rectangle1
        x: 150
        y: 300
        width: 350
        height: 60
        color: "#dcecff"

        Text {
            id: quitText
            text: qsTr("Quit")
            anchors.fill: parent
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            MouseArea {
                id: quit
                anchors.fill: parent
                scrollGestureEnabled: false

                Connections {
                    target: quit
                    onClicked: console.log("quit.clicked")
                }
            }
        }
    }

    Rectangle {
        id: rectangle2
        x: 150
        y: 230
        width: 350
        height: 60
        color: "#d3e7ff"

        Text {
            id: modesText
            text: qsTr("Modes")
            anchors.fill: parent
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            MouseArea {
                id: modes
                anchors.fill: parent
                scrollGestureEnabled: false

                Connections {
                    target: modes
                    onClicked: console.log("modes.clicked")
                }
            }
        }
    }
}
