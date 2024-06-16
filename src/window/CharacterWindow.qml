import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import FluentUI 1.0
import DBManager 1.0
import Episodes 1.0

FluWindow {
    id: window
    width: 800
    height: 640
    minimumWidth: 520
    minimumHeight: 200
    title: "角色详情"
    launchMode: FluWindowType.Standard

    property var argument: ({})

    DatabaseManager {
        id: dbManager
    }

    EpisodeModel {
        id: episodesModel
    }

    ColumnLayout{
        id: c_layout

        spacing: 24

        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
            topMargin: 16
            leftMargin: 16
            rightMargin: 16
        }

        FluFrame {
            id: frame
            Layout.preferredWidth: parent.width
            anchors {
                leftMargin: 12
                rightMargin: 12
            }
            padding: 16

            RowLayout {
                anchors.left: parent.left
                spacing: 24
                Image {
                    id: avatar
                    source: Qt.resolvedUrl(argument.image)
                    sourceSize: Qt.size(200, 310)
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 12
                    FluText {
                        text: argument.name_zh
                        font: FluTextStyle.Title
                    }
                    FluText {
                        text: "英文名：" + argument.name_en
                        font: FluTextStyle.BodyStrong
                    }
                    FluText {
                        text: "品种：" + argument.breed
                        font: FluTextStyle.BodyStrong
                    }
                    FluText {
                        Layout.preferredWidth: frame.width - 260
                        text: "简介：" + argument.desc
                        font: FluTextStyle.Caption
                        wrapMode: Text.WordWrap
                        lineHeight: 1.25
                    }
                }
            }
        }
        FluText {
            text: qsTr("Seen in these Episodes")
            font: FluTextStyle.Title
            Layout.leftMargin: 16
        }

        ListView {
            id: relateEpisodeList
            model: episodesModel
            anchors{
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }
            height: 160
            orientation: ListView.Horizontal
            header: Item{height: 8;width: 8}
            footer: Item{height: 8;width: 8}
            spacing: 24
            ScrollBar.horizontal: FluScrollBar{
                id: scrollbar_header
            }
            clip: false
            delegate: com_episode
        }

        Component.onCompleted: {
            console.debug("Now finding episodes related to CharacterID:", argument.id);
            episodesModel.setEpisodes(dbManager.getRelatedEpisodes(argument.id));
        }

    }

    FluFilledButton {
        text: qsTr("Edit")
        onClicked: {
            // open edit page，也不管
        }
        anchors {
            top: c_layout.top
            right: c_layout.right
            topMargin: 12
            rightMargin: 12
        }
    }

    property int frameHeight: 142
    property int frameWidth: 520
    property real aspectRatio: 16 / 9
    property int imageHeight: frameHeight
    property int imageWidth: Math.round(imageHeight * aspectRatio)


    // Episode Card Component id: com_episode
    Component {
        id: com_episode
        Item {
            property string title: model.title
            property string desc: model.description
            property int season: model.season
            property int episode: model.episode
            property string img: model.image_path
            width: frameWidth
            height: frameHeight
            // clip: true
            FluShadow{
                property int shadow: 4
                id: cardShadow
                radius: 8
                elevation: {
                    if(item_mouse.containsMouse){
                        return shadow+2
                    }
                    return shadow
                }

                anchors.fill: item_card
            }
            FluFrame {
                id: item_card
                radius: 8
                width: frameWidth
                height: frameHeight
                anchors.centerIn: parent
                clip: true
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
                RowLayout {
                    anchors.fill: parent
                    FluClip{
                        id:item_screenshot
                        radius: [7,0,0,7]
                        width: imageWidth
                        height: imageHeight
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        Image {
                            sourceSize: Qt.size(imageWidth, imageHeight)
                            fillMode: Image.PreserveAspectCrop
                            source: Qt.resolvedUrl(img)
                        }
                    }

                    Column {
                        anchors {
                            left: item_screenshot.right
                            leftMargin: 12
                            horizontalCenter: parent.horizontalCenter
                        }
                        spacing: 6
                        FluText {
                            id: item_title
                            text: title
                            font: FluTextStyle.Subtitle
                        }
                        FluText {
                            id:item_se
                            text: "第" + season + "季，第" + episode + "集"
                            // text: season + episode
                            font: FluTextStyle.Body
                            color: FluColors.Grey120
                        }

                        FluText{
                            id:item_desc
                            text: desc
                            width: frameWidth - imageWidth - 24
                            color:FluColors.Grey120
                            wrapMode: Text.WordWrap
                            font: FluTextStyle.Caption
                            maximumLineCount: 2
                            elide: Text.ElideRight
                            lineHeight: 1.125
                        }
                    }
                }
                MouseArea{
                    id:item_mouse
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        FluRouter.navigate("/episodeWindow", {
                                           "id": model.id,
                                           "title": model.title,
                                           "desc": model.description,
                                           "season": model.season,
                                           "episode": model.episode,
                                           "image": model.image_path
                        })
                    }
                    onWheel:
                        (wheel)=>{
                            if (wheel.angleDelta.y > 0) scrollbar_header.decrease()
                            else scrollbar_header.increase()
                        }

                }
            }
        }
    }
}
