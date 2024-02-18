import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Feet Inches Converter")

    function convert() {
        var value = txtFrom.text
        var ret = 0
        switch (cmbType.currentIndex) {
        case 0:
            ret = inch_to_feet(value)
            break
        case 1:
            ret = feet_to_inch(value)
            break
        }
        lblResult.text = ret
    }

    function inch_to_feet(value) {
        return value / 12
    }

    function feet_to_inch(value) {
        return value * 12
    }

    Column {
        id: column
        width: 250
        height: 196
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Grid {
            id: grid
            width: 250
            height: 150
            spacing: 10
            rows: 3
            columns: 2

            Label {
                id: label
                text: qsTr("Type:")
            }

            ComboBox {
                id: cmbType
                model: ListModel {
                    id: cbItems
                    ListElement {
                        text: "Inches to Feet"
                    }
                    ListElement {
                        text: "Feet to Inches"
                    }
                }
            }

            Label {
                id: label1
                text: qsTr("From:")
            }

            TextField {
                id: txtFrom
                placeholderText: qsTr("Text Field")
            }

            Label {
                id: label2
                text: qsTr("Result:")
            }

            Label {
                id: lblResult
                text: qsTr("Nothing")
                font.pointSize: 15
            }
        }

        Button {
            id: button
            text: qsTr("Convert")
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: convert()
        }
    }
}
