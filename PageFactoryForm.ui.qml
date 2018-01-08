import QtQuick 2.4
import QtQuick.Controls 2.3

PageBackGround {
    id: pageBackGround
    width: 980
    height: 800
    tittle: "Factory Mode"

    PageFactoryControl {
        width: 750
        height: 100
        clip: false
        visible: true
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 60
    }

    PageFactoryEncoder {
        id: pageFactoryEncoder
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 180
    }

    PageFactoryDebug {
        id: pageFactoryDebug
        height: 150
        anchors.left: parent.left
        anchors.leftMargin: 300
        anchors.top: parent.top
        anchors.topMargin: 180
    }

    PageFactoryLimit {
        y: 394
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottomMargin: 50
        anchors.bottom: parent.bottom
    }

    PageFactoryInitAsix {
        id: pageFactoryInitAsix
        y: 428
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 350
        anchors.left: parent.left
        anchors.leftMargin: 650
    }
}
