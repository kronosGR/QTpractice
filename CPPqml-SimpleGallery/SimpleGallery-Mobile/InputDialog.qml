import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Window

Dialog {
    property string label: "New Item"
    property string hint: ""
    property alias editText: editTextItem

    standardButtons: StandardButton.Ok | StandardButton.Cancel
    onVisibleChanged: {
        editTextItem.focus = true
        editTextItem.selectAll()
    }

    Rectangle {
        implicitWidth: parent.width
        implicitHeight: 100

        ColumnLayout {
            Text {
                id: labelItem
                text: label
                color: Style.text
            }

            TextInput {
                id: editTextItem
                inputMethodHints: Qt.ImhPreferUppercase
                text: hint
                color: Style.text
            }
        }
    }
}
