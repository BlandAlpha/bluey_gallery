import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import "../window"
import "../global"

FluScrollablePage{

    launchMode: FluPageType.SingleTask
    header: Item{}

    Item{
        Layout.fillWidth: true
        Layout.preferredHeight: 320
        Image {
            id: bg
            fillMode:Image.PreserveAspectCrop
            anchors.fill: parent
            verticalAlignment: Qt.AlignVCenter
            sourceSize: Qt.size(1920,1080)
            source: "qrc:/res/img/charactersBanner.jpg"
        }

        // Banner Overlay
        Rectangle{
            anchors.fill: parent
            gradient: Gradient{
                GradientStop { position: 0.5; color: FluTheme.dark ? "#a6323232" : "#80f3f3f3" }
                GradientStop { position: 1.0; color: FluTheme.dark ? "#323232" : "#f3f3f3" }
            }
        }

        ColumnLayout{
            spacing: 8
            anchors{
                top: parent.top
                left: parent.left
                topMargin: 96
                leftMargin: 48
            }
            FluText{
                text:qsTr("Characters")
                font: FluTextStyle.TitleLarge
            }
            FluText{
                text:qsTr("Meet with your best buddies.")
                font: FluTextStyle.Body
            }


        }

    }

    FluText{
        text: "Bluey's Closest Friends"
        font: FluTextStyle.Title
        Layout.topMargin: 24
        Layout.leftMargin: 24
    }

    GridView{
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        cellHeight: 120
        cellWidth: 320
        /*
        model:ItemsOriginal.getRecentlyAddedData()
        interactive: false
        delegate: com_item
        */
    }

    FluText{
        text: "Supportive Characters"
        font: FluTextStyle.Title
        Layout.topMargin: 24
        Layout.leftMargin: 24
    }

    GridView{
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        cellHeight: 120
        cellWidth: 320
        /*
        interactive: false
        model: ItemsOriginal.getRecentlyUpdatedData()
        delegate: com_item
        */
    }

}

