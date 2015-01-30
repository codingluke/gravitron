#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <QObject>
#include <QMutex>
#include <set>
#include "Spacecraft.h"

using namespace std;

/**
 * Event Filter for the QCoreApplication. It filters out
 * the keyboad events and writes the codes into the inputs list.
 * Has a mutex for that the inputs list can be accessed over differen threads.
 */
class InputHandler : public QObject
{
    Q_OBJECT

    private:
        /**
         * Mutex to make input mutations threadsave.
         */
        QMutex mutex;

        /**
         * A set of the input codes.
         */
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
