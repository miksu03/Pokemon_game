import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import local.udpclient 1.0

Item {
    UdpClient{
        id: ip
        }
    visible: true
    width: parent.width
    height: parent.height
    ColumnLayout {
        id: column12
        width: _mainWindow.width
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Label {
            text: ip.getIpAdress()
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: Screen.height * 0.015
            font.bold: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
        }

        TextField {
            id: textField
            Layout.preferredWidth: parent.width*0.33
            font.pixelSize: Screen.height * 0.015
            placeholderText: qsTr("Enter text")
            Layout.alignment: Qt.AlignHCenter
        }

        RowLayout {
            spacing: 10
            Layout.alignment: Qt.AlignHCenter

            Button {
                highlighted: true
                text: qsTr("Back")
                font.pixelSize: Screen.height * 0.015
                onClicked: stack.pop()
            }

            Button {
                highlighted: true
                text: qsTr("Go")
                font.pixelSize: Screen.height * 0.015
                onClicked: {stack.push("Match.qml");}
            }
        }
    }
}

