import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: item1
    width: 500
    height: 100

    ListView {
        id: listView
        width: 500
        height: 100
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        model: pageFactoryMod.dirverDebugInfo
        delegate:Rectangle{
            height: 20
            Text {
                text: modelData;
                anchors.left: parent.left
                color: "#ffffff"
            }
        }
    }
}
