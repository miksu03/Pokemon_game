import QtQuick
import QtQuick.Controls 6.3
import QtQuick.Layouts 6.3

Item {
    id: item1
    PokemonMatchStats{
        id:stats
        width: parent.width * 0.7
    }
    ScrollView{
        id: pokemonInfo
        anchors.left: stats.right
        anchors.leftMargin: 0
        height: stats.height
        width: parent.width * 0.3
        contentWidth: 0
        Text {
            id: pokemonInfoText
            text: qsTr("Text\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n onnistui")
            font.pixelSize: 12
            wrapMode: Text.WordWrap
            clip: true
        }
    }
    GridLayout {
        id:moveShower
        width: stats.width
        height: parent.height - stats.height
        anchors.top: stats.bottom
        columns:2
        rows:2
        Repeater {
        model: userSelection.mySelectedMoves
        delegate:
            ToolButton {
                Layout.fillWidth: true
                Layout.fillHeight: true
                text:modelData
                icon.color: "#ffffff"
                onClicked:{console.log(index + userSelection.mySelectedMoves[index])}
            }
        }
    }
    ToolButton {
        id: dodgeButton
        text: qsTr ("Dodge")
        height: moveShower.height / 2
        width: pokemonInfo.width
        anchors.top: pokemonInfo.bottom
        anchors.left: moveShower.right
        icon.color: "#ffffff"
        onClicked:{console.log(index + userSelection.mySelectedMoves[index])}
    }
    ScrollView{
        id: matchInfo
        anchors.left: stats.right
        anchors.leftMargin: 0
        anchors.top: dodgeButton.bottom
        height: PokemonMatchStats.height
        width: parent.width * 0.3
        contentWidth: 0
        Text {
            id: matchInfoText
            text: qsTr("Text")
            font.pixelSize: 12
            wrapMode: Text.WordWrap
            clip: true
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
