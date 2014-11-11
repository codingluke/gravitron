import QtQuick 2.0
import QMLFileReader 1.0


Rectangle {
    //width: parent.width
    //height: parent.height
    width: 1024
    height: 256
    color: "#bbffffff"

    Text {
        id: txt_credits
        textFormat: Text.StyledText

        //wrapMode: Text.WordWrap
    }

    QMLFileReader {
        id: myFile
        source: ":/text/creditsText"
    }

    Component.onCompleted: {
        txt_credits.text =  myFile.read();
    }
}
