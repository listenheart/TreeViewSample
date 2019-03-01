#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "treemodel.h"
#include "treeitem.h"
#include "basetreemodel.h"
#include "treecontrol.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickView view;
    //创建的树的model数据
//    TreeModel* model=new TreeModel;
//    for(int i=0;i<4;i++)
//    {
//        QString text="item:i="+QString::number(i);
//           TreeItem * item1=new TreeItem(QVariant::fromValue(new BaseTreeModel("",text)));
//           for(int j=0;j<4;j++)
//           {
//               QString text2=text+";j="+QString::number(j);
//                TreeItem * item2=new TreeItem(QVariant::fromValue(new BaseTreeModel("",text2)));
//                for(int z=0;z<4;z++)
//                {
//                    QString text3=text2+";z="+QString::number(z);
//                     TreeItem * item3=new TreeItem(QVariant::fromValue(new BaseTreeModel("",text3)));

//                     item2->appendChild(item3);
//                }
//                item1->appendChild(item2);
//           }
//           model->rootItem()->appendChild(item1);
//    }
    //将model传入到qml中
    TreeControl* treeControl=new TreeControl();
    view.rootContext()->setContextProperty("treeControl",treeControl);
    //这个cpp关联到Treeview.qml文件
    view.setSource(QUrl("qrc:/Treeview.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
