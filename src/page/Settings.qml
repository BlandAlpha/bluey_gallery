import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import "../component"
import "../global"

FluScrollablePage{

    title: qsTr("Settings")

    FluContentDialog{
        id: dialog_restart
        title: qsTr("Friendly Reminder")
        message: qsTr("This action requires a restart of the program to take effect, is it restarted?")
        buttonFlags: FluContentDialogType.NegativeButton | FluContentDialogType.PositiveButton
        negativeText: qsTr("Cancel")
        positiveText: qsTr("OK")
        onPositiveClicked: {
            FluRouter.exit(931)
        }
    }

    FluFrame{
        Layout.fillWidth: true
        Layout.topMargin: 16
        height: 128
        padding: 16

        ColumnLayout{
            spacing: 8
            anchors{
                top: parent.top
                left: parent.left
            }
            FluText{
                text: qsTr("Dark Mode")
                font: FluTextStyle.BodyStrong
                Layout.bottomMargin: 4
            }
            Repeater{
                model: [{title:qsTr("System"),mode:FluThemeType.System},{title:qsTr("Light"),mode:FluThemeType.Light},{title:qsTr("Dark"),mode:FluThemeType.Dark}]
                delegate: FluRadioButton{
                    checked : FluTheme.darkMode === modelData.mode
                    text:modelData.title
                    clickListener:function(){
                        FluTheme.darkMode = modelData.mode
                    }
                }
            }
        }
    }

    FluFrame{
        Layout.fillWidth: true
        Layout.topMargin: 16
        height: 160
        padding: 16

        ColumnLayout{
            spacing: 8
            anchors{
                top: parent.top
                left: parent.left
            }
            FluText{
                text:qsTr("Navigation View Display Mode")
                font: FluTextStyle.BodyStrong
                Layout.bottomMargin: 4
            }
            Repeater{
                model: [{title:qsTr("Open"),mode:FluNavigationViewType.Open},{title:qsTr("Compact"),mode:FluNavigationViewType.Compact},{title:qsTr("Minimal"),mode:FluNavigationViewType.Minimal},{title:qsTr("Auto"),mode:FluNavigationViewType.Auto}]
                delegate: FluRadioButton{
                    text: modelData.title
                    checked: GlobalModel.displayMode === modelData.mode
                    clickListener:function(){
                        GlobalModel.displayMode = modelData.mode
                    }
                }
            }
        }
    }

    ListModel{
        id:model_language
        ListElement{
            name:"en"
        }
        ListElement{
            name:"zh"
        }
    }


    //  语言切换
    FluFrame{
        Layout.fillWidth: true
        Layout.topMargin: 16
        height: 80
        padding: 16

        ColumnLayout{
            spacing: 16
            anchors{
                top: parent.top
                left: parent.left
            }
            FluText{
                text:qsTr("Language")
                font: FluTextStyle.BodyStrong
                Layout.bottomMargin: 4
            }
            Flow{
                spacing: 8
                Repeater{
                    model: TranslateHelper.languages
                    delegate: FluRadioButton{
                        checked: TranslateHelper.current === modelData
                        text:modelData
                        clickListener:function(){
                            TranslateHelper.current = modelData
                            dialog_restart.open()
                        }
                    }
                }
            }
        }
    }

    FluDivider{
        Layout.topMargin: 16
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
                        Qt.openUrlExternally("https://github.com/zhuzichu520/FluentUI")
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
                        Qt.openUrlExternally("https://github.com/zhuzichu520/FluentUI")
                    }
                }
            }
        }
    }
}
