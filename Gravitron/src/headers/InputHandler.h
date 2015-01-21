#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <QObject>
#include <QMutex>
#include <set>
#include "Spacecraft.h"

using namespace std;

class InputHandler : public QObject
{
    Q_OBJECT

    private:
      QMutex mutex;
      set<int> inputs;

    public:
        InputHandler();

        set<int> getInputs();
        void removeInputCode(int code);
        void insertInputCode(int code);

    signals:
        void inputsChanged(set<int> inputs);

    protected:
        bool eventFilter(QObject *obj, QEvent *event);
};

#endif
