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
        width: parent.width

        FluFrame {
            id: frame
            Layout.fillWidth: true
            Layout.leftMargin: 16
            Layout.rightMargin: 16
            Layout.topMargin: 16
            padding: 16

            RowLayout {
                // anchors.left: parent.left
                Layout.leftMargin: 16
                Layout.rightMargin: 16
                spacing: 24
                Image {
                    id: avatar
                    source: Qt.resolvedUrl(argument.image)
                    sourceSize: Qt.size(300, 464)
                    Layout.preferredHeight: 310
                    Layout.preferredWidth: 200
                    fillMode: Image.PreserveAspectFit
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
            Layout.leftMargin: 16
            Layout.rightMargin: 16
            Layout.fillWidth: true
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
        id: delete_btn
        text: qsTr("Delete")
        FluTooltip{
            visible: button_1.hovered
            text:button_1.text
            delay: 1800
        }
        Timer {
            id: closeWindowTimer
            interval: 2000
            repeat: false
            running: false
            onTriggered: FluRouter.removeWindow(window)
        }
        anchors {
            top: c_layout.top
            right: c_layout.right
            topMargin: 16 + 12
            rightMargin: 16 + 12
        }
        onClicked: {
            dialog_delete.open()
            if(dialog_delete.onPositiveClickListener()) {
                showSuccess("删除成功")
            }
        }
    }

    FluContentDialog {
        id: dialog_delete
        title: qsTr("Delete This Character?")
        message: qsTr("This action cannot be withdrawn")
        buttonFlags: FluContentDialogType.NegativeButton | FluContentDialogType.PositiveButton
        positiveText: qsTr("Confirm")
        negativeText: qsTr("Cancel")
        onPositiveClicked:{
            console.debug("Now Deleting", argument.id)
            if(dbManager.deleteCharacter(argument.id)) {
                console.debug("Successfully Deleted:", argument.name_zh)
            } else {
                console.debug("Delete failed")
            }
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
                        radius: [8,0,0,8]
                        width: imageWidth
                        height: imageHeight
                        Image {
                            sourceSize: Qt.size(1280, 720)
                            fillMode: Image.PreserveAspectCrop
                            source: Qt.resolvedUrl(img)
                            width: imageWidth
                            height: imageHeight
                        }
                    }

                    Column {
                        Layout.leftMargin: 8
                        spacing: 6
                        FluText {
                            id: item_title
                            text: title
                            font: FluTextStyle.Subtitle
                        }
                        FluText {
                            id:item_se
                            text: "第" + season + "季，第" + episode + "集"
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
