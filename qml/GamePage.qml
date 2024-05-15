import QtQuick
import local.udpclient 1.0

Item {
    Match{
        visible: UdpClient.ready
        anchors.fill: parent
    }
    IPAddressSelecter{
        anchors.fill: parent
        visible: !UdpClient.ready
    }
}
