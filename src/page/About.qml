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
        Layout.fillWidth: true
        Layout.topMargin: 16
        height: 160
        padding: 16

        ColumnLayout{
            spacing: 16
            anchors{
                top: parent.top
                left: parent.left
            }
            FluText{
                text:qsTr("Author")
                font: FluTextStyle.BodyStrong
                Layout.bottomMargin: 4
            }

            RowLayout{
                FluText{
                    text: "作者："
                }
                FluCopyableText{
                    text: "刘国傲"
                }
            }

            RowLayout{
                FluText{
                    text: "学号："
                }
                FluCopyableText{
                    text: "20214841"
                }
            }

            RowLayout{
                FluText{
                    text: "框架："
                }
                FluText{
                    text: "Qt QML"
                }
            }

            RowLayout{
                // spacing: 16
                FluText{
                    text: "第三方UI开源库："
                    // width: labelwidth
                }
                FluButton{
                    id: libBtn
                    text: "FluentUI"
                    Layout.alignment: Qt.AlignCenter
                    onClicked: {
                        redirect("https://github.com/zhuzichu520/FluentUI")
                        // Qt.openUrlExternally("https://github.com/zhuzichu520/FluentUI")
                    }
                }
            }

            RowLayout{
                // spacing: 16
                FluText{
                    text: "本项目地址："
                    width: labelwidth
                }
                FluFilledButton{
                    id: repoBtn
                    text: "前往 Github"
                    Layout.alignment: Qt.AlignCenter
                    onClicked: {
                        redirect("https://github.com/BlandAlpha/bluey_gallery")
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
