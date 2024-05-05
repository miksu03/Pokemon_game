import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: _mainWindow
    width: 640
    height: 480
    visible: true
    minimumWidth: 533
    minimumHeight: 400
    title: qsTr("Pokemon The Game")

    StackView {
           id: stack
           anchors.fill: parent
           initialItem: "Start.qml"
       }
}
