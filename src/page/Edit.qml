import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import FluentUI 1.0
import "../component"

FluContentPage{

    id:root
    title: qsTr("Edit")
    signal checkBoxChanged

    property var dataSource : []
    property int sortType: 0
    property bool selectedAll: true
    property string nameKeyword: ""

    onNameKeywordChanged: {
        table_view.filter(function(item){
            if(item.name.includes(nameKeyword)){
                return true
            }
            return false
        })
    }

    Component.onCompleted: {
        loadData(1,1000)
    }

    onCheckBoxChanged: {
        for(var i =0;i< table_view.rows ;i++){
            if(false === table_view.getRow(i).checkbox.options.checked){
                root.selectedAll = false
                return
            }
        }
        root.selectedAll = true
    }

    onSortTypeChanged: {
        table_view.closeEditor()
        if(sortType === 0){
            table_view.sort()
        }else if(sortType === 1){
            table_view.sort(
                        (l, r) =>{
                            var lage = Number(l.age)
                            var rage = Number(r.age)
                            if(lage === rage){
                                return l._key>r._key
                            }
                            return lage>rage
                        });
        }else if(sortType === 2){
            table_view.sort(
                        (l, r) => {
                            var lage = Number(l.age)
                            var rage = Number(r.age)
                            if(lage === rage){
                                return l._key>r._key
                            }
                            return lage<rage
                        });
        }
    }

    FluContentDialog{
        id:custom_update_dialog
        property var text
        property var onAccpetListener
        title: qsTr("Modify the column name")
        negativeText: qsTr("Cancel")
        contentDelegate: Component{
            Item{
                implicitWidth: parent.width
                implicitHeight: 60
                FluTextBox{
                    id:textbox_text
                    anchors.centerIn: parent
                    onTextChanged: {
                        custom_update_dialog.text = textbox_text.text
                    }
                }
                Component.onCompleted: {
                    textbox_text.text = custom_update_dialog.text
                    textbox_text.forceActiveFocus()
                }
            }
        }
        positiveText: qsTr("OK")
        onPositiveClicked:{
            if(custom_update_dialog.onAccpetListener){
                custom_update_dialog.onAccpetListener(custom_update_dialog.text)
            }
        }
        function showDialog(text,listener){
            custom_update_dialog.text = text
            custom_update_dialog.onAccpetListener = listener
            custom_update_dialog.open()
        }
    }

    FluMenu{
        id:pop_filter
        width: 200
        height: 89

        contentItem: Item{

            onVisibleChanged: {
                if(visible){
                    name_filter_text.text = root.nameKeyword
                    name_filter_text.cursorPosition = name_filter_text.text.length
                    name_filter_text.forceActiveFocus()
                }
            }

            FluTextBox{
                id:name_filter_text
                anchors{
                    left: parent.left
                    right: parent.right
                    top: parent.top
                    leftMargin: 10
                    rightMargin: 10
                    topMargin: 10
                }
                iconSource: FluentIcons.Search
            }

            FluButton{
                text: qsTr("Search")
                anchors{
                    bottom: parent.bottom
                    right: parent.right
                    bottomMargin: 10
                    rightMargin: 10
                }
                onClicked: {
                    root.nameKeyword = name_filter_text.text
                    pop_filter.close()
                }
            }

        }

        function showPopup(){
            table_view.closeEditor()
            pop_filter.popup()
        }

    }

    Component{
        id:com_checbox
        Item{
            FluCheckBox{
                anchors.centerIn: parent
                checked: true === options.checked
                animationEnabled: false
                clickListener: function(){
                    var obj = table_view.getRow(row)
                    obj.checkbox = table_view.customItem(com_checbox,{checked:!options.checked})
                    table_view.setRow(row,obj)
                    checkBoxChanged()
                }
            }
        }
    }

    Component{
        id:com_column_filter_name
        Item{
            FluText{
                text: qsTr("Name")
                anchors.centerIn: parent
            }
            FluIconButton{
                width: 20
                height: 20
                iconSize: 12
                verticalPadding:0
                horizontalPadding:0
                iconSource: FluentIcons.Filter
                iconColor: {
                    if("" !== root.nameKeyword){
                        return FluTheme.primaryColor
                    }
                    return FluTheme.dark ?  Qt.rgba(1,1,1,1) : Qt.rgba(0,0,0,1)
                }
                anchors{
                    right: parent.right
                    rightMargin: 3
                    verticalCenter: parent.verticalCenter
                }
                onClicked: {
                    pop_filter.showPopup()
                }
            }
        }
    }

    Component{
        id:com_action
        Item{
            RowLayout{
                anchors.centerIn: parent
                FluButton{
                    text: qsTr("Delete")
                    onClicked: {
                        table_view.closeEditor()
                        table_view.removeRow(row)
                    }
                }
                FluFilledButton{
                    text: qsTr("Edit")
                    onClicked: {
                        var obj = table_view.getRow(row)
                        obj.name = "12345"
                        table_view.setRow(row,obj)
                        showSuccess(JSON.stringify(obj))
                    }
                }
            }
        }
    }


    Component{
        id:com_column_checbox
        Item{
            RowLayout{
                anchors.centerIn: parent
                FluText{
                    text: qsTr("Select All")
                    Layout.alignment: Qt.AlignVCenter
                }
                FluCheckBox{
                    checked: true === root.selectedAll
                    animationEnabled: false
                    Layout.alignment: Qt.AlignVCenter
                    clickListener: function(){
                        root.selectedAll = !root.selectedAll
                        var checked = root.selectedAll
                        itemModel.display = table_view.customItem(com_column_checbox,{"checked":checked})
                        for(var i =0;i< table_view.rows ;i++){
                            var rowData = table_view.getRow(i)
                            rowData.checkbox = table_view.customItem(com_checbox,{"checked":checked})
                            table_view.setRow(i,rowData)
                        }
                    }
                }
            }
        }
    }

    Component{
        id:com_combobox
        FluComboBox {
            anchors.fill: parent
            focus: true
            editText: display
            editable: true
            model: ListModel {
                ListElement { text: "100" }
                ListElement { text: "300" }
                ListElement { text: "500" }
                ListElement { text: "1000" }
            }
            Component.onCompleted: {
                currentIndex=["100","300","500","1000"].findIndex((element) => element === display)
                selectAll()
            }
            onCommit: {
                editTextChaged(editText)
                tableView.closeEditor()
            }
        }
    }

    Component{
        id:com_auto_suggestbox
        FluAutoSuggestBox {
            id: textbox
            anchors.fill: parent
            focus: true
            Component.onCompleted: {
                var data = ["傲来国界花果山水帘洞","傲来国界坎源山脏水洞","大唐国界黑风山黑风洞","大唐国界黄风岭黄风洞","大唐国界骷髅山白骨洞","宝象国界碗子山波月洞","宝象国界平顶山莲花洞","宝象国界压龙山压龙洞","乌鸡国界号山枯松涧火云洞","乌鸡国界衡阳峪黑水河河神府"]
                var result = data.map(function(item) {
                    return {title: item};
                });
                items = result
                textbox.text= String(display)
            }
            onCommit: {
                editTextChaged(textbox.text)
                tableView.closeEditor()
            }
        }
    }

    Component{
        id:com_avatar
        Item{
            FluClip{
                anchors.centerIn: parent
                width: 40
                height: 40
                radius: [20,20,20,20]
                Image{
                    anchors.fill: parent
                    source: {
                        if(options && options.avatar){
                            return options.avatar
                        }
                        return ""
                    }
                    sourceSize: Qt.size(80,80)
                }
            }
        }
    }

    Component{
        id:com_column_update_title
        Item{
            FluText{
                id:text_title
                text: {
                    if(options.title){
                        return options.title
                    }
                    return ""
                }
                anchors.fill: parent
                verticalAlignment: Qt.AlignVCenter
                horizontalAlignment: Qt.AlignHCenter
                elide: Text.ElideRight
            }
            MouseArea{
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    custom_update_dialog.showDialog(options.title,function(text){
                        itemModel.display = table_view.customItem(com_column_update_title,{"title":text})
                    })
                }
            }
        }
    }

    Component{
        id:com_column_sort_age
        Item{
            FluText{
                text: qsTr("Age")
                anchors.centerIn: parent
            }
            ColumnLayout{
                spacing: 0
                anchors{
                    right: parent.right
                    verticalCenter: parent.verticalCenter
                    rightMargin: 4
                }
                FluIconButton{
                    Layout.preferredWidth: 20
                    Layout.preferredHeight: 15
                    iconSize: 12
                    verticalPadding:0
                    horizontalPadding:0
                    iconSource: FluentIcons.ChevronUp
                    iconColor: {
                        if(1 === root.sortType){
                            return FluTheme.primaryColor
                        }
                        return FluTheme.dark ?  Qt.rgba(1,1,1,1) : Qt.rgba(0,0,0,1)
                    }
                    onClicked: {
                        if(root.sortType === 1){
                            root.sortType = 0
                            return
                        }
                        root.sortType = 1
                    }
                }
                FluIconButton{
                    Layout.preferredWidth: 20
                    Layout.preferredHeight: 15
                    iconSize: 12
                    verticalPadding:0
                    horizontalPadding:0
                    iconSource: FluentIcons.ChevronDown
                    iconColor: {
                        if(2 === root.sortType){
                            return FluTheme.primaryColor
                        }
                        return FluTheme.dark ?  Qt.rgba(1,1,1,1) : Qt.rgba(0,0,0,1)
                    }
                    onClicked: {
                        if(root.sortType === 2){
                            root.sortType = 0
                            return
                        }
                        root.sortType = 2
                    }
                }
            }
        }
    }

    FluFrame{
        id:layout_controls
        anchors{
            left: parent.left
            right: parent.right
            top: parent.top
            topMargin: 16
        }
        height: 60

        Row{
            spacing: 8
            anchors{
                left: parent.left
                leftMargin: 16
                rightMargin: 16
                verticalCenter: parent.verticalCenter
            }

            FluDropDownButton{
                id: selectMenu
                text: qsTr("Choose a table")
                FluMenuItem{
                    text: qsTr("Characters")
                    onClicked:{
                        selectMenu.text = text
                        // changeTableView(text)
                    }
                }
                FluMenuItem{
                    text: qsTr("Episodes")
                    onClicked:{
                        selectMenu.text = text
                        // changeTableView(text)
                    }
                }
                FluMenuItem{
                    text: qsTr("Relations")
                    onClicked:{
                        selectMenu.text = text
                        // changeTableView(text)
                    }
                }
            }

            FluButton{
                text: qsTr("Delete Selection")
                onClicked: {
                    var data = []
                    var rows = []
                    for (var i = 0; i < table_view.rows; i++) {
                        var item = table_view.getRow(i);
                        rows.push(item)
                        if (!item.checkbox.options.checked) {
                            data.push(item);
                        }
                    }
                    var sourceModel = table_view.sourceModel;
                    for (i = 0; i < sourceModel.rowCount; i++) {
                        var sourceItem = sourceModel.getRow(i);
                        const foundItem = rows.find(item=> item._key === sourceItem._key)
                        if (!foundItem) {
                            data.push(sourceItem);
                        }
                    }
                    table_view.dataSource = data
                }
            }

            FluFilledButton{
                text: qsTr("Add a row of Data")
                onClicked: {
                    table_view.appendRow(genTestObject())
                }
            }
        }
    }

    FluTableView{
        id:table_view
        anchors{
            left: parent.left
            right: parent.right
            top: layout_controls.bottom
            bottom: gagination.top
        }
        anchors.topMargin: 16
        onRowsChanged: {
            root.checkBoxChanged()
        }
        columnSource:[
            {
                title: table_view.customItem(com_column_checbox,{checked:true}),
                dataIndex: 'checkbox',
                width:100,
                minimumWidth:100,
                maximumWidth:100
            },
            {
                title: table_view.customItem(com_column_filter_name,{title:qsTr("Original Name")}),
                dataIndex: 'name',
                readOnly:true
            },
            {
                title: table_view.customItem(com_column_filter_name,{title:qsTr("Chinese Name")}),
                dataIndex: 'name',
                readOnly:true
            },
            {
                title: qsTr("Breed"),
                dataIndex: 'breed',
                editDelegate: com_auto_suggestbox,
                width:200,
                minimumWidth:100,
                maximumWidth:250
            },
            {
                title: qsTr("Description"),
                dataIndex: 'longstring',
                width:200,
                minimumWidth:100,
                maximumWidth:300,
                editMultiline: true
            },
            {
                title: qsTr("Options"),
                dataIndex: 'action',
                width:160,
                minimumWidth:160,
                maximumWidth:160
            }
        ]
    }

    FluPagination{
        id:gagination
        anchors{
            bottom: parent.bottom
            left: parent.left
        }
        pageCurrent: 1
        itemCount: 100000
        pageButtonCount: 7
        __itemPerPage: 1000
        previousText: qsTr("<Previous")
        nextText: qsTr("Next>")
        onRequestPage:
            (page,count)=> {
                table_view.closeEditor()
                loadData(page,count)
                table_view.resetPosition()
            }
    }

    function genTestObject(){
        var names = ["布鲁伊", "班底特", "奇莉", "宾果","麦肯齐","罗斯奇","玛芬","条纹"];
        function getRandomName(){
            var randomIndex = Math.floor(Math.random() * names.length);
            return names[randomIndex];
        }
        var names_en = ["Bluey","Bandit","Chilli","Bingo","Mackenzie","Rusty","Muffin","Stripe"]
        function getRandomames_en(){
            var randomIndex = Math.floor(Math.random() * names_en.length);
            return names_en[randomIndex];
        }
        var breed = ["蓝色澳大利亚牧牛犬","红色澳大利亚牧牛犬","边境牧羊犬","红色科尔比犬","杰克罗素犬"]
        function getRandomBreed(){
            var randomIndex = Math.floor(Math.random() * breed.length);
            return breed[randomIndex];
        }
        return {
            checkbox: table_view.customItem(com_checbox,{checked:root.selectedAll}),
            name: getRandomName(),
            names_en: getRandomames_en(),
            breed: getRandomBreed(),
            longstring: "布鲁伊是一只精力充沛的蓝色澳大利亚牧牛小狗，与爸爸妈妈和妹妹宾果生活在一起。她喜欢笑，喜欢玩，但更喜欢和家人一起玩游戏。",
            action: table_view.customItem(com_action),
            _minimumHeight: 48,
            _key:FluTools.uuid()
        }
    }
    function loadData(page,count){
        root.selectedAll = true
        const dataSource = []
        for(var i=0;i<count;i++){
            dataSource.push(genTestObject())
        }
        root.dataSource = dataSource
        table_view.dataSource = root.dataSource
    }
}
