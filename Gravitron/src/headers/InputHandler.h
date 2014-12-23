#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <QObject>
#include <set>

using namespace std;

typedef void (*callback)(void);

class InputHandler : public QObject
{
    Q_OBJECT

    protected:
      set<int> inputs;
      map<int, callback> bindings;

    public:
        InputHandler();

        void bindFunction(int code, callback func);
        void execute();

    protected:
        bool eventFilter(QObject *obj, QEvent *event);
};

#endif
