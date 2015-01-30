#ifndef GAMEACTORVIEW_H
#define GAMEACTORVIEW_H

#include <string>
#include <map>
#include <vector>

using namespace std;

/**
 * Definition of a GameActorView. It is a general representation of the properties
 * of a GameActor. The GameActorView can be serialized. It is specially designed
 * to be rendered through QML.
 */
class GameActorView
{
    private:
      /**
       * Path of the QML File.
       */
      string qmlPath;

      /**
       * Key/Value map of properties.
       */
      map<string, string> properties;

    public:
        GameActorView();
        GameActorView(string theQmlPath);

        string getQmlPath() const;
        void setProperty(string key, string value);
        void setProperty(string key, float value);
        void setProperty(string key, bool value);
        void setProperty(string key, int value);
        string getPropterty(string key);
        map<string, string> getProperties() const;
        string toString() const;
        void fromString(string serialized);

    private:
        vector<string> split(const string& value, char separator);
};

#endif
