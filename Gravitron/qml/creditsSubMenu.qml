import QtQuick 2.0
import QMLFileReader 1.0


Rectangle {
    height: 100
    width: 100

    Text {
        id: txt_credits
    }

    QMLFileReader {
        id: myFile
        source: ":/text/credits.html"
        onError: console.log(msg)
    }

    Component.onCompleted: {
        txt_credits.text =  myFile.read();
        console.log(txt_credits.text)
    }
}
