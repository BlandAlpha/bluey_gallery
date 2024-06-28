import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import DBManager 1.0
import "../component"
import "../global"

FluScrollablePage{

    title: qsTr("Settings")

    DatabaseManager {
        id: dbManager
    }

    FluContentDialog{
        id: dialog_restart
        title: qsTr("Restart now?")
        message: qsTr("This action requires a restart of the program to take effect.")
        buttonFlags: FluContentDialogType.NegativeButton | FluContentDialogType.PositiveButton
        negativeText: qsTr("Cancel")
        positiveText: qsTr("OK")
        onPositiveClicked: {
            FluRouter.exit(931)
        }
    }

    ColumnLayout {
        spacing: 16
        Layout.rightMargin: 8

        // 深色模式
        FluFrame{
            Layout.fillWidth: true
            padding: 16

            ColumnLayout{
                spacing: 12
                FluText{
                    text: qsTr("Dark Mode")
                    font: FluTextStyle.BodyStrong
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

        // 导航栏模式
        FluFrame{
            Layout.fillWidth: true
            padding: 16

            ColumnLayout{
                spacing: 12
                FluText{
                    text:qsTr("Navigation View Display Mode")
                    font: FluTextStyle.BodyStrong
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


        // 语言切换
        FluFrame{
            Layout.fillWidth: true
            padding: 16

            ColumnLayout{
                spacing: 12
                FluText{
                    text:qsTr("Language")
                    font: FluTextStyle.BodyStrong
                    // Layout.bottomMargin: 4
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

        MenuSeparator{
            Layout.fillWidth: true
        }

        // 重置数据库
        FluFrame {
            Layout.fillWidth: true
            padding: 16
            RowLayout {
                spacing: 16
                FluText {
                    text:qsTr("Reset Database")
                    font: FluTextStyle.BodyStrong
                }

                FluButton {
                    text: qsTr("Reset")
                    onClicked: {
                        console.log("Database Reset")
                        dbManager.resetDatabase()
                        showSuccess(qsTr("Database Reset Successfully"))
                    }
                }
            }
        }
    }
}
