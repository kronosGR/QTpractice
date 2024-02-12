import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

Window {
    id: window
    width: 400
    height: 400
    visible:true
    title: qsTr("Square Meter Calculator")

    color: "#EAEAEA"

    function calc(){
        var num = sbWidth.value * sbHeight.value;
        label.text = num + " sqm"
    }

    ColumnLayout {
        id: columnLayout
        width: 220
        height: 172
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: label
            text: qsTr("0 sqm")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 25
        }

        Grid {
            id: grid
            width: 400
            height: 400
            spacing: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            rows: 2
            columns: 2

            Label {
                id: label1
                text: qsTr("Width")
            }

            SpinBox {
                id: sbWidth
            }

            Label {
                id: label2
                text: qsTr("Height")
            }

            SpinBox {
                id: sbHeight
            }

        }
    }

    Connections{
        target: sbWidth
        onValueModified: calc()
    }

    Connections{
        target:sbHeight
        onValueModified: calc()
    }
}
