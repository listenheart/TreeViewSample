import QtQuick 2.7

TreeviewForm {

    Component.onCompleted: function(){
        treeview.model=treeControl.getModel();
        //item的checkbox改变调用
        treeview.itemcheckChanged.connect(treeViewCheckChanged);
        //删除之后直接调用刷新
        treeControl.resetTree.connect(refuseModel);
    }
    //调用了modelReset会闪烁的刷新（删除的时候用这个）
    btnrefuse.onClicked: {
         refuseModel(treeControl.getModel())
    }
    //调用了layoutChanged的刷新
    btnrefuse1.onClicked: {
         refuseModel1(treeControl.getModel())
    }
    //移除tree上的某一个item，这里要删除的item的index通过treeview点击的时候传给c++了
    remove.onClicked: {
        treeControl.remove()
    }
    //点击tree上面的某一个item将index传给c++
    treeview.onClicked: function(index){
        treeControl.treeClicked(index)
    }
    function treeViewCheckChanged(index,checked){
        treeControl.itemCheckedChanged(index,checked);
    }

    function expanexAll(parindex)
    {
        var count=treeControl.getModel().rowCount(parindex);
        for(var i=0;i<count;i++)
        {
            var index= treeControl.getModel().index(i,0,parindex);
            var isExpaned= treeControl.getModel().dataisExpand(index);
            if( isExpaned){
                if(!treeview.isExpanded(index))
                    treeview.expand(index);
                expanexAll(index);
            }
        }
    }
    //闪烁的刷新
    function refuseModel(model2)
    {
        var conty=treeview.flickableItem.contentY;
        model2.modelReset();
        expanexAll();
        treeview.flickableItem.contentY=conty;
    }
    //不闪烁的刷新
    function refuseModel1(model2)
    {
        var conty=treeview.flickableItem.contentY;
        model2.layoutChanged();
        treeview.flickableItem.contentY=conty;
    }

}
