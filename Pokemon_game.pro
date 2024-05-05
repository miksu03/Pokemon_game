QT += quick quickcontrols2

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        abilities.cpp \
        ailments.cpp \
        attack.cpp \
        calculations.cpp \
        filereader.cpp \
        listfinder.cpp \
        main.cpp \
        moves.cpp \
        pokedex.cpp \
        pokemonlistmodel.cpp \
        searchablepokemonlistmodel.cpp \
        status.cpp \
        udpclient.cpp \
        userpokemon.cpp \
        userselected.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abilities.h \
    ailments.h \
    attack.h \
    calculations.h \
    filereader.h \
    listfinder.h \
    moves.h \
    pokedex.h \
    pokemonlistmodel.h \
    searchablepokemonlistmodel.h \
    status.h \
    udpclient.h \
    userpokemon.h \
    userselected.h
