import QtQuick 2.4

Item {
    id: item1
    width: 1280
    height: 760

    PageMainLists {
        id: pageMainLists
        x: 522
        y: 366
        anchors.verticalCenterOffset: 25
        anchors.rightMargin: 19
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
    }

    PageMainArray {
        id: pageMainArray
        x: 18
        y: 80
        anchors.horizontalCenterOffset: -160
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: -100
        anchors.verticalCenter: parent.verticalCenter
    }

    PageMainRun {
        id: pageMainRun
        x: 674
        y: 522
        anchors.verticalCenterOffset: 180
        anchors.horizontalCenterOffset: 150
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
