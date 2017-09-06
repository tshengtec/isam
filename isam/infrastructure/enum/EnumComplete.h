#ifndef ENUMCOMPLETE_H
#define ENUMCOMPLETE_H

#include <QObject>
enum Priority { High, Low, VeryHigh, VeryLow };

class EnumComplete : public QObject
{
    Q_OBJECT
public:
    EnumComplete() { }
    Q_ENUM(Priority)
};

#endif // ENUMCOMPLETE_H
