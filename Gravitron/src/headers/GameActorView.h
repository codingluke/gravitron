#ifndef GAMEACTORVIEW_H
#define GAMEACTORVIEW_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <string>

using namespace std;

class GameActorView: public QObject
{
    private:
      string qmlPath;

    public:
        GameActorView(string theQmlPath);

        string getQmlPath() const;
};

#endif
