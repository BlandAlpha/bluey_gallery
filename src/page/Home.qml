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

    property int cardWidth: 180
    property int cardMargin: 40
    property int cardPadding: 16
    property int cardHeight: 240
    property int cardBorderRadius: 8

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
                width: cardWidth + cardMargin
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
                        Image {
                            Layout.topMargin: 24
                            Layout.leftMargin: 16
                            Layout.preferredWidth: 56
                            Layout.preferredHeight: 56
                            source: model.icon
                        }
                        FluText{
                            text: model.title
                            font.pixelSize: 24
                            Layout.topMargin: 24
                            Layout.leftMargin: 16
                        }
                        FluText{
                            text: model.desc
                            Layout.topMargin: 6
                            Layout.preferredWidth: cardWidth - 2 * cardPadding
                            Layout.leftMargin: 16
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
            }
            orientation: ListView.Horizontal
            height: 240
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

    FluText{
        text: qsTr("Explore Characters")
        font: FluTextStyle.Title
        Layout.topMargin: 24
        Layout.leftMargin: 24
    }

    GridView{
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        cellHeight: 120
        cellWidth: 320
        model:ItemsOriginal.getRandomCharacterData()
        interactive: false
        delegate: com_item
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
        cellHeight: 120
        cellWidth: 320
        interactive: false
        model: ItemsOriginal.getRandomSeriesData()
        delegate: com_item
    }

}

