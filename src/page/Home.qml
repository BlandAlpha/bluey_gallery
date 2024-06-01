import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import "../window"
import "../global"

FluScrollablePage{

    launchMode: FluPageType.SingleTask
    // animationEnabled: false
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
            title: qsTr("Series")
            desc: qsTr("Check out different Bluey episodes and explore interesting stories of the Heelers.")
            url: "qrc:/page/Home.qml"
            clicked: function(model){
                navigationView.push(url)
            }
        }
        ListElement{
            icon: "qrc:/res/img/characters.png"
            title: qsTr("Characters")
            desc: qsTr("Check out the different Bluey characters and get to know these fun and lively characters.")
            // url: "https://github.com/zhuzichu520/FluentUI"
            clicked: function(model){
                // fluent_Initializr.showDialog()
            }
        }
        ListElement{
            icon: "qrc:/res/img/info.png"
            title: qsTr("About")
            desc: qsTr("Learn about Bluey's worldview and what its creators have to say about the animation.")
            url: "qrc:/page/About.qml"
            clicked: function(model){
                navigationView.push(url)
            }
        }
        ListElement{
            icon: "qrc:/res/img/add.png"
            title: qsTr("Add")
            desc: qsTr("Didn't find the page you wanted? Manually add episode or character pages.")
            // url: "https://github.com/zhuzichu520/FluentUI"
            clicked: function(model){
                // fluent_Initializr.showDialog()
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
            sourceSize: Qt.size(1140,810)
            source: "qrc:/res/img/mainBanner.jpg"
        }

        // Banner Overlay
        Rectangle{
            anchors.fill: parent
            gradient: Gradient{
                GradientStop { position: 0.5; color: FluTheme.dark ? "#a6323232" : "#80f3f3f3" }
                GradientStop { position: 1.0; color: FluTheme.dark ? "#323232" : "#f3f3f3" }
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
                        tintOpacity: FluTheme.dark ? 0.7 : 0.75
                        blurRadius : 48
                        targetRect: Qt.rect(list.x-list.contentX+10+(control.width)*index,list.y+10,width,height)
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
                            font.pixelSize: 20
                            Layout.topMargin: 24
                            Layout.leftMargin: 16
                        }
                        FluText{
                            text: model.desc
                            Layout.topMargin: 6
                            Layout.preferredWidth: cardWidth - 2 * cardPadding
                            Layout.leftMargin: 16
                            color: FluColors.Grey120
                            font.pixelSize: 12
                            font.family: FluTextStyle.family
                            wrapMode: Text.WordWrap
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
            header: Item{height: 10;width: 10}
            footer: Item{height: 10;width: 10}
            ScrollBar.horizontal: FluScrollBar{
                id: scrollbar_header
            }
            clip: false
            delegate: com_grallery
        }
    }

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
        text: "Recently added samples"
        font: FluTextStyle.Title
        Layout.topMargin: 24
        Layout.leftMargin: 24
    }

    GridView{
        Layout.fillWidth: true
        Layout.preferredHeight: contentHeight
        cellHeight: 120
        cellWidth: 320
        model:ItemsOriginal.getRecentlyAddedData()
        interactive: false
        delegate: com_item
    }

    FluText{
        text: "Recently updated samples"
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
        model: ItemsOriginal.getRecentlyUpdatedData()
        delegate: com_item
    }

}

