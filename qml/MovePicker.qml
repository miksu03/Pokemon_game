import QtQuick
import QtQuick.Controls 6.3
import QtQuick.Layouts 6.3
import local.pokemonlistmodel 1.0


Item {

    function reset()
    {
        /* nollaa */
        myClass.mySelectedMoveIn(0, "")
        myClass.mySelectedMoveIn(1, "")
        myClass.mySelectedMoveIn(2, "")
        myClass.mySelectedMoveIn(3, "")
        moveButton1.text = "Click to add"
        moveButton2.text = "Click to add"
        moveButton3.text = "Click to add"
        moveButton4.text = "Click to add"
    }
    ListView {
        id: listView
        anchors.bottom: parent.bottom
        clip: true
        width: parent.width * 0.33
        height: parent.height
        //displayMarginBeginning: - parent.height * 0.085

        delegate: Item {
            x: 5
            width: listView.width
            height: 40
            property string ltext: modelData
            Row {
                id: row1
                Rectangle {

                    width: listView.width * 0.95
                    height: Screen.height / 28
                    color: "#b3cccc"
                    Text {

                        text: modelData
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: index === listView.currentIndex
                    }
                }

                spacing: 12
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    listView.currentIndex = index;
                    //console.log(listView.itemAtIndex(listView.currentIndex).ltext);
                }
            }
        }
        model: pokemonList.currentMoves
    }

    Item {
        id: item1
        width: parent.width * 0.67
        height: parent.height
        x: parent.width * 0.33

        Label {
            id: moveName
            width: parent.width
            height: parent.height * 0.15
            text: listView.model[listView.currentIndex]
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 28
            font.bold: true
            onTextChanged: myClass.myMoveFind(moveName.text)
        }
        ScrollView{
            width: parent.width
            height: parent.height * 0.60
            anchors.bottom: gridLayout.top
            contentWidth: 0
        Text {
            id: moveText
            width: moveName.width*0.95
            text: myClass ? myClass.myMove : "error"
            font.pixelSize: 15
            wrapMode: Text.WordWrap
            clip: true
        }
        }

        GridLayout {
            id: gridLayout
            width: parent.width
            height: parent.height * 0.30
            anchors.bottom: parent.bottom
            columns: 2
            rows: 2

            ToolButton {
                id: moveButton1
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: qsTr("Tool Button")
                onClicked:{
                    if(moveButton1.text != moveName.text &&
                            moveButton2.text != moveName.text &&
                           moveButton3.text != moveName.text &&
                            moveButton4.text != moveName.text){
                    text = moveName.text
                        myClass.mySelectedMoveIn(0, moveName.text)
                    }
                }


            }

            ToolButton {
                id: moveButton2
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: qsTr("Tool Button")
                onClicked:{
                    if(moveButton1.text != moveName.text &&
                            moveButton2.text != moveName.text &&
                           moveButton3.text != moveName.text &&
                            moveButton4.text != moveName.text){
                    text = moveName.text
                        myClass.mySelectedMoveIn(1, moveName.text)
                    }
                }
            }

            ToolButton {
                id: moveButton3
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: qsTr("Tool Button")
                onClicked:{
                    if(moveButton1.text != moveName.text &&
                            moveButton2.text != moveName.text &&
                           moveButton3.text != moveName.text &&
                            moveButton4.text != moveName.text){
                    text = moveName.text
                        myClass.mySelectedMoveIn(2, moveName.text)
                    }
                }
            }

            ToolButton {
                id: moveButton4
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: qsTr("Tool Button")
                onClicked:{
                    if(moveButton1.text != moveName.text &&
                            moveButton2.text != moveName.text &&
                           moveButton3.text != moveName.text &&
                            moveButton4.text != moveName.text){
                        text = moveName.text
                        myClass.mySelectedMoveIn(3, moveName.text)
                    }
                }
            }

    }
  }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/
