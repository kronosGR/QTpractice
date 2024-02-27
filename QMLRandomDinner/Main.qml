import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Random Dinner")

    property variant places: ["Gyros", "Mousakas", "Spanakopita", "Pastitsio", "Papoutsakia"]
    MouseArea {
        id: area
        anchors.fill: parent

        onClicked: {
            aniStart.stop()
            aniFadeOut.stop()
            lblPlace.font.pixelSize = 45
            lblPlace.opacity = 0
            lblPlace.rotation = 0.0

            aniFadeOut.start()
        }

        Label {
            id: lblPlace
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: 25
            color: black
            text: "Tap me"
        }
    }

    function pick() {
        let i = Math.floor(Math.random() * places.length)
        lblPlace.text = places[i]
        aniSelection.start()
    }

    SequentialAnimation {
        id: aniStart
        running: true
        loops: Animation.Infinite
        NumberAnimation {
            target: lblPlace
            property: "font.pixelSize"
            to: 45
            duration: 1000
        }
        NumberAnimation {
            target: lblPlace
            property: "font.pixelSize"
            to: 25
            duration: 1000
        }
    }

    OpacityAnimator {
        id: aniFadeOut
        running: false
        target: lblPlace
        from: 1
        to: 0
        duration: 1000
        onFinished: pick()
    }

    ParallelAnimation {
        id: aniSelection
        running: false

        NumberAnimation {
            target: lblPlace
            property: "font.pixelSize"
            from: 0
            to: 25
            duration: 2000
            easing.type: Easing.InOutQuad
        }

        OpacityAnimator {
            target: lblPlace
            from: 0
            to: 1
            duration: 1000
        }

        RotationAnimation {
            target: lblPlace
            from: 0
            to: 1
            duration: 2000
            direction: RotationAnimation.Counterclockwise
        }
    }
}
