#ifndef ENUMCOMPLETE_H
#define ENUMCOMPLETE_H

#include <QObject>

class EnumComplete : public QObject
{
    Q_OBJECT

public:
    EnumComplete() { }

    enum Priority { High, Low, VeryHigh, VeryLow };
    Q_ENUM(Priority)
//    void setPriority(Priority priority);
//    Priority priority() const;
};

#endif // ENUMCOMPLETE_H
