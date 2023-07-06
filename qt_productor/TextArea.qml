import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window{
    id: window_1
    width: 640
    height: 480
    visible: true
    title: qsTr("Productor")

    MenuBar {
        id: menubar_1
        width: parent.width
        Menu {
            title: qsTr("Archivo")
            MenuItem {
                text: qsTr("Salir")
                onTriggered: Qt.quit();
            }
        }
    }
    
     Column {
        id: column_1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20

        Row{
            id: row_1
            spacing: 20

            Rectangle {
                id: rectangle_1
                width: 300
                height: 200
                border.width: 1
                border.color: "black"

                TextArea {
                    id: textarea_1
                    focus: true
                    //text: MyCounter.value
                }
            }

        }
    }
}