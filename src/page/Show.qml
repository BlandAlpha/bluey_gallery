import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import "../component"
import "../global"

FluScrollablePage{

    title: qsTr("About")

    FluContentDialog{
        property string url: ""
        id: dialog_Jump
        title: qsTr("Redirecting")
        message: qsTr("You are about to be redirected to your browser.")
        buttonFlags: FluContentDialogType.NegativeButton | FluContentDialogType.PositiveButton
        positiveText: qsTr("OK")
        negativeText: qsTr("Cancel")
        onPositiveClicked:{
            Qt.openUrlExternally(dialog_Jump.url)
        }
    }

    FluFrame{
        id: frameView
        Layout.fillWidth: true
        Layout.topMargin: 16
        // Layout.preferredHeight: 480
        padding: 24
        RowLayout{
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop
            spacing: 24

            Item{
                Layout.alignment: top
                // anchors.top: parent.top
                id: posterCard
                width: 240+8
                height: 360+8
                FluShadow{
                    radius: 16
                    elevation: 8
                    anchors.fill: item_content
                }
                FluClip{
                    id: item_content
                    radius: [16,16,16,16]
                    width: 240
                    height: 360
                    Image{
                        asynchronous: true
                        anchors.fill: parent
                        source: "qrc:/res/img/poster.jpg"
                        sourceSize: Qt.size(width,height)
                    }
                }
            }

            ColumnLayout{
                id: descriptionSection
                height: 360
                spacing: 32
                Layout.fillWidth: true

                ColumnLayout{
                    spacing: 16
                    RowLayout{
                        spacing: 24
                        FluText{
                            text: "布鲁伊 (Bluey)"
                            font: FluTextStyle.Title
                        }
                        FluFilledButton{
                            text:"在线观看"
                            onClicked: {
                                redirect("https://www.bilibili.com/bangumi/media/md20222115")
                            }
                        }
                    }

                    FluText{
                        text: "标签：动画，儿童，喜剧"
                        font: FluTextStyle.Body
                    }
                }

                FluDivider{
                    implicitWidth: 320
                }

                ColumnLayout{
                    spacing: 8
                    FluText{
                        text: "剧情简介"
                        font: FluTextStyle.Subtitle
                    }
                    FluText{

                        Layout.preferredWidth: frameView.width - 320 - 32
                        text: "这部以趣味真挚的方式描绘现代家庭生活的动画片，赞扬了富有想象力的游戏是如何帮助孩子健康成长的。6岁的蓝色澳大利亚牧牛犬布鲁伊有着无穷无尽的想象力，热衷于将日常生活转变为调皮冒险。她和妹妹宾果致力于探索自己的世界，用游戏来克服她们的恐惧，并且尝试扮演成年人的角色。她们喜欢把父母（尤其是爸爸）拉进她们的游戏中。妈妈奇莉回归工作了，而爸爸班底特一边照顾孩子一边在家工作。虽然他可能以为自己能做主，但是女儿们绝对掌控了游戏时间——以及几乎所有其他的事情！"
                        font: FluTextStyle.Body
                        wrapMode: Text.WordWrap
                    }
                }

                ColumnLayout{
                    spacing: 8
                    FluText{
                        text: "制作公司"
                        font: FluTextStyle.Subtitle
                    }
                    FluIconButton{
                        iconSource: FluentIcons.ChromeCloseContrast
                        iconSize: 20
                        text: "Ludo Studio"
                        display: Button.TextOnly
                        onClicked: {
                            redirect("https://ludostudio.com.au/")
                            // Qt.openUrlExternally("https://ludostudio.com.au/")
                        }
                    }
                }

            }

        }
    }

    function redirect(url) {
            dialog_Jump.url = url
            dialog_Jump.open()
        }

}
