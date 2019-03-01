import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

  Item {
        id: itemviewdt
        property var itemData: styleData.value
        property  var index: styleData.index
        property var itemExpaned: styleData.isExpanded
        signal checkBoxItemChanged(var index,bool check)
        onItemExpanedChanged: {
            // 记录展开状态
            itemData.isExpaned=itemExpaned
        }
        // 数据变化重新绑定数据的过程
        onItemDataChanged: {
//            if(check.checked!==itemData.isSelect)
//            {
                check.ignoreCheck=true;
                check.checked=itemData.isSelect;
                check.ignoreCheck=false;
//            }
        }

        CheckBox{
            property bool ignoreCheck:false
            id:check
            checked: itemData.isSelect
            onCheckedChanged:{
                if(!ignoreCheck)
                itemviewdt.checkBoxItemChanged(index,check.checked);
            }

        }
        Text {
            id:text
            anchors.left: check.right
            text: itemData.name
        }
    }
