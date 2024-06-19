import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import DBManager 1.0
import Characters 1.0
import Episodes 1.0
import "../window"
import "../global"

FluScrollablePage{

    launchMode: FluPageType.SingleTask
    header: Item{}

    DatabaseManager {
        id: dbManager
    }

    EpisodeModel {
        id: episodesModel
    }

    CharacterModel {
        id: charactersModel
    }

    property int cardWidth: 180
    property int cardHeight: 240
    property int cardBorderRadius: 8

    // Random Recommendation Numbers
    property int randomCharacters: 5
    property int randomEpisodes: 6

    ListModel{
        id: model_header
        ListElement{
            icon: "qrc:/res/img/cinema.png"
            title: qsTr("Episodes")
            desc: qsTr("Check out different Bluey episodes and explore interesting stories of the Heelers.")
            index: 1
            clicked: function(model){
                ItemsOriginal.setCurrentIndex(model.index)
            }
        }
        ListElement{
            icon: "qrc:/res/img/characters.png"
            title: qsTr("Characters")
            desc: qsTr("Check out the different Bluey characters and get to know these fun and lively characters.")
            index: 2
            clicked: function(model){
                ItemsOriginal.setCurrentIndex(model.index)
            }
        }
        ListElement{
            icon: "qrc:/res/img/info.png"
            title: qsTr("Show")
            desc: qsTr("Learn about Bluey's worldview and what its creators have to say about the animation.")
            index: 3
            clicked: function(model){
                ItemsOriginal.setCurrentIndex(model.index)
            }
        }
        ListElement{
            icon: "qrc:/res/img/add.png"
            title: qsTr("Add")
            desc: qsTr("Didn't find the page you wanted? Manually add episode or character pages.")
            index: 4
            clicked: function(model){
                ItemsOriginal.setCurrentIndex(model.index)
            }
        }
    }

    Item{
        Layout.fillWidth: true
        Layout.preferredHeight: 480
        Image {
            id: bg
            fillMode:Image.PreserveAspectCrop
            anchors.fill: parent
            verticalAlignment: Qt.AlignVCenter
            sourceSize: Qt.size(1440, 810)
            source: "qrc:/res/img/mainBanner.jpg"
        }

        // Banner Overlay
        Rectangle{
            anchors.fill: parent
            gradient: Gradient{
                GradientStop { position: 0.5; color: FluTheme.dark ? "#a6191919" : "#80f3f3f3" }
                GradientStop { position: 1.0; color: FluTheme.dark ? "#191919" : "#f3f3f3" }
            }
        }

        // Main Text
        ColumnLayout{
            spacing: 4
            anchors{
                top: parent.top
                left: parent.left
                topMargin: 64
                leftMargin: 48
            }
            FluText{
                    text:qsTr("Welcome to")
                    font: FluTextStyle.Subtitle
            }
            ColumnLayout{
                spacing: 16
                FluText{
                    text:qsTr("Bluey Gallery")
                    font: FluTextStyle.TitleLarge
                }
                FluText{
                    text:qsTr("Have fun exploring the animated characters, plot descriptions, and more of Bluey.")
                    font: FluTextStyle.Body
                }
            }
        }

        // 首页Banner大卡片组件
        Component{
            id:com_grallery
            Item{
                id: control
                width: cardWidth
                height: cardHeight
                FluShadow{
                    radius: 8
                    elevation: 6
                    anchors.fill: item_content
                }
                FluClip{
                    id:item_content
                    radius: [8,8,8,8]
                    width: cardWidth
                    height: cardHeight
                    anchors.centerIn: parent
                    FluAcrylic{
                        anchors.fill: parent
                        tintColor: FluTheme.dark ? Qt.rgba(0,0,0,1) : Qt.rgba(1,1,1,1)
                        target: bg
                        tintOpacity: FluTheme.dark ? 0.7 : 0.8
                        blurRadius: 64
                        targetRect: Qt.rect(list.x-list.contentX-200+(control.width)*index, list.y, width, height)
                    }

                    Rectangle{
                        anchors.fill: parent
                        radius: cardBorderRadius
                        color:FluTheme.itemHoverColor
                        visible: item_mouse.containsMouse
                    }
                    Rectangle{
                        anchors.fill: parent
                        radius: cardBorderRadius
                        color:Qt.rgba(0,0,0,0.0)
                        visible: !item_mouse.containsMouse
                    }
                    ColumnLayout{
                        width: parent.width - 32
                        anchors.horizontalCenter: parent.horizontalCenter
                        Image {
                            Layout.topMargin: 24
                            // Layout.leftMargin: 16
                            Layout.preferredWidth: 56
                            Layout.preferredHeight: 56
                            source: model.icon
                        }
                        FluText{
                            text: model.title
                            font.pixelSize: 24
                            Layout.topMargin: 24
                            // Layout.leftMargin: 16
                        }
                        FluText{
                            text: model.desc
                            Layout.topMargin: 6
                            Layout.fillWidth: true
                            // Layout.leftMargin: 16
                            color: FluColors.Grey140
                            font.pixelSize: 12
                            font.family: FluTextStyle.family
                            font.weight: 200
                            wrapMode: Text.WordWrap
                            lineHeight: 1.125
                        }
                    }
                    MouseArea{
                        id:item_mouse
                        anchors.fill: parent
                        hoverEnabled: true
                        onWheel:
                            (wheel)=>{
                                if (wheel.angleDelta.y > 0) scrollbar_header.decrease()
                                else scrollbar_header.increase()
                            }
                        onClicked: {
                            model.clicked(model)
                        }
                    }
                }
            }
        }

        ListView{
            id: list
            anchors{
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                leftMargin: 24
            }
            orientation: ListView.Horizontal
            height: cardHeight
            spacing: 32
            model: model_header
            header: Item{height: 8;width: 8}
            footer: Item{height: 8;width: 8}
            ScrollBar.horizontal: FluScrollBar{
                id: scrollbar_header
            }
            clip: false
            delegate: com_grallery
        }
    }

    // Explore Card Component
    Component{
        id:com_item
        Item{
            property string desc: modelData.extra.desc
            width: 320
            height: 120
            FluFrame{
                radius: 8
                width: 300
                height: 100
                anchors.centerIn: parent
                Rectangle{
                    anchors.fill: parent
                    radius: 8
                    color:{
                        if(item_mouse.containsMouse){
                            return FluTheme.itemHoverColor
                        }
                        return FluTheme.itemNormalColor
                    }
                }
                Image{
                    id:item_icon
                    height: 40
                    width: 40
                    source: modelData.extra.image
                    anchors{
                        left: parent.left
                        leftMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                }
                FluText{
                    id:item_title
                    text:modelData.title
                    font: FluTextStyle.BodyStrong
                    anchors{
                        left: item_icon.right
                        leftMargin: 20
                        top: item_icon.top
                    }
                }
                FluText{
                    id:item_desc
                    text:desc
                    color:FluColors.Grey120
                    wrapMode: Text.WordWrap
                    elide: Text.ElideRight
                    font: FluTextStyle.Caption
                    maximumLineCount: 2
                    anchors{
                        left: item_title.left
                        right: parent.right
                        rightMargin: 20
                        top: item_title.bottom
                        topMargin: 5
                    }
                }

                Rectangle{
                    height: 12
                    width: 12
                    radius:  6
                    color: FluTheme.primaryColor
                    anchors{
                        right: parent.right
                        top: parent.top
                        rightMargin: 14
                        topMargin: 14
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

    FluText {
        text: qsTr("Explore Characters")
        font: FluTextStyle.Title
        Layout.topMargin: 48
        Layout.leftMargin: 24
    }

    GridView {
        id: charactersCards
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        Layout.topMargin: 16
        Layout.leftMargin: 24
        cellHeight: characterCardHeight+12
        cellWidth: characterCardWidth+12
        model: charactersModel
        interactive: false
        delegate: com_character
    }

    FluText{
        text: qsTr("Explore Episodes")
        font: FluTextStyle.Title
        Layout.topMargin: 24
        Layout.leftMargin: 24
    }

    GridView{
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        Layout.topMargin: 16
        Layout.leftMargin: 24
        cellHeight: frameHeight + 16
        cellWidth: frameWidth + 16
        interactive: false
        model: episodesModel
        delegate: com_episode
    }

    property int characterCardHeight: 330
    property int characterCardWidth: 200
    // Character Card Component
    Component {
        id: com_character
        Item {
            property string name_zh: model.name_zh
            property string name_en: model.name_en
            property string breed: model.breed
            property string desc: model.description
            property string img: model.image_path

            width: characterCardWidth
            height: characterCardHeight
            FluFrame {
                radius: 8
                width: characterCardWidth
                height: characterCardHeight
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
                }

            }
        }
    }

    property int frameHeight: 120
    property int frameWidth: 500
    property real aspectRatio: 16 / 9
    property int imageHeight: frameHeight
    property int imageWidth: Math.round(imageHeight * aspectRatio)
    // Episode Card Component
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

    Component.onCompleted: {
        charactersModel.setCharacters(dbManager.getRandomCharacters(randomCharacters));
        episodesModel.setEpisodes(dbManager.getRandomEpisodes(randomEpisodes));
    }



}

