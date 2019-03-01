#include <QAbstractItemModel>

#pragma once
class BaseTreeModel;
class TreeModel;
class TreeControl:public QObject
{
    Q_OBJECT
public:
    TreeControl();
//    ~TreeControl();
    void CreateModel();
    Q_INVOKABLE QAbstractItemModel* getModel();
    Q_INVOKABLE void remove();
    Q_INVOKABLE void treeClicked(QModelIndex index);
    Q_INVOKABLE void itemCheckedChanged(QModelIndex index, bool checked);
signals:
    void resetTree(QAbstractItemModel* model);
protected:
    TreeModel* m_treeModel;
    QModelIndex m_curIndex;
    std::vector<BaseTreeModel*> m_ptrSelectModels;
};

