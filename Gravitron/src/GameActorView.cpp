#include "headers/GameActorView.h"
#include <iostream>
#include <sstream>

using namespace std;

GameActorView::GameActorView()
{
}

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

string GameActorView::toString() const
{
    ostringstream x;
    x << "qml_" << qmlPath << ",";
    map<string, string> props = getProperties();
    map<string, string>::iterator pit;
    for(pit = props.begin(); pit != props.end(); pit++) {
        x << pit->first << "_" << pit->second << ",";
    }
    return x.str();
}

void GameActorView::fromString(string serialized)
{
    vector<string> props = split(serialized, ',');
    vector<string>::iterator pit;
    for(pit = props.begin(); pit != props.end(); pit++) {
        vector<string> prop = split((*pit), '_');
        if (prop.size() == 2) {
            if (prop.at(0) == "qml" || prop.at(0) == "vqml") {
                qmlPath = prop.at(1);
            } else {
                setProperty(prop.at(0), prop.at(1));
            }
        }
    }
}

vector<string> GameActorView::split(const string& value, char separator)
{
    vector<string> result;
    string::size_type p = 0;
    string::size_type q;
    while ((q = value.find(separator, p)) != string::npos) {
        result.emplace_back(value, p, q - p);
        p = q + 1;
    }
    result.emplace_back(value, p);
    return result;
}
        