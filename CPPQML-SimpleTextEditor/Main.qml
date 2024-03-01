import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs

import me.kandz.backend

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Simple Text Editor")

    Backend {
        id: backend
        onPathChanged: console.log("Path: ", path)
        onDataChanged: console.log("Data: ", data)
    }

    FileDialog {
        id: openDialog
        title: "Please choose a file"
        nameFilters: ["Text files (*.txt)", "HTML files (*.html *.htm)"]
        onAccepted: {
            backend.path = openDialog.currentFile
            editor.text = backend.data
        }
    }

    FileDialog {
        id: saveDialog
        title: "Please choose a file"
        nameFilters: ["Text files (*.txt)", "HTML files (*.html *.htm)"]

        onAccepted: {
            backend.path = saveDialog.currentFile
            backend.data = editor.text
        }
    }

    Action {
        id: actionNew
        text: qsTr("New")
        icon.color: "transparent"
        icon.source: "qrc:/icons/oNew.png"
        onTriggered: editor.clear()
    }

    Action {
        id: actionOpen
        text: qsTr("Open")
        icon.color: "transparent"
        icon.source: "qrc:/icons/oOpen.png"
        onTriggered: openDialog.open()
    }

    Action {
        id: actionSave
        text: qsTr("Save")
        icon.color: "transparent"
        icon.source: "qrc:/icons/oSave.png"
        onTriggered: saveDialog.open()
    }

    Action {
        id: actionCopy
        text: qsTr("Copy")
        icon.color: "transparent"
        icon.source: "qrc:/icons/oCopy.png"
        onTriggered: editor.copy()
    }

    Action {
        id: actionCut
        text: qsTr("Cut")
        icon.color: "transparent"
        icon.source: "qrc:/icons/oCut.png"
        onTriggered: editor.cut()
    }

    Action {
        id: actionPaste
        text: qsTr("Paste")
        icon.color: "transparent"
        icon.source: "qrc:/icons/oPaste.png"
        onTriggered: editor.paste()
    }

    menuBar: MenuBar {
        Menu {
            id: menuFile
            title: qsTr("File")
            MenuItem {
                action: actionNew
            }
            MenuItem {
                action: actionOpen
            }
            MenuItem {
                action: actionSave
            }
        }
        Menu {
            id: menuEdit
            title: qsTr("Edit")
            MenuItem {
                action: actionCopy
            }
            MenuItem {
                action: actionCut
            }
            MenuItem {
                action: actionPaste
            }
        }
    }

    header: ToolBar {
        Row {
            ToolButton {
                display: AbstractButton.IconOnly
                action: actionNew
            }
            ToolButton {
                display: AbstractButton.IconOnly
                action: actionOpen
            }
            ToolButton {
                display: AbstractButton.IconOnly
                action: actionSave
            }
            ToolButton {
                display: AbstractButton.IconOnly
                action: actionCopy
            }
            ToolButton {
                display: AbstractButton.IconOnly
                action: actionCut
            }
            ToolButton {
                display: AbstractButton.IconOnly
                action: actionPaste
            }
        }
    }

    ScrollView {
        anchors.fill: parent
        TextArea {
            id: editor
            focus: true
            text: "New text"
            selectByMouse: true
            persistentSelection: true // for copy and paste
        }
    }
}
