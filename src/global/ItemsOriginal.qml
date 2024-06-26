pragma Singleton

import QtQuick 2.15
import FluentUI 1.0

FluObject{

    property var navigationView
    property var paneItemMenu

    function rename(item, newName){
        if(newName && newName.trim().length>0){
            item.title = newName;
        }
    }

    FluPaneItem{
        id:item_home
        title: qsTr("Home")
        menuDelegate: paneItemMenu
        icon: FluentIcons.Home
        url: "qrc:/page/Home.qml"
        onTap: {
            navigationView.push(url)
            // icon: FluentIcons.HomeSolid
        }
    }

    FluPaneItem{
        id:item_movies
        title: qsTr("Episodes")
        menuDelegate: paneItemMenu
        icon: FluentIcons.TVMonitor
        url: "qrc:/page/Episodes.qml"
        onTap: {
            navigationView.push(url)
        }
    }

    FluPaneItem{
        id:item_characters
        title: qsTr("Characters")
        menuDelegate: paneItemMenu
        icon: FluentIcons.People
        url: "qrc:/page/Characters.qml"
        onTap: {
            navigationView.push(url)
        }
    }

    FluPaneItem{
        id:item_show
        title: qsTr("Show")
        menuDelegate: paneItemMenu
        icon: FluentIcons.Movies
        url: "qrc:/page/Show.qml"
        onTap: {
            navigationView.push(url)
        }
    }

    FluPaneItem{
        id:item_add
        title: qsTr("Edit")
        menuDelegate: paneItemMenu
        icon: FluentIcons.Edit
        url: "qrc:/page/Edit.qml"
        onTap: {
            navigationView.push(url)
        }
    }

    function getSearchData(){
        // change to database search
        if(!navigationView){
            return
        }
        var arr = []
        var items = navigationView.getItems();
        console.debug("Search got: ", items)
        for(var i=0;i<items.length;i++){
            var item = items[i]
            if(item instanceof FluPaneItem){
                if (item.parent instanceof FluPaneItemExpander)
                {
                    arr.push({title:`${item.parent.title} -> ${item.title}`,key:item.key})
                }
                else
                    arr.push({title:item.title,key:item.key})
            }
        }
        return arr
    }

    function setCurrentIndex(index){
        navigationView.setCurrentIndex(index)
    }

    function startPageByItem(data){
        navigationView.startPageByItem(data)
    }

}
