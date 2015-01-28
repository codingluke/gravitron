#ifndef GAMEACTORVIEW_H
#define GAMEACTORVIEW_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class GameActorView
{
    private:
      string qmlPath;
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
