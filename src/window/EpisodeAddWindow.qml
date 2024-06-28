import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs
import FluentUI 1.0
import DBManager 1.0
import Characters 1.0
import Episodes 1.0

FluWindow {
    id: window
    width: 880
    height: 640
    minimumWidth: 520
    minimumHeight: 200
    title: "添加角色"
    launchMode: FluWindowType.Standard

    property string imagePath: ""
    property var selectedCharacters: []
    property var selectedCharactersId: []

    property var argument: ({})

    DatabaseManager {
        id: dbManager
    }

    EpisodeModel {
        id: episodesModel
    }

    ScrollView {
        anchors.fill: parent
        width: window.width

        ColumnLayout {
            width: window.width
            spacing: 24

            // Basic Input
            FluFrame {
                id: mainFrame
                Layout.fillWidth: true
                Layout.topMargin: 16
                Layout.leftMargin: 16
                Layout.rightMargin: 16
                padding: 16
                RowLayout {
                    id: mainContent
                    spacing: 32
                    Layout.preferredWidth: mainFrame.width
                    ColumnLayout {
                        id: mainTextContent
                        // anchors.left: parent.left
                        spacing: 24
                        Layout.fillWidth: true
                        Layout.preferredWidth: mainFrame.width - avatar.width - 64

                        FluText {
                            text: "基本信息"
                            font: FluTextStyle.Subtitle
                            anchors.topMargin: 16
                        }

                        ColumnLayout {
                            spacing: 8
                            Layout.fillWidth: true
                            FluText {
                                text: "图片"
                                font: FluTextStyle.BodyStrong
                            }
                            ColumnLayout {
                                spacing: 4
                                FluButton {
                                    text: "选择剧集图片"
                                    onClicked: fileDialog.open()
                                }
                                FluText {
                                    Layout.fillWidth: true
                                    text: "路径：" + imagePath
                                    font: FluTextStyle.Caption
                                    wrapMode: Text.WordWrap
                                }
                            }
                        }

                        RowLayout {
                            id: nameInput
                            spacing: 16
                            Layout.fillWidth: true
                            ColumnLayout {
                                spacing: 8
                                FluText {
                                    text: "剧集名称"
                                    font: FluTextStyle.BodyStrong
                                }
                                FluTextBox{
                                    id: titleField
                                    Layout.fillWidth: true
                                    placeholderText: qsTr("输入剧集名称")
                                }
                            }

                            ColumnLayout {
                                spacing: 8
                                FluText {
                                    text: "季"
                                    font: FluTextStyle.BodyStrong
                                }
                                FluTextBox{
                                    id: seasonField
                                    Layout.preferredWidth: 72
                                    // placeholderText: qsTr("输入季数")
                                    text: argument.season
                                }
                            }

                            ColumnLayout {
                                spacing: 8
                                FluText {
                                    text: "集"
                                    font: FluTextStyle.BodyStrong
                                }
                                FluTextBox{
                                    id: episodeField
                                    Layout.preferredWidth: 72
                                    // placeholderText: qsTr("输入集数")
                                }
                            }
                        }

                        ColumnLayout {
                            spacing: 8
                            Layout.fillWidth: true
                            FluText {
                                text: "简介"
                                font: FluTextStyle.BodyStrong
                            }
                            FluMultilineTextBox{
                                id: descField
                                Layout.fillWidth: true
                                placeholderText: qsTr("输入剧情简介")
                            }
                        }

                        FileDialog {
                            id: fileDialog
                            title: "选择图片"
                            nameFilters: ["Images (*.jpg)"]
                            // selectMultiple: false

                            onAccepted: {
                                imagePath = selectedFile
                                console.log("Selected photo path:", imagePath)
                            }
                            onRejected: {
                                console.log("No photo selected")
                            }
                        }
                    }
                    Image {
                        id: avatar
                        source: Qt.resolvedUrl(imagePath)
                        fillMode: Image.PreserveAspectFit
                        sourceSize: Qt.size(426*2, 240*2)
                        Layout.preferredHeight: 240
                        Layout.preferredWidth: 426
                        // anchors.left: mainTextContent.right
                    }
                }
            }

            // Connect Character-Episode
            FluFrame {
                id: relationFrame
                Layout.fillWidth: true
                Layout.leftMargin: 16
                Layout.rightMargin: 16
                //height: contentHeight + selectedEpisodesList.height + 32
                padding: 16

                ColumnLayout {
                    id: col_1
                    width: parent.width
                    // height: contentHeight
                    spacing: 24

                    FluText {
                        text: "关联角色"
                        font: FluTextStyle.Subtitle
                    }
                    FluAutoSuggestBox{
                        id: searchBox
                        iconSource: FluentIcons.Search
                        items: searchCharacters(text)
                        placeholderText: "搜索角色以关联"
                        onItemClicked: (data)=> {
                                addSelectedCharacter(data);
                                searchBox.text = "";
                            }
                    }

                    ColumnLayout{
                        id: col_2
                        // Layout.preferredWidth: parent.width
                        width: parent.width
                        spacing: 16
                        FluText {
                            text: "已选择角色："
                            font: FluTextStyle.BodyStrong
                        }

                        GridView {
                            Layout.fillWidth: true
                            Layout.preferredHeight: contentHeight
                            id: selectedCharactersList
                            width: parent.width
                            // height: contentHeight
                            model: selectedCharacters
                            cellHeight: 36+8
                            cellWidth: 150+8
                            delegate: selectedCharactersCom
                        }
                    }

                    Component {
                        id: selectedCharactersCom
                        FluFrame {
                            width: 150
                            height: 36
                            radius: 8

                            FluText {
                                text: modelData.title
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.left: parent.left
                                anchors.leftMargin: 12
                            }

                            FluIconButton {
                                iconSource: FluentIcons.Cancel
                                iconSize: 12
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.right: parent.right
                                // anchors.rightMargin: 8
                                onClicked: {
                                    removeSelectedCharacter(modelData)
                                }
                            }
                        }
                    }
                }
            }

            RowLayout {
                spacing: 16
                Layout.leftMargin: 24
                Layout.bottomMargin: 24
                FluFilledButton {
                    text: "添加"
                    horizontalPadding: 24
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

                    onClicked: {
                        if (imagePath.text !== "" && seasonField.text !== "" && episodeField.text !== "") {
                            var newImageDir = "/img/episodes"
                            var epName = "s" + ("00" + seasonField.text).slice(-2) + "e" + ("00" + episodeField.text).slice(-2);
                            var newImagePath = newImageDir + "/" + epName;
                            // 复制图片，添加条目
                            dbManager.copyImage(imagePath, newImageDir, epName);
                            if (dbManager.copyImage(imagePath, newImageDir, epName)) {
                                var newId = dbManager.addEpisode(
                                    titleField.text,
                                    seasonField.text,
                                    episodeField.text,
                                    descField.text,
                                    newImagePath
                                );
                                console.log("Binding Episodes:", selectedCharactersId);
                                // 绑定剧集
                                dbManager.bindCharacters(newId, selectedCharactersId)
                                showSuccess("添加成功")
                                closeWindowTimer.start()
                            } else {
                                console.log("Failed to copy image");
                                showError("拷贝图片失败")
                            }
                        } else {
                            console.log("Image path is empty");
                            showError("所选图片或必填字段为空")
                        }
                    }
                }
                FluButton {
                    text: "取消"
                    horizontalPadding: 24
                    onClicked: {
                        dialog_close.open()
                    }
                }
            }

            FluContentDialog{
                id: dialog_close
                title: qsTr("Warning")
                message: qsTr("The changes you have made will not be saved")
                buttonFlags: FluContentDialogType.NegativeButton | FluContentDialogType.PositiveButton
                positiveText: qsTr("Confirm")
                negativeText: qsTr("Cancel")
                onPositiveClicked:{
                    FluRouter.removeWindow(window)
                }
            }
        }
    }


    function searchCharacters(text) {
        console.debug("Now searching: ", text);
        var episodes = dbManager.searchCharacters(text);
        console.debug("Search got: ", JSON.stringify(episodes));
        for(let i = 0; i < text; i++) {
            var item = episodes[i]
            episodes.push({title:item.title, key:item.id})
        }
        return episodes;
    }

    function addSelectedCharacter(episode) {
        if (!selectedCharacters.some(ep => ep.id === episode.id)) {
            selectedCharacters.push(episode)
            selectedCharactersId.push(episode.id)
            selectedCharactersList.model = selectedCharacters
        }
        console.log("Current characters:", selectedCharactersId)
    }

    function removeSelectedCharacter(episode) {
        var index = selectedCharacters.findIndex(ep => ep.id === episode.id)
        if (index !== -1) {
            selectedCharacters.splice(index, 1)
            selectedCharactersId.splice(index, 1)
            selectedCharactersList.model = selectedCharacters
        }
        console.log("Current characters:", selectedCharactersId)
    }
}
