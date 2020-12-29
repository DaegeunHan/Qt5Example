import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }

    ProgressBar {
        objectName: "progressBarObj"
        id: progressBar
        x: 35
        y: 106
        width: 531
        height: 22
        to: 100
        value: 0

        signal update(int val)
        onUpdate: value = val
    }
}
