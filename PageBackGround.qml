import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2


Rectangle {
    Material.theme: Material.Dark
    Material.accent: Material.Orange
    width: 1280
    height: 800
    color: "#191919"
    property alias tittle: tittleLab.text

    Rectangle {
        id: rectangle
        x: 1110
        y: -128
        width: 400
        height: 200
        color: "#3a3a3a"
        clip: true
        rotation: 45
        border.width: 1
    }

    Label {
        id: tittleLab
        x: 8
        y: 18
        color: "#ffffff"
        text: qsTr("Label")
        font.pointSize: 22
    }
}
