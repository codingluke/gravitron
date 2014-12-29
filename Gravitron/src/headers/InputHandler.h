#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <QObject>
#include <QMutex>
#include <set>
#include "Spacecraft.h"

using namespace std;

typedef void (Spacecraft::*callback)();

class InputHandler : public QObject
{
    Q_OBJECT

    private:
      set<int> inputs;
      QMutex mutex;

    public:
        InputHandler();
        set<int> getInputs();
        void removeInputCode(int code);
        void insertInputCode(int code);

    protected:
        bool eventFilter(QObject *obj, QEvent *event);
};

#endif
