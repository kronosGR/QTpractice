import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Image Viewer")

    SwipeView {
        id: swipeView
        anchors.fill: parent
    }
}
