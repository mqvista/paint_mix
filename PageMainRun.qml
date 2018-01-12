import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: item1
    width: 200
    height: 60
    Button {
        id: button
        x: 194
        y: 214
        width: 200
        height: 60
        text: qsTr("Run It")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 33
        focusPolicy: Qt.NoFocus
        enabled: {
            if (pageMainModel.busy == true)
            {
                return false
            }
            else
                return true;
        }
        onClicked: {
//            console.log(pageMainLists.contactDelegate);
//            pageMainModel.runFromProfile(pageMainLists.listViewMain.currentItem);
        }
    }
}
