import QtQuick
import QtQuick.Window
import QtQuick.Controls
import local.udpclient 1.0

Window {
    id: _mainWindow
    width: 640
    height: 480
    visible: true
    minimumWidth: 533
    minimumHeight: 400
    title: qsTr("Pokemon The Game")
    Binding {
        target: UdpClient
        property: "localPokemon"
        value: uPokmeon
    }

    StackView {
           id: stack
           anchors.fill: parent
           initialItem: "Start.qml"
       }
}
