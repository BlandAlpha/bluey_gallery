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
    width: 800
    height: 640
    minimumWidth: 520
    minimumHeight: 200
    title: "添加角色"
    launchMode: FluWindowType.Standard

    property string imagePath: ""
    property var selectedEpisodes: []

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
                                    text: "选择角色图片"
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
                                    text: "中文名"
                                    font: FluTextStyle.BodyStrong
                                }
                                FluTextBox{
                                    id: nameZhField
                                    Layout.fillWidth: true
                                    placeholderText: qsTr("输入角色中文名")
                                }
                            }

                            ColumnLayout {
                                spacing: 8
                                FluText {
                                    text: "英文名"
                                    font: FluTextStyle.BodyStrong
                                }
                                FluTextBox{
                                    id: nameEnField
                                    Layout.fillWidth: true
                                    placeholderText: qsTr("输入角色英文名")
                                }
                            }

                            ColumnLayout {
                                spacing: 8
                                FluText {
                                    text: "品种"
                                    font: FluTextStyle.BodyStrong
                                }
                                FluTextBox{
                                    id: breedField
                                    Layout.fillWidth: true
                                    placeholderText: qsTr("输入角色品种")
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
                                placeholderText: qsTr("输入角色简介")
                            }
                        }

                        FileDialog {
                            id: fileDialog
                            title: "选择照片"
                            nameFilters: ["Images (*.png)"]
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
                        sourceSize: Qt.size(300, 464)
                        Layout.preferredHeight: 300
                        Layout.preferredWidth: 200
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
                        text: "关联剧集"
                        font: FluTextStyle.Subtitle
                    }
                    FluAutoSuggestBox{
                        id: searchBox
                        iconSource: FluentIcons.Search
                        items: searchEpisodes(text)
                        placeholderText: "搜索剧集以关联"
                        onItemClicked: (data)=> {
                                addSelectedEpisode(data);
                                searchBox.text = "";
                            }
                    }

                    ColumnLayout{
                        id: col_2
                        // Layout.preferredWidth: parent.width
                        width: parent.width
                        spacing: 16
                        FluText {
                            text: "已选择剧集："
                            font: FluTextStyle.BodyStrong
                        }

                        GridView {
                            Layout.fillWidth: true
                            Layout.preferredHeight: contentHeight
                            id: selectedEpisodesList
                            width: parent.width
                            // height: contentHeight
                            model: selectedEpisodes
                            cellHeight: 36+8
                            cellWidth: 150+8
                            delegate: selectedEpisodesCom
                        }
                    }

                    Component {
                        id: selectedEpisodesCom
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
                                    removeSelectedEpisode(modelData)
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
                }
                FluButton {
                    text: "取消"
                    horizontalPadding: 24
                }
            }
        }
    }


    function searchEpisodes(text) {
        console.debug("Now searching: ", text);
        var episodes = dbManager.searchEpisodes(text);
        console.debug("Search got: ", JSON.stringify(episodes));
        for(let i = 0; i < text; i++) {
            var item = episodes[i]
            episodes.push({title:item.title, key:item.id})
        }
        return episodes;
    }

    function addSelectedEpisode(episode) {
        if (!selectedEpisodes.some(ep => ep.id === episode.id)) {
            selectedEpisodes.push(episode)
            selectedEpisodesList.model = selectedEpisodes
        }
        console.log("Current episodes:", JSON.stringify(selectedEpisodes))
    }

    function removeSelectedEpisode(episode) {
        var index = selectedEpisodes.findIndex(ep => ep.id === episode.id)
        if (index !== -1) {
            selectedEpisodes.splice(index, 1)
            selectedEpisodesList.model = selectedEpisodes
        }
        console.log("Current episodes:", JSON.stringify(selectedEpisodes))
    }

    function addCharacter() {
        var name = characterName.text
        var image = characterImage.text
        var episodes = selectedEpisodes.map(function(episode) { return episode.id })

        dbManager.addCharacter(name, image, episodes)

        // Clear inputs after adding
        characterName.text = ""
        characterImage.text = ""
        selectedEpisodes = []
        selectedEpisodesList.model = selectedEpisodes
    }

}
