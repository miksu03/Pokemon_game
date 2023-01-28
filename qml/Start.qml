import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Pane {
    Label {
        id: text1
        x: 150
        y: 60
        width: 350
        height: 60
        text: qsTr("Pokemon The Game")
        font.pixelSize: 36
    }

    Column
    {
        spacing: 10
        anchors.centerIn: parent
        MainWindowButton {
            id: _startButton
            text: qsTr("Start")
            onClicked: stack.push("SelectionPick.qml")
        }
        MainWindowButton {
            id: _modesButton
            text: qsTr("Modes")
            onClicked: console.log("modes.clicked")
        }
        MainWindowButton {
            id: _quitButton
            text: qsTr("Quit")
            onClicked: {
                Qt.quit()
            }
        }
    }
}
