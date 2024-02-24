import QtQuick
import QtQuick.Controls
import "."

ApplicationWindow {
    readonly property alias pageStack: stackView

    id: app
    width: 768
    height: 1280
    visible: true

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: AlbumListPage
    }

    onClosing: {
        if (Qt.platform.os == "andoird") {
            if (stackView.depth > 1) {
                close.accepted = false
                stackView.pop()
            }
        }
    }
}
