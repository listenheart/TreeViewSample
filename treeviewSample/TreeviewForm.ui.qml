import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.2

Item {
    width: 400
    height: 400
    property alias treeview: treeview
    property alias btnrefuse: btnRefuse
    property alias btnrefuse1: btnRefuse1
    property alias remove: remove
    Rectangle {
        width: row.width
        height: row.height
        color: "#a00050ee"
        border.color: "black"
        border.width: 1
        radius: 2
    }
    RowLayout {
        id: row
        width: parent.width
        height: 40
        Button {
            text: "add"
        }
        Button {
            id: remove
            text: "remove"
        }
        Button {
            id: btnRefuse
            text: "刷新"
        }

        Button {
            id: btnRefuse1
            text: "刷新"
        }
    }
    TreeView {
        signal itemcheckChanged(var index, var checked)
        id: treeview
        width: parent.width
        anchors.top: row.bottom
        anchors.bottom: parent.bottom
        //        signal itemRightClick(var index)
        itemDelegate: ItemDelegate {
            onCheckBoxItemChanged: function (ind, checkt) {
                treeview.itemcheckChanged(ind, checkt)
            }
        }
        TableViewColumn {
            role: "name"
            title: "Name"
        }
    }
}
