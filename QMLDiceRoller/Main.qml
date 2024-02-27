import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Dice Roller")

    function calc() {
        var model = listView.model
        var total = 0

        for (var i = 0; i < model.count; i++) {
            let item = model.get(i)

            if (item.value > 0) {

                // console.log("Name: ", item.name)
                // console.log("number: ", item.number)
                // console.log("value: ", item.value)
                for (var roll = 0; roll < item.value; roll++) {
                    let min = 1
                    let max = item.number

                    let subtotal = Math.floor(Math.random(
                                                  ) * (max - min - 1) + min)
                    console.log("Roll: ", subtotal)
                    total += subtotal
                }
                console.log(total)
            }
            lblTotal.text = "Total: " + total
        }
    }

    Column {
        anchors.fill: parent
        spacing: 10

        ListView {
            id: listView
            width: parent.width
            height: parent.height
            focus: true
            delegate: DiceDelegate {}
            model: DiceModel {}
        }

        Row {
            id: row
            width: parent.width
            height: 50
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Rectangle {
                anchors.fill: parent
                color: "gray"

                Label {
                    id: lblTotal
                    color: "white"
                    text: "Total: 0"
                    font.bold: true
                    font.pointSize: 25
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                }

                Button {
                    id: button
                    text: "Calculate"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    onClicked: calc()
                }
            }
        }
    }
}
