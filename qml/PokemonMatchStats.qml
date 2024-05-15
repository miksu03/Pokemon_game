import QtQuick
import QtQuick.Controls
import local.udpclient 1.0

Column {
    width: parent.width
    function testi(pp_index){
        if (userstamina.value <= 0 && uPokmeon.m_pp[pp_index] > 0){
            UdpClient.lowerProgressBarLocal(uPokmeon.speedTime())
            uPokmeon.pp_oneLover(pp_index)
        }
    }
    Row {
        width: parent.width
        Text {
            id:opponentStats
            text: "O"
            rightPadding: 10
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
        }
        Column {
            width: parent.width - opponentStats.width
            spacing: 5
            ProgressBar {
                id:opponentstamina
                width: parent.width
                from: 0
                to: 100
                value: UdpClient.remoteProgressBarValue
            }
            Row {
                width: parent.width
                ProgressBar {
                    id:opponenthealt
                    from: 0
                    to: UdpClient.remotePokemon.maxHp
                    value: UdpClient.remotePokemon.hp
                    width: parent.width - opponenthealtNumber.width
                }
                Text {
                    id:opponenthealtNumber
                    text: UdpClient.remotePokemon.hp
                    font.pointSize: 20
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
    Row {
        width: parent.width
        Text {
            id:userStats
            text: "Y"
            rightPadding: 10
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
        }
        Column {
            width: parent.width - opponentStats.width
            spacing: 5
            ProgressBar {
                id:userstamina
                width: parent.width
                from: 0
                to: 100
                value: UdpClient.localProgressBarValue
            }
            Row {
                width: parent.width
                ProgressBar {
                    id:userHealt
                    from: 0
                    to: UdpClient.localPokemon.maxHp
                    value: UdpClient.localPokemon.hp
                    width: parent.width - userHealtNumber.width
                }
                Text {
                    id:userHealtNumber
                    text: UdpClient.localPokemon.hp
                    font.pointSize: 20
                    verticalAlignment: Text.AlignVCenter
                }
                Component.onCompleted: {
                    console.log("UdpClient.localPokemon: " + UdpClient.localPokemon)
                    console.log("UdpClient.localPokemon.hp: " + UdpClient.localPokemon.hp)
                }
            }
        }
    }
}

