import QtQuick
import QtQuick.Controls


Column {
    width: parent.width
    Row {
        width: parent.width
        Text {
            id:opponentStats
            text: "O"
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
        }
        Column {
            width: parent.width - opponentStats.width
            spacing: 5
            ProgressBar {
                id:opponentstamina
                width: parent.width
                value: 0.5
            }
            Row {
                width: parent.width
                ProgressBar {
                    id:opponenthealt
                    value: 0.3
                    width: parent.width - opponenthealtNumber.width
                }
                Text {
                    id:opponenthealtNumber
                    text: "123"
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
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
        }
        Column {
            width: parent.width - opponentStats.width
            spacing: 5
            ProgressBar {
                id:userstamina
                width: parent.width
                value: 0.5
            }
            Row {
                width: parent.width
                ProgressBar {
                    id:userHealt
                    value: 0.3
                    width: parent.width - userHealtNumber.width
                }
                Text {
                    id:userHealtNumber
                    text: uPokmeon.hp
                    font.pointSize: 20
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}

