#ifndef Commodity_H
#define Commodity_H

#include <QString>
#include <QObject>
#include "DomainObject.h"

class Commodity : public QObject, public DomainObject
{
    Q_OBJECT
public:
    Commodity();
    virtual ~Commodity();

    void fromJson(const QJsonObject data);
    QJsonObject toJson();

    QString getId();
    void setId(QString id);

    /*"/Music/I miss.mp3"*/

    QString getName();      /*I miss.mp3*/
    void setName(QString name);

    QString getMusicName(); /*I miss*/
    void setMusicName(QString musicName);

    QString getPathName();  /*/Music/I miss.mp3*/
    void setPathName(QString pathName);



private:
    QString m_id;
    QString m_name;
    QString m_pathName;
    QString m_musicName;
};

#endif // Commodity_H
