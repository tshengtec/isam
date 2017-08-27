#include "SalesQueryService.h"
#include <QRegExp>
#include <QDebug>
#include <QString>

SalesQueryService * SalesQueryService::_instance = NULL;


SalesQueryService::SalesQueryService()
{
}

SalesQueryService *SalesQueryService::instance()
{
    if (_instance == NULL) {
        _instance = new SalesQueryService();
    }
    return _instance;
}
