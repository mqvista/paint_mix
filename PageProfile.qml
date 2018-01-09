import QtQuick 2.4
import QtQml 2.2

PageProfileForm {


    buttonAddNew.onClicked: {
        PageProfileDialog.show();
        Qt.createComponent("PageProfileDialog.qml").createObject(PageProfile);
        //Loader.source = "ageProfileDialog.qml"
    }
}
