import QtQuick
import local.pokemonlistmodel 1.0

Item {
    function reset()
    {
        /* nollaa */
        myClass.myPokemonFind(pokemonList.model.data(pokemonList.model.index(pokemonList.currentIndex, 0)))
    }

    Text {
        id: text1
        text: myClass ? myClass.myPokemon : "error"
        anchors.fill: parent
        font.pixelSize: 22
        verticalAlignment: Text.AlignVCenter
        rightPadding: 12
        leftPadding: 12
    }
}
