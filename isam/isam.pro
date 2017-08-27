TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    infrastructure/domain/DomainObject.cpp \
    infrastructure/domain/BaseListModel.cpp \
    infrastructure/domain/BaseItemModel.cpp \
    infrastructure/utils/Themes.cpp \
    infrastructure/repertory/CommodityRepertory.cpp \
    domain/Commodity.cpp \
    model/CommodityModel.cpp \
    model/CommodityListModel.cpp \
    service/CommodityService.cpp \
    model/SalesCommodity/SalesCommodityListModel.cpp \
    service/SalesCommodity/SalesCommodityService.cpp \
    model/SalesCommodity/SalesCommodityEditModel.cpp \
    model/GettingCommodity/GettingCommodityListModel.cpp \
    model/BaseCommodity/BaseCommodityModel.cpp \
    service/SalesQuery/SalesQueryService.cpp \
    infrastructure/utils/FuzzySearchTool.cpp \
    model/SalesQuery/SalesQueryListModel.cpp \
    service/CommodityQuery/CommodityQueryService.cpp \
    service/CommodityQuery/CommodityQueryCondition.cpp \
    model/CommodityQuery/CommodityQueryListModel.cpp

RESOURCES += qml.qrc

INCLUDEPATH += infrastructure/domain \
               infrastructure/utils \
               infrastructure/repertory \
               infrastructure/enum

INCLUDEPATH += model \
               model/BaseCommodity \
               model/SalesCommodity \
               model/GettingCommodity \
               model/SalesQuery \
               model/CommodityQuery

INCLUDEPATH += service \
               service/SalesCommodity \
               service/SalesQuery \
               service/CommodityQuery

INCLUDEPATH += domain

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    infrastructure/domain/ObjectListModelImpl.h \
    infrastructure/domain/ObjectListModel.h \
    infrastructure/domain/JsonListConvertorImpl.h \
    infrastructure/domain/JsonListConvertor.h \
    infrastructure/domain/DomainObject.h \
    infrastructure/domain/BaseListModel.h \
    infrastructure/domain/BaseItemModel.h \
    infrastructure/utils/Themes.h \
    infrastructure/repertory/CommodityRepertory.h \
    domain/Commodity.h \
    model/CommodityModel.h \
    model/CommodityListModel.h \
    service/CommodityService.h \
    model/SalesCommodity/SalesCommodityListModel.h \
    service/SalesCommodity/SalesCommodityService.h \
    model/SalesCommodity/SalesCommodityEditModel.h \
    model/GettingCommodity/GettingCommodityListModel.h \
    model/BaseCommodity/BaseCommodityModel.h \
    service/SalesQuery/SalesQueryService.h \
    infrastructure/utils/FuzzySearchTool.h \
    model/SalesQuery/SalesQueryListModel.h \
    infrastructure/enum/EnumComplete.h \
    service/CommodityQuery/CommodityQueryService.h \
    service/CommodityQuery/CommodityQueryCondition.h \
    model/CommodityQuery/CommodityQueryListModel.h
