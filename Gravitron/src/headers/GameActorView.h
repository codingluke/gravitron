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
        map<string, string> getProperties() const;
        string toString() const;
        void fromString(string serialized);

    private:
        vector<string> split(const string& value, char separator)
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
        };
};

#endif
