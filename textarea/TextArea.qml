import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow{
    id: root
    visible: true
    width: 820
    height: 600
    title: qsTr("TextArea")
    
    ScrollView {
    id: control
        Row{
            id: textarea_row
            spacing: 10

            TextArea {
                id: textarea_1
                width: 400
                height: 300
                
                
                padding: 5
                color: "black"                
                placeholderText: "Textarea"
                placeholderTextColor: "gray"
                selectByMouse: true
                selectByKeyboard: true
                selectedTextColor: "white"
                selectionColor: "black"
                font{
                    family: "SimSun"
                    pixelSize: 16
                }

            }

        }
    }
}