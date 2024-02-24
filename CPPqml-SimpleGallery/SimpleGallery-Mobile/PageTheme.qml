import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "."

Page {
    property alias toolbarButtons: buttonLoader.sourceComponent
    property alias toolbarTitle: titleLabel.text

    header: ToolBarTheme {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                background: Image {
                    source: "qrc:/icons/res/back-to-gallery.png"
                }
                onClicked: {
                    if (stackView.depth > 1) {
                        stackView.pop()
                    }
                }
            }
            Label {
                id: titleLabel
                Layout.fillWidth: true
                color: Style.text
                elide: Text.ElideRight
                font.pointSize: 30
            }
            Loader {
                Layout.alignment: Qt.AlignRight
                id: buttonsLoader
            }
        }
    }

    Rectangle {
        color: Style.pageBackground
        anchors.fill: parent
    }
}
