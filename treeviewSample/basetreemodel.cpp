#include "basetreemodel.h"

BaseTreeModel::BaseTreeModel(QObject *parent) : QObject(parent)
{
 m_isExpaned=false;
}

BaseTreeModel::BaseTreeModel(const QString &Id, const QString &name, QObject *parent):QObject (parent),
    m_Id(Id),
    m_name(name)
{
    m_isExpaned=false;
}

BaseTreeModel::~BaseTreeModel()
{

}

QString BaseTreeModel::Id() const
{
    return m_Id;
}

void BaseTreeModel::setId(const QString &Id)
{
    m_Id = Id;
}

QString BaseTreeModel::name() const
{
    return m_name;
}

void BaseTreeModel::setName(const QString &name)
{
    m_name = name;
}

bool BaseTreeModel::isSelect() const
{
    return m_isSelect;
}

void BaseTreeModel::setIsSelect(bool isSelect)
{
    m_isSelect = isSelect;
   // emit isSelectedChanged();
}

bool BaseTreeModel::isExpaned() const
{
    return m_isExpaned;
}

void BaseTreeModel::setIsExpaned(bool isExpaned)
{
    m_isExpaned = isExpaned;
}
