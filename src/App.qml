import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import FluentUI 1.0

FluLauncher {
    id: app
    Connections{
        target: FluTheme
        function onDarkModeChanged(){
            SettingsHelper.saveDarkMode(FluTheme.darkMode)
        }
    }
    Connections{
        target: FluApp
        function onUseSystemAppBarChanged(){
            SettingsHelper.saveUseSystemAppBar(FluApp.useSystemAppBar)
        }
    }
    Component.onCompleted: {
        FluApp.init(app)
        // Change app icon
        FluApp.windowIcon = "qrc:/res/img/favicon.png"
        // FluApp.useSystemAppBar = SettingsHelper.getUseSystemAppBar()
        // FluTheme.darkMode = SettingsHelper.getDarkMode()
        FluTheme.animationEnabled = true
        FluRouter.routes = {
            "/":"qrc:/main.qml",
            "/pageWindow":"qrc:/window/PageWindow.qml"
        }
        FluRouter.navigate("/")
    }
}
