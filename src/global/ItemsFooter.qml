pragma Singleton

import QtQuick 2.15
import FluentUI 1.0

FluObject{

    property var navigationView
    property var paneItemMenu

    id:footer_items

    FluPaneItem{
        title:qsTr("About")
        menuDelegate: paneItemMenu
        icon:FluentIcons.Info
        url:"qrc:/page/About.qml"
        onTap:{
            navigationView.push(url)
        }
    }

    FluPaneItem{
        title:qsTr("Settings")
        menuDelegate: paneItemMenu
        icon:FluentIcons.Settings
        url:"qrc:/page/Settings.qml"
        onTap:{
            navigationView.push(url)
        }
    }

}
