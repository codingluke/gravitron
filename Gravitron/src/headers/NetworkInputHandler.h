#ifndef NETWORK_INPUT_HANDLER_H
#define NETWORK_INPUT_HANDLER_H

#include <QObject>
#include <QMutex>
#include <set>
#include <QString>

using namespace std;

/**
 * InputHandler which can be connected through a slot.
 * Can not just Handler NetworkInputs, so the name is a little bit odd.
 *
 * In a refactoring spring, could be merged with the InputHandler.
 */
class NetworkInputHandler : public QObject
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
        NetworkInputHandler();

        set<int> getInputs();
        void removeInputCode(int code);
        void setInputs(set<int> newInputs);
        void setInputsFromString(QString inputStr);

    public slots:
        void receive(QString message);
};

#endif
