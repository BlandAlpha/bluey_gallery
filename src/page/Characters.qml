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

    property int cardHeight: 330
    property int cardWidth: 200

    // Character Card Component
    Component {
        id: com_character
        Item {
            property string name_zh: model.name_zh
            property string name_en: model.name_en
            property string breed: model.breed
            property string desc: model.description
            property string img: model.image_path

            width: cardWidth
            height: cardHeight
            FluFrame {
                radius: 8
                width: cardWidth
                height: cardHeight
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
                        topMargin: 16
                        left: parent.left
                        right: parent.right
                        leftMargin: 16
                        rightMargin: 16
                    }
                    spacing: 24
                    // anchors.horizontalCenter: parent.horizontalCenter
                    Image {
                        id:item_avatar
                        Layout.preferredHeight: 200
                        Layout.preferredWidth: 128
                        sourceSize: Qt.size(300, 464)
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
                            text: name_zh
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
                        console.debug("Now transmitting", model.name_zh)
                        FluRouter.navigate("/characterWindow", {
                                            "id": model.id,
                                            "name_zh": model.name_zh,
                                            "name_en": model.name_en,
                                            "breed": model.breed,
                                            "desc": model.description,
                                            "image": model.image_path
                        })
                    }
                }

            }
        }
    }

    FluFilledButton {
        anchors.left: parent.left
        anchors.leftMargin: 24
        text: "添加角色"
        onClicked: {
            FluRouter.navigate("/characterAddWindow")
        }
    }

    GridView {
        id: charactersCards
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        Layout.topMargin: 16
        Layout.leftMargin: 24
        cellHeight: cardHeight + 12
        cellWidth: cardWidth + 12
        interactive: false
        model: charactersModel
        delegate: com_character
    }

    Component.onCompleted: {
        charactersModel.setCharacters(dbManager.getCharacters());
    }
}

