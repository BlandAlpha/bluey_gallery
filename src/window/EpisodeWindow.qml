import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Effects
import FluentUI 1.0
import DBManager 1.0
import Characters 1.0

FluWindow {
    id: window
    width: 840
    height: 760
    minimumWidth: 700
    minimumHeight: 400
    title: "剧集详情"
    launchMode: FluWindowType.Standard

    property var argument: ({})

    DatabaseManager {
        id: dbManager
    }

    CharacterModel {
        id: charactersModel
    }


    ColumnLayout{
        id: c_layout

        spacing: 24

        // anchors{
        //     top: parent.top
        //     left: parent.left
        //     right: parent.right
        //     topMargin: 16
        //     leftMargin: 16
        //     rightMargin: 16
        // }
        width: parent.width

        FluFrame {
            id: frame
            Layout.fillWidth: true
            Layout.leftMargin: 16
            Layout.rightMargin: 16
            Layout.topMargin: 16
            padding: 16

            RowLayout {
                anchors.left: parent.left
                spacing: 16
                Item {
                    id: coverContainer
                    width: 426+16
                    height: 240+16
                    y: 0

                    Behavior on y {
                        PropertyAnimation {
                            duration: 200
                            easing.type: Easing.OutQuad
                        }
                    }

                    Rectangle {
                        id: shadowHolder
                        width: 426
                        height: 240
                        anchors.centerIn: parent
                        radius: 8
                        color: "White"
                    }

                    MultiEffect {
                        id: shadow
                        property real verticalOffset: 2
                        property real blurAmount: 0.5
                        property real opacityAmount: 0.2

                        source: shadowHolder
                        anchors.fill: shadowHolder
                        shadowEnabled: true
                        shadowColor: "Black"
                        shadowBlur: blurAmount
                        shadowVerticalOffset: verticalOffset
                        shadowOpacity: opacityAmount

                        Behavior on verticalOffset {
                            PropertyAnimation {
                                duration: 200
                                easing.type: Easing.OutQuad
                            }
                        }

                        Behavior on blurAmount {
                            PropertyAnimation {
                                duration: 200
                                easing.type: Easing.OutQuad
                            }
                        }

                        Behavior on opacityAmount {
                            PropertyAnimation {
                                duration: 200
                                easing.type: Easing.OutQuad
                            }
                        }
                    }

                    FluClip {
                        id: cover_image
                        radius: [8,8,8,8]
                        width: 426
                        height: 240
                        anchors.centerIn: parent

                        Image {
                            fillMode: Image.PreserveAspectCrop
                            source: Qt.resolvedUrl(argument.image)
                            width: 426
                            height: 240
                            sourceSize: Qt.size(1280, 720)

                            MouseArea {
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered: {
                                    shadow.verticalOffset = 6
                                    shadow.blurAmount = 1
                                    shadow.opacityAmount = 0.15
                                    coverContainer.y = -2
                                }
                                onExited: {
                                    shadow.verticalOffset = 2
                                    shadow.blurAmount = 0.5
                                    shadow.opacityAmount = 0.25
                                    coverContainer.y = 0
                                }
                            }

                        }
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 12
                    FluText {
                        text: argument.title
                        font: FluTextStyle.Title
                    }
                    FluText {
                        text: "第" + argument.season + "季 第" + argument.episode + "集"
                        font: FluTextStyle.BodyStrong
                    }
                    FluText {
                        Layout.preferredWidth: frame.width - 510
                        text: "简介：" + argument.desc
                        font: FluTextStyle.Caption
                        wrapMode: Text.WordWrap
                        lineHeight: 1.25
                    }
                }
            }
        }
        FluText {
            text: qsTr("Starring")
            font: FluTextStyle.Title
            Layout.leftMargin: 16
        }

        ListView {
            id: relateCharactersList
            model: charactersModel
            anchors{
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }
            height: 360
            orientation: ListView.Horizontal
            header: Item{height: 16;width: 16}
            footer: Item{height: 16;width: 16}
            spacing: 12
            ScrollBar.horizontal: FluScrollBar{
                id: scrollbar_header
            }
            clip: false
            delegate: com_character
        }

        Component.onCompleted: {
            charactersModel.setCharacters(dbManager.getRelatedCharacters(argument.id));
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
                        console.debug("Now transmitting ID:", model.id)
                        FluRouter.navigate("/characterWindow", {
                                            "id": model.id,
                                            "name_zh": model.name_zh,
                                            "name_en": model.name_en,
                                            "breed": model.breed,
                                            "desc": model.description,
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

    FluFilledButton {
        id: delete_btn
        text: qsTr("Delete")
        anchors {
            top: c_layout.top
            right: c_layout.right
            topMargin: 16 + 12
            rightMargin: 16 + 12
        }
        onClicked: {
            dialog_delete.open()
        }
    }

    FluContentDialog {
        id: dialog_delete
        title: qsTr("Delete This Episode?")
        message: qsTr("This action cannot be withdrawn")
        buttonFlags: FluContentDialogType.NegativeButton | FluContentDialogType.PositiveButton
        positiveText: qsTr("Confirm")
        negativeText: qsTr("Cancel")
        onPositiveClicked:{
            console.debug("Now Deleting", argument.id)
            if(dbManager.deleteEpisode(argument.id)) {
                console.debug("Successfully Deleted:", argument.title)
                showSuccess("删除成功")
            } else {
                console.debug("Delete failed")
                showError("删除失败")
            }
        }
    }

}
