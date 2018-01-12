import QtQuick 2.4

PageBackGround {
    id: pageBackGround
    width: 980
    height: 760
    tittle: ""
    PageMainList {
        id: pageMainList
        x: 464
        y: 314
        anchors.verticalCenterOffset: -20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    PageMainLoading {
        id: pageMainLoading
        x: 188
        y: 494
        anchors.horizontalCenterOffset: -50
        anchors.verticalCenterOffset: 150
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
