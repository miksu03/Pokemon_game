import QtQuick
import QtQuick.Controls 6.3
import QtQuick.Layouts 6.3
import local.pokemonlistmodel 1.0

Item {

    function reset()
    {
        /* nollaa */
        userSelection.mySelectedAbility = ""
        abilityButton.text = "Click to add"
    }

    ListView {
        id: listAbility
        anchors{ bottom: parent.bottom}
        clip: true
        width: parent.width * 0.33
        height: parent.height
        //displayMarginBeginning: - parent.height * 0.085

        delegate: Item {
            x: 5
            width: listAbility.width
            height: 40
            property string atext: modelData
            Row {
                id: row1
                Rectangle {

                    width: listAbility.width * 0.95
                    height: Screen.height / 28
                    color: "#b3cccc"
                    Text {

                        text: modelData
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: index === listAbility.currentIndex
                    }
                }

                spacing: 12
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    listAbility.currentIndex = index;
                }
            }
        }
        model: pokemonList.currentAbilities
    }

    Item {
        id: item1
        width: parent.width * 0.67
        height: parent.height
        x: parent.width * 0.33

        Label {
            id: abilityName
            width: parent.width
            height: parent.height * 0.15
            text: listAbility.model[listAbility.currentIndex]
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 28
            font.bold: true
            onTextChanged: myClass.myAbilityFind(abilityName.text)
        }
        ScrollView{
            anchors.bottom: abilityButton.top
            width: parent.width
            height: parent.height * 0.60
            contentWidth: 0

            Text {
                id: abilityText
                width: abilityName.width*0.95
                text: myClass ? myClass.myAbility : "error"
                wrapMode: Text.WordWrap
                font.pixelSize: 16
                clip: true
            }
        }


        ToolButton {
            id: abilityButton
            width: parent.width
            height: parent.height * 0.25
            anchors.bottom: parent.bottom
            text: qsTr("Tool Button")
            onClicked:{
                text = abilityName.text
                userSelection.mySelectedAbility = abilityName.text
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/
