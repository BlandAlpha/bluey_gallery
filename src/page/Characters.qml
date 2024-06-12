import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import "../window"
import "../global"
import DBManager 1.0
import Characters 1.0

FluScrollablePage{

    launchMode: FluPageType.SingleTask
    header: Item{}

    DatabaseManager {
        id: dbManager
    }

    CharacterModel {
        id: charactersModel
    }

    Item{
        Layout.fillWidth: true
        Layout.preferredHeight: 320
        Image {
            id: bg
            fillMode:Image.PreserveAspectCrop
            anchors.fill: parent
            verticalAlignment: Qt.AlignVCenter
            sourceSize: Qt.size(2560, 1440)
            source: "qrc:/res/img/charactersBanner.jpg"
        }

        // Banner Overlay
        Rectangle{
            anchors.fill: parent
            gradient: Gradient{
                GradientStop { position: 0.5; color: FluTheme.dark ? "#a6191919" : "#33f3f3f3" }
                GradientStop { position: 1.0; color: FluTheme.dark ? "#191919" : "#f3f3f3" }
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

    Component {
        id: com_character
        Item {
            property string desc: model.description
            property string name: model.name_zh
            property string img: model.image_path
            width: 240
            height: 380
            FluFrame {
                radius: 8
                width: 240
                height: 380
                anchors.centerIn: parent
                Rectangle {
                    anchors.fill: parent
                    radius: 8
                    color: {
                        if(item_mouse.containsMouse){
                            return FluTheme.itemHoverColor
                        }
                        return FluTheme.itemNormalColor
                    }
                }
                ColumnLayout {
                    anchors {
                        top: parent.top
                        topMargin: 24
                        left: parent.left
                        right: parent.right
                        leftMargin: 24
                        rightMargin: 24
                    }
                    spacing: 24
                    anchors.horizontalCenter: parent.horizontalCenter
                    Image {
                        id:item_avatar
                        height: 232
                        width: 150
                        sourceSize: Qt.size(150, 232)
                        fillMode: Image.PreserveAspectFit
                        source: Qt.resolvedUrl(img)
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    ColumnLayout{
                        anchors {
                            left: parent.left
                            right: parent.right
                            horizontalCenter: parent.horizontalCenter
                        }
                        spacing: 8
                        FluText {
                            id: item_name
                            text: name
                            font: FluTextStyle.Subtitle
                            horizontalAlignment: FluText.AlignHCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        FluText{
                            id:item_desc
                            text: desc
                            Layout.preferredWidth: parent.width
                            Layout.alignment: Qt.AlignHCenter
                            color:FluColors.Grey120
                            wrapMode: Text.WordWrap
                            font: FluTextStyle.Caption
                            maximumLineCount: 2
                            elide: Text.ElideRight
                            lineHeight: 1.2
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }
                MouseArea{
                    id:item_mouse
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        ItemsOriginal.startPageByItem(modelData)
                    }
                }

            }
        }
    }

    FluFilledButton {
        anchors.left: parent.left
        anchors.leftMargin: 24
        text: "添加角色"
    }

    GridView {
        id: charactersCards
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        Layout.topMargin: 16
        cellHeight: 380 + 24
        cellWidth: 240 + 24
        interactive: false
        model: charactersModel
        delegate: com_character
        Layout.leftMargin: 24
    }

    Component.onCompleted: {
        charactersModel.setCharacters(dbManager.getCharacters());
    }

}

