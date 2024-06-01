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
        title: qsTr("Series")
        menuDelegate: paneItemMenu
        icon: FluentIcons.Movies
        // Change to real url
        url: "qrc:/page/Series.qml"
        onTap: {
            navigationView.push(url)
        }
    }

    FluPaneItem{
        id:item_characters
        title: qsTr("Characters")
        menuDelegate: paneItemMenu
        icon: FluentIcons.People
        // Change to real url
        url: "qrc:/page/Characters.qml"
        onTap: {
            navigationView.push(url)
        }
    }

    FluPaneItem{
        id:item_add
        title: qsTr("Add")
        menuDelegate: paneItemMenu
        icon: FluentIcons.Add
        // Change to real url
        url: "qrc:/page/Add.qml"
        onTap: {
            navigationView.push(url)
        }
    }

    function getRecentlyAddedData(){
        var arr = []
        var items = navigationView.getItems();
        for(var i=0;i<items.length;i++){
            var item = items[i]
            if(item instanceof FluPaneItem && item.extra && item.extra.recentlyAdded){
                arr.push(item)
            }
        }
        arr.sort(function(o1,o2){ return o2.extra.order-o1.extra.order })
        return arr
    }

    function getRecentlyUpdatedData(){
        var arr = []
        var items = navigationView.getItems();
        for(var i=0;i<items.length;i++){
            var item = items[i]
            if(item instanceof FluPaneItem && item.extra && item.extra.recentlyUpdated){
                arr.push(item)
            }
        }
        return arr
    }

    function getSearchData(){
        // change to database search
        if(!navigationView){
            return
        }
        var arr = []
        var items = navigationView.getItems();
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

    function startPageByItem(data){
        navigationView.startPageByItem(data)
    }

}
