#ifndef GAMEACTORVIEW_H
#define GAMEACTORVIEW_H

#include <string>
#include <map>

using namespace std;

class GameActorView
{
    private:
      string qmlPath;
      map<string, string> properties;

    public:
        GameActorView(string theQmlPath);

        string getQmlPath() const;
        void setProperty(string key, string value);
        map<string, string> getProperties() const;
};

#endif
