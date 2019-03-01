#include "basetreemodel.h"
#include "treecontrol.h"
#include "treeitem.h"
#include "treemodel.h"

TreeControl::TreeControl()
{
    CreateModel();
}

void TreeControl::CreateModel()
{
    TreeModel* model=new TreeModel;
    for(int i=0;i<14;i++)
    {
        QString text="item:i="+QString::number(i);
        BaseTreeModel* basemodel1=new BaseTreeModel("",text);
        basemodel1->setIsSelect(false);
           TreeItem * item1=new TreeItem(QVariant::fromValue(basemodel1));
           for(int j=0;j<14;j++)
           {
               QString text2=text+";j="+QString::number(j);
               BaseTreeModel* basemodel2=new BaseTreeModel("",text2);
               basemodel2->setIsSelect(false);
                TreeItem * item2=new TreeItem(QVariant::fromValue(basemodel2));
                for(int z=0;z<14;z++)
                {
                    QString text3=text2+";z="+QString::number(z);
                    BaseTreeModel* basemodel3=new BaseTreeModel("",text3);
                    basemodel3->setIsSelect(false);
                     TreeItem * item3=new TreeItem(QVariant::fromValue(basemodel3));

                     item2->appendChild(item3);
                }
                item1->appendChild(item2);
           }
           model->rootItem()->appendChild(item1);
    }
    m_treeModel=model;
}

QAbstractItemModel *TreeControl::getModel()
{
    return m_treeModel;
}

void TreeControl::remove()
{
    TreeItem* item=static_cast<TreeItem*>(m_curIndex.internalPointer());
    TreeItem* parentItem=item->parentItem();
    if(parentItem==NULL)
        parentItem=m_treeModel->rootItem();
    item->parentItem()->removeChild(item);
    emit resetTree(m_treeModel);

}

void  CheckedTreeItem(TreeItem* item,bool checked,std::vector<BaseTreeModel*>& selectResult)
{
    if(!item)
        return;
    BaseTreeModel * model=qobject_cast<BaseTreeModel*>(item->dataObj(0));
    if(model)
    {
        model->setIsSelect(checked);
//        std::vector<BaseTreeModel*>::iterator it=std::find(selectResult.begin(),selectResult.end(),model);
//        if(checked&& it==selectResult.end())
//            selectResult.push_back(model);
//        else if(!checked&& it!=selectResult.end())
//            selectResult.erase(it);
//        return;
    }
    for(int i=0,size=item->childCount();i<size;i++)
        CheckedTreeItem(item->child(i),checked,selectResult);
}

void TreeControl::itemCheckedChanged(QModelIndex index,bool checked)
{
    TreeItem *item =static_cast<TreeItem*>(index.internalPointer());
    if(!item)
        return;
    //操作选择集的过程
    CheckedTreeItem(item,checked,m_ptrSelectModels);
    m_treeModel->layoutChanged();
}


void TreeControl::treeClicked(QModelIndex index)
{
    m_curIndex=index;
}


