#include "headers/GameActorView.h"
#include <QDebug>

using namespace std;

GameActorView::GameActorView(QObject *parent) : QObject(parent)
{
}

QQuickItem* GameActorView::render(QQmlApplicationEngine *engine, QQuickItem *qmlParent)
{
    QQmlComponent component(engine, QUrl(QStringLiteral("qrc:/qml/CreditsSubMenu.qml")));
    QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());
    childItem->setParentItem(qmlParent);
    return childItem;
}
