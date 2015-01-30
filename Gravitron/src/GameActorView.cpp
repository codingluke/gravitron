#include "headers/GameActorView.h"
#include <iostream>
#include <sstream>

using namespace std;


/**
 * Default constructor.
 */
GameActorView::GameActorView()
{
}

/**
 * Constructor to set the qml Path by initialisation.
 */
GameActorView::GameActorView(string theQmlPath) : qmlPath(theQmlPath)
{
}

/**
 * Returns the QML Path.
 *
 * @return Path to the QML File.
 */
string GameActorView::getQmlPath() const
{
    return qmlPath;
}

/**
 * Setting a property and its value as string.
 *
 * @param key     Key of the property.
 * @param value   Value of the property as float.
 */
void GameActorView::setProperty(string key, string value)
{
    properties[key] = value;
}

/**
 * Setting the porperty and its value as float.
 *
 * @param key     Key of the property.
 * @param value   Value of the property as float.
 */
void GameActorView::setProperty(string key, float value)
{
    ostringstream os;
    os << value;
    setProperty(key, os.str());
}

/**
 * Setting the porperty and its value as bool.
 *
 * @param key     Key of the property.
 * @param value   Value of the property as bool.
 */
void GameActorView::setProperty(string key, bool value)
{
    ostringstream os;
    os << value;
    setProperty(key, os.str());
}

/**
 * Setting the porperty and its value as int.
 *
 * @param key     Key of the property.
 * @param value   Value of the property as int.
 */
void GameActorView::setProperty(string key, int value)
{
    ostringstream os;
    os << value;
    setProperty(key, os.str());
}

/**
 * Returns the value of a property.
 *
 * @param key     Key of the property.
 *
 * @returns value of the property.
 */
string GameActorView::getPropterty(string key)
{
    return properties[key];
}

/**
 * Returns the whole Map with the properties.
 *
 * @return map with all the properties.
 */
map<string, string> GameActorView::getProperties() const
{
    return properties;
}

/**
 * Returns the GameActorView in a string representation
 *
 * @return String representation of the GameActorView
 */
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

/**
 * Setting the state of the GameActorView by a string
 * representation. (Deserialisation)
 *
 * @param serialized  String representation of the new state.
 */
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

/**
 * Helper function. Splits a string by a character and returns a vector
 * with the splitted elements.
 *
 * @param value       String to split.
 * @param separator   Character to split by.
 *
 * @return vector of the splitted strings.
 */
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

