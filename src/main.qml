import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQml 2.15
import Qt.labs.platform 1.1
import FluentUI 1.0
import "global"

FluWindow {

    id: window
    width: 1440
    height: 680
    minimumWidth: 680
    minimumHeight: 200
    title: qsTr("Bluey Gallery")

    launchMode: FluWindowType.SingleTask
    fitsAppBarWindows: true
    appBar: FluAppBar {
        width: window.width
        height: 30
        showDark: false
        showStayTop: false
        closeClickListener: ()=>{dialog_close.open()}
        z:7
    }

    Component.onDestruction: {
        FluRouter.exit()
    }

    SystemTrayIcon {
        id:system_tray
        visible: true
        icon.source: "qrc:/res/img/favicon.png"
        tooltip: "FluentUI"
        menu: Menu {
            MenuItem {
                text: "退出"
                onTriggered: {
                    FluRouter.exit()
                }
            }
        }
        onActivated:
            (reason)=>{
                if(reason === SystemTrayIcon.Trigger){
                    window.show()
                    window.raise()
                    window.requestActivate()
                }
            }
    }

    Timer{
        id: timer_window_hide_delay
        interval: 150
        onTriggered: {
            window.hide()
        }
    }

    FluContentDialog{
        id: dialog_close
        title: qsTr("Quit")
        message: qsTr("Are you sure you want to exit the program?")
        // negativeText: qsTr("Minimize")
        buttonFlags: FluContentDialogType.NegativeButton | FluContentDialogType.PositiveButton
        positiveText: qsTr("Quit")
        negativeText: qsTr("Cancel")
        onPositiveClicked:{
            FluRouter.exit(0)
        }
    }

    Flipable{
        id:flipable
        anchors.fill: parent
        property bool flipped: false
        property real flipAngle: 0
        transform: Rotation {
            id: rotation
            origin.x: flipable.width/2
            origin.y: flipable.height/2
            axis { x: 0; y: 1; z: 0 }
            angle: flipable.flipAngle

        }
        states: State {
            PropertyChanges { target: flipable; flipAngle: 180 }
            when: flipable.flipped
        }
        transitions: Transition {
            NumberAnimation { target: flipable; property: "flipAngle"; duration: 1000 ; easing.type: Easing.OutCubic}
        }
        back: Item{
            anchors.fill: flipable
            visible: flipable.flipAngle !== 0
            Row{
                id:layout_back_buttons
                z:8
                anchors{
                    top: parent.top
                    left: parent.left
                    topMargin: FluTools.isMacos() ? 20 : 5
                    leftMargin: 5
                }
                FluIconButton{
                    iconSource: FluentIcons.ChromeBack
                    width: 30
                    height: 30
                    iconSize: 13
                    onClicked: {
                        flipable.flipped = false
                    }
                }
                FluIconButton{
                    iconSource: FluentIcons.Sync
                    width: 30
                    height: 30
                    iconSize: 13
                    onClicked: {
                        loader.reload()
                    }
                }
                Component.onCompleted: {
                    window.setHitTestVisible(layout_back_buttons)
                }
            }
            /*
            FluRemoteLoader{
                id:loader
                lazy: true
                anchors.fill: parent
                source: "https://zhu-zichu.gitee.io/Qt_174_LieflatPage.qml"
            }
            */
        }
        front: Item{
            id:page_front
            visible: true
            anchors.fill: flipable
            FluNavigationView{
                property int clickCount: 0
                id:nav_view
                width: parent.width
                height: parent.height
                z:999
                //Stack模式，每次切换都会将页面压入栈中，随着栈的页面增多，消耗的内存也越多，内存消耗多就会卡顿，这时候就需要按返回将页面pop掉，释放内存。该模式可以配合FluPage中的launchMode属性，设置页面的启动模式
                //                pageMode: FluNavigationViewType.Stack
                //NoStack模式，每次切换都会销毁之前的页面然后创建一个新的页面，只需消耗少量内存
                pageMode: FluNavigationViewType.NoStack
                items: ItemsOriginal
                footerItems:ItemsFooter
                topPadding:{
                    if(window.useSystemAppBar){
                        return 0
                    }
                    return FluTools.isMacos() ? 20 : 0
                }
                displayMode: GlobalModel.displayMode
                logo: "qrc:/res/img/favicon.png"
                title:"Bluey Gallery"
                /*
                onLogoClicked:{
                    clickCount += 1
                    showSuccess("%1:%2".arg(qsTr("Click Time")).arg(clickCount))
                    if(clickCount === 5){
                        loader.reload()
                        flipable.flipped = true
                        clickCount = 0
                    }
                }
                */
                autoSuggestBox:FluAutoSuggestBox{
                    iconSource: FluentIcons.Search
                    items: ItemsOriginal.getSearchData()
                    placeholderText: qsTr("Search")
                    onItemClicked:
                        (data)=>{
                            ItemsOriginal.startPageByItem(data)
                        }
                }
                Component.onCompleted: {
                    ItemsOriginal.navigationView = nav_view
                    // ItemsOriginal.paneItemMenu = nav_item_right_menu
                    ItemsFooter.navigationView = nav_view
                    // ItemsFooter.paneItemMenu = nav_item_right_menu
                    window.setHitTestVisible(nav_view.buttonMenu)
                    window.setHitTestVisible(nav_view.buttonBack)
                    window.setHitTestVisible(nav_view.imageLogo)
                    setCurrentIndex(0)
                }
            }
        }
    }


    FluLoader{
        id:loader_reveal
        anchors.fill: parent
    }

}
