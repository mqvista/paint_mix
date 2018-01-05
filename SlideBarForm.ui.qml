import QtQuick 2.4

PageBackGround {
    id: pageBackGround
    width: 300
    height: 800
    tittle: "Paint Mix"

    Rectangle {
        id: rectangle
        x: 85
        width: 2
        height: 800
        color: "#ffffff"
        anchors.top: parent.top
        anchors.right: parent.right
    }
}
