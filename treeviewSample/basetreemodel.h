#ifndef BASETREEMODEL_H
#define BASETREEMODEL_H

#include <QObject>

class BaseTreeModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString id READ Id WRITE setId)
    Q_PROPERTY(bool isSelect READ isSelect WRITE setIsSelect NOTIFY isSelectedChanged)
    Q_PROPERTY(bool isExpaned READ isExpaned WRITE setIsExpaned)
public:
    explicit BaseTreeModel(QObject *parent = nullptr);
     explicit BaseTreeModel(const QString &Id,const QString &name,QObject *parent = nullptr);
    ~BaseTreeModel();
    QString Id() const;
    void setId(const QString &Id);

    QString name() const;
    void setName(const QString &name);

    bool isSelect() const;
    void setIsSelect(bool isSelect);

    bool isExpaned() const;
    void setIsExpaned(bool isExpaned);

signals:
  void  isSelectedChanged();

protected:
    QString m_Id;
    QString m_name;
    bool m_isSelect;
    bool m_isExpaned;
};

#endif // BASETREEMODEL_H
