#include "headers/GameActorView.h"

using namespace std;

GameActorView::GameActorView(string theQmlPath) : qmlPath(theQmlPath)
{
}

string GameActorView::getQmlPath() const
{
    return qmlPath;
}

void GameActorView::setProperty(string key, string value)
{
    properties[key] = value;
}

map<string, string> GameActorView::getProperties() const
{
    return properties;
}

