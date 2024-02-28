import QtQuick
import QtQuick.Controls
import QtQuick.Window

import me.kandz.dirhelper

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Image Viewer")

    DirHelper {
        id: dirHelper
        path: "D:\\OneDrive\\OneDriveSync\\Screenshots"
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent

        Component.onCompleted: {
            let files = dirHelper.files

            for (var i = 0; i < files.length; i++) {
                console.log("Loading: ", files[i])
                let component = Qt.createComponent("ImagePage.qml")
                let page = component.createObject(swipeView, {
                                                      "width": 640,
                                                      "height": 480
                                                  })
                page.source = "file:///" + files[i]
            }
        }
    }
}
