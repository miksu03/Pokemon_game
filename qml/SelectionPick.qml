import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import local.pokemonlistmodel 1.0

Item {
    visible: true
    id: item2
    Item {
        id: item1
        width: parent.width * 0.3
        height: parent.height
        ListView {
            id: pokemonList
            anchors.bottom: parent.bottom
            spacing: 2
            clip: true
            width: parent.width
            height: parent.height * 0.915
            property string currentName: ""
            property var currentAbilities
            property var currentMoves
            function updateCurrentSelection()
            {
                _statText.reset()
                _abilityPicker.reset()
                _movePicker.reset()
                stackView.name = currentName
                userSelection.mySelectedPokemon = currentName
                currentAbilities = pokemonList.model.data(pokemonList.model.index(pokemonList.currentIndex, 0), SearchablePokemonListModel.Role.Abilities)
                currentMoves = pokemonList.model.data(pokemonList.model.index(pokemonList.currentIndex, 0), SearchablePokemonListModel.Role.Moves)
            }
            onCurrentIndexChanged: updateCurrentSelection()

            delegate: Item {
                x: 5
                property bool selectedItem: ListView.isCurrentItem
                property var moves: model.moves
                property var abilities: model.abilities
                property var name: model.name
                width: pokemonList.width
                height: 40
                onSelectedItemChanged: {
                    if (selectedItem)
                    {
                        pokemonList.currentName = name
                        pokemonList.updateCurrentSelection()
                    }
                }

                Row {
                    id: row1

                    Rectangle {

                        width: pokemonList.width * 0.95
                        height: Screen.height / 28
                        color: "#b3cccc"
                        Text {
                            text: model.name
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.bold: selectedItem
                            onTextChanged: {
                                if (selectedItem)
                                {
                                    pokemonList.currentName = name
                                    pokemonList.updateCurrentSelection()
                                }
                            }
                        }
                    }

                    spacing: 12
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        pokemonList.currentName = model.name
                        pokemonList.currentIndex = index
                        userSelection.mySelectedPokemon = model.name
                    }
                }
            }
            model: SearchablePokemonListModel{
                searchString: searchField.text
            }
        }

        Image {
            id: magnifyingGlass
            anchors.right: parent.right
            width: parent.width * 0.2
            height: parent.height * 0.085
            source: "qrc:/qtquickplugin/images/template_image.png"
            fillMode: Image.PreserveAspectFit
        }

        TextField {
            id: searchField
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.02
            width: parent.width * 0.78
            height: parent.height * 0.085
            font.pixelSize: Screen.height * 0.015
            placeholderText: qsTr("search pokemon")
            verticalAlignment: Text.AlignVCenter
            selectionColor: "#c6008dff"
            selectByMouse: true
            mouseSelectionMode: TextInput.SelectCharacters

        }
    }

    TabBar {
        id: row
        width: parent.width * 0.6929
        height: parent.height * 0.085
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 0
        spacing: 6
        TabButton {
            id: statsButton
            text: qsTr("stats")
            onClicked: stackView.currentIndex = 0
        }
        TabButton {
            id: abilityPickerButton
            text: qsTr("Ability")
            onClicked: stackView.currentIndex = 1

        }
        TabButton {
            id: movePickerButton
            text: qsTr("Move")
            onClicked: { stackView.currentIndex = 2;}
        }
        TabButton {
            id: backButton
            text: qsTr("Back")
            checked: true
            onClicked: stack.pop()
        }
        TabButton {
            id: playButton
            text: qsTr("Play")
            checkable: false
            checked: false
            onClicked: {
                if(userSelection.mySelectedMoves.length !== 0){
                    uPokmeon.pokemonSelect(userSelection.mySelectedPokemon);
                    for (var i = 0;userSelection.mySelectedMoves.length>i; i++){
                        uPokmeon.moveSelect(userSelection.mySelectedMoves[i]);
                    }
                    uPokmeon.abilitySelect(userSelection.mySelectedAbility);
                    stack.push("Match.qml");
                }
                //console.log(uPokmeon.m_userMoves[0].m_pp);
            }
        }
    }
    StackLayout {
        id: stackView
        property string name: ""
        x: item2.width * 0.3
        y: row.height
        width: item2.width - item2.width * 0.3
        height: item2.height - row.height
        currentIndex: 0
        StatText {
            id: _statText
        }
        AbilityPicker {
            id: _abilityPicker
        }
        MovePicker {
            id: _movePicker
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/
