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

    PageSideBarScales {
        id: pageSideBarScales
        x: 66
        y: 170
        width: 77
        height: 88
        anchors.horizontalCenterOffset: -30
        anchors.verticalCenterOffset: -200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
