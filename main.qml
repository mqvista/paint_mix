import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import QtQuick.Extras 1.4

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 1280
    height: 800
    title: qsTr("Paint Mix")
    Material.theme: Material.Dark
    Material.accent: Material.DeepOrange

    StackLayout {
        id: stackLayOut
        anchors.left: slideBar.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        currentIndex: tabBar.currentIndex

        PageMain {

        }

        PageProfile {

        }

        PageSettings {

        }

        PageFactory{

        }
    }

    TabBar {
        id: tabBar
        anchors.right: parent.right
        anchors.left: slideBar.right
        anchors.bottom: parent.bottom
        currentIndex: stackLayOut.currentIndex
        TabButton {
            id: tabButtonMain
            text: qsTr("Main")
        }
        TabButton {
            id: tabButtonProfile
            text: qsTr("Profile")
        }
        TabButton {
            id: tabButtonSetting
            text: qsTr("Setting")
        }

        TabButton {
            id: tabButtonFactory
            text: qsTr("Factory Mode")
        }
    }

    SlideBar {
        id: slideBar
    }
}
