import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    width: 315
    height: 100

    RowLayout {
        x: 0
        y: 0
        spacing: 100
        visible: pageMainModel.busy

        AnimatedImage {
            id: loadingGif;
            Layout.preferredHeight: 100
            Layout.preferredWidth: 100
            source: "qrc:/images/loading.gif"
            playing: true;
        }

        Label {
            id: label
            color: "#ffffff"
            text: qsTr("RUNNING")
            font.pointSize: 33
        }
    }

}
