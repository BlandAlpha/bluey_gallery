import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Effects
import FluentUI 1.0
import "../component"
import "../global"

FluScrollablePage{

    title: qsTr("About The Show")

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
        Row{
            width: parent.width
            anchors.top: parent.top
            spacing: 24

            Item {
                id: coverContainer
                width: 240
                height: 360
                y: 0

                Behavior on y {
                    PropertyAnimation {
                        duration: 200
                        easing.type: Easing.OutQuad
                    }
                }

                Rectangle {
                    id: shadowHolder
                    width: 240
                    height: 360
                    anchors.centerIn: parent
                    radius: 12
                    color: "White"
                }

                MultiEffect {
                    id: shadow
                    property real verticalOffset: 2
                    property real blurAmount: 0.75
                    property real opacityAmount: 0.25

                    source: shadowHolder
                    anchors.fill: shadowHolder
                    shadowEnabled: true
                    shadowColor: "Black"
                    shadowBlur: blurAmount
                    shadowVerticalOffset: verticalOffset
                    shadowOpacity: opacityAmount

                    Behavior on verticalOffset {
                        PropertyAnimation {
                            duration: 200
                            easing.type: Easing.OutQuad
                        }
                    }

                    Behavior on blurAmount {
                        PropertyAnimation {
                            duration: 200
                            easing.type: Easing.OutQuad
                        }
                    }

                    Behavior on opacityAmount {
                        PropertyAnimation {
                            duration: 200
                            easing.type: Easing.OutQuad
                        }
                    }
                }

                FluClip {
                    id: item_content
                    radius: [12,12,12,12]
                    width: 240
                    height: 360

                    Image {
                        anchors.fill: parent
                        source: "qrc:/res/img/poster.jpg"
                        sourceSize: Qt.size(width*2,height*2)

                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: {
                                shadow.verticalOffset = 6
                                shadow.blurAmount = 1.2
                                shadow.opacityAmount = 0.1
                                coverContainer.y = -2
                            }
                            onExited: {
                                shadow.verticalOffset = 2
                                shadow.blurAmount = 0.75
                                shadow.opacityAmount = 0.2
                                coverContainer.y = 0
                            }
                        }

                    }
                }
            }

            ColumnLayout{
                id: descriptionSection
                // height: 360
                spacing: 32
                Layout.fillWidth: true
                // anchors.top: parent.top

                ColumnLayout{
                    spacing: 16
                    RowLayout{
                        spacing: 24
                        FluText{
                            text: qsTr("Bluey (2018)")
                            font: FluTextStyle.Title
                        }
                        FluFilledButton{
                            text: qsTr("Watch Online")
                            onClicked: {
                                redirect("https://www.bilibili.com/bangumi/media/md20222115")
                            }
                        }
                    }

                    FluText{
                        text: qsTr("Label: Animation, Kids, Comedy")
                        font: FluTextStyle.Body
                    }
                }

                FluDivider{
                    implicitWidth: 320
                }

                ColumnLayout{
                    spacing: 8
                    FluText{
                        text: qsTr("Overview")
                        font: FluTextStyle.Subtitle
                    }
                    FluText{
                        Layout.preferredWidth: frameView.width - 320 - 32
                        text: qsTr("Bluey is an inexhaustible six year-old Blue Heeler dog, who loves to play and turns everyday family life into extraordinary adventures, developing her imagination as well as her mental, physical and emotional resilience.")
                        font: FluTextStyle.Body
                        wrapMode: Text.WordWrap
                        lineHeight: 1.25
                    }
                }

                ColumnLayout{
                    spacing: 8
                    FluText{
                        text: qsTr("Production")
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
