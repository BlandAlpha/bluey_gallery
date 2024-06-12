import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import FluentUI 1.0

FluWindow {

    id: window
    width: 800
    height: 600
    minimumWidth: 520
    minimumHeight: 200
    title: "角色详情"
    launchMode: FluWindowType.SingleTask

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

        Component.onCompleted: {
            console.log("LayoutWidth:", c_layout.width);
            console.log("frameWidth:", frame.width);
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
                    // source:
                    source: Qt.resolvedUrl("file:///D:/PROJECTS/QT_Projects/bluey_gallery/bin/Debug/img/characters/Bluey.png")
                    sourceSize: Qt.size(200, 310)
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 12
                    FluText {
                        text: "布鲁伊"
                        font: FluTextStyle.Title
                    }
                    FluText {
                        text: "英文名：" + "Bluey"
                        font: FluTextStyle.BodyStrong
                    }
                    FluText {
                        text: "种族：" + "澳大利亚蓝色牧牛犬"
                        font: FluTextStyle.BodyStrong
                    }
                    FluText {
                        Layout.preferredWidth: frame.width - 260
                        text: "简介：" + "布鲁伊是一只精力充沛的蓝色澳大利亚牧牛小狗，与爸爸妈妈和妹妹宾果生活在一起。她喜欢笑，喜欢玩，但更喜欢和家人一起玩游戏。"
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

        ListModel {
            id: relateEpisodeModel
            //
        }

        ListView {
            id: relateEpisodeList
            //
        }

    }
    FluFilledButton {
        text: qsTr("Edit")
        onClicked: {
            // open edit page
        }
        anchors {
            top: c_layout.top
            right: c_layout.right
            topMargin: 12
            rightMargin: 12
        }
    }
}
