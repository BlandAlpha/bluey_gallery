import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import "../window"
import "../global"
import DBManager 1.0
import Episodes 1.0

FluScrollablePage{

    launchMode: FluPageType.SingleTask
    header: Item{}

    property int totalSeasons: 3

    DatabaseManager {
        id: dbManager
    }

    // 循环创建有点问题，先将就用一下
    EpisodeModel {
        id: season1Model
    }
    EpisodeModel {
        id: season2Model
    }
    EpisodeModel {
        id: season3Model
    }

    // property var seasonModels: [season1, season2, season3]


    // Component.onCompleted: {
    //     // 根据季度数量动态创建 EpisodeModel 并分配不同的 id
    //     for (var i = 0; i < totalSeasons; i++) {
    //         var model = createModel(i);
    //         seasonModels.push(model);
    //         console.debug("Model", model, "created.");
    //     }
    // }

    // --- Banner Starts ---

    Item{
        Layout.fillWidth: true
        Layout.preferredHeight: 320
        Image {
            id: bg
            fillMode:Image.PreserveAspectCrop
            anchors.fill: parent
            // verticalAlignment: Qt.AlignVCenter
            sourceSize: Qt.size(1920,1080)
            source: "qrc:/res/img/episodesBanner.jpg"
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
                text:qsTr("Episodes")
                font: FluTextStyle.TitleLarge
            }
            FluText{
                text:qsTr("Which episode was your favourite?")
                font: FluTextStyle.Body
            }
        }
    }

    property int frameHeight: 142
    property int frameWidth: 520
    property real aspectRatio: 16 / 9
    property int imageHeight: frameHeight
    property int imageWidth: Math.round(imageHeight * aspectRatio)

    // Card Component id: com_episode
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
            // FluShadow{
            //     property int shadow: 4
            //     id: cardShadow
            //     radius: 8
            //     elevation: 2
            //     anchors.fill: item_card
            // }
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
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        Image {
                            sourceSize: Qt.size(1280, 720)
                            fillMode: Image.PreserveAspectFit
                            source: Qt.resolvedUrl(img)
                            width: imageWidth
                            height: imageHeight
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
                }
            }
        }
    }
    // Card Component Ends

    // 动态创建Model的函数
    // 有点问题，跑不起来，不认EpisodeModel
    // function createModel(index) {
    //     console.log("Creating model for season " + (index + 1));
    //     var modelString = 'import QtQuick 2.15; EpisodeModel { id: episodesModel' + index + ' }';
    //     var model = Qt.createQmlObject(modelString, this, "dynamicObject");
    //     // console.log("model: ", model);
    //     model.setEpisodes(dbManager.getEpisodesBySeason(index+1));
    //     // console.log("model: ", model);
    //     return model;
    // }

    // Item{
    //     id: s1_Sec
    //     Layout.leftMargin: 24
    //     RowLayout{
    //         spacing: 32
    //         // Layout.fillWidth: true
    //         Layout.topMargin: 24
    //         FluText{
    //             text: qsTr("Season 1")
    //             font: FluTextStyle.Title
    //         }
    //         FluFilledButton {
    //             text: qsTr("Add Series")
    //         }
    //     }
    //     GridView{
    //         Layout.fillWidth: true
    //         Layout.preferredHeight: contentHeight
    //         Layout.topMargin: 16
    //         cellHeight: frameHeight + 24
    //         cellWidth: frameWidth + 24
    //         model: season1Model
    //         interactive: false
    //         delegate: com_episode
    //     }
    //     Component.onCompleted: {
    //         season1Model.setEpisodes(dbManager.getEpisodesBySeason(1));
    //     }
    // }

    ColumnLayout{
        Layout.leftMargin: 24
        Layout.topMargin: 24
        RowLayout{
            spacing: 32
            // Layout.fillWidth: true
            Layout.topMargin: 24
            FluText{
                text: qsTr("Season 1")
                font: FluTextStyle.Title
            }
            FluFilledButton {
                text: qsTr("Add Episode")
            }
        }
        GridView{
            Layout.fillWidth: true
            Layout.preferredHeight: contentHeight
            Layout.topMargin: 16
            cellHeight: frameHeight + 24
            cellWidth: frameWidth + 24
            model: season1Model
            interactive: false
            delegate: com_episode
        }

        RowLayout{
            spacing: 32
            // Layout.fillWidth: true
            Layout.topMargin: 24
            FluText{
                text: qsTr("Season 2")
                font: FluTextStyle.Title
            }
            FluFilledButton {
                text: qsTr("Add Episode")
            }
        }
        GridView{
            Layout.fillWidth: true
            Layout.preferredHeight: contentHeight
            Layout.topMargin: 16
            cellHeight: frameHeight + 24
            cellWidth: frameWidth + 24
            model: season2Model
            interactive: false
            delegate: com_episode
        }

        RowLayout{
            spacing: 32
            // Layout.fillWidth: true
            Layout.topMargin: 24
            FluText{
                text: qsTr("Season 3")
                font: FluTextStyle.Title
            }
            FluFilledButton {
                text: qsTr("Add Episode")
            }
        }
        GridView{
            Layout.fillWidth: true
            Layout.preferredHeight: contentHeight
            Layout.topMargin: 16
            cellHeight: frameHeight + 24
            cellWidth: frameWidth + 24
            model: season3Model
            interactive: false
            delegate: com_episode
        }

        Component.onCompleted: {
            season1Model.setEpisodes(dbManager.getEpisodesBySeason(1));
            season2Model.setEpisodes(dbManager.getEpisodesBySeason(2));
            season3Model.setEpisodes(dbManager.getEpisodesBySeason(3));
        }
    }

}

