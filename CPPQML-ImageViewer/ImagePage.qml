import QtQuick
import QtQuick.Controls
import QtQuick.Window

Item {
    property alias source: image.source

    Page {
        anchors.fill: parent

        Image {
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "https://images.hindustantimes.com/tech/img/2020/09/24/960x540/Untitled_design_(12)_1600925482551_1600925492949.png"
        }
    }
}
