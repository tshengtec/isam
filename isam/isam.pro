TEMPLATE = app
QT += qml quick
QT += network
QT += sql
QT += widgets
CONFIG += c++11

win32: RC_FILE += logo.rc

equals( QT_MAJOR_VERSION, 5 ) {
    QT += qml quick widgets
    DEFINES += QT5VERSION
    message(" ================ QT 5 VERSION ================ ")
}
else {
    QT += widgets declarative
    DEFINES += QT4VERSION
    message(" ================ QT 4 VERSION================= ")
}

SOURCES += main.cpp \
    infrastructure/domain/DomainObject.cpp \
    infrastructure/domain/BaseListModel.cpp \
    infrastructure/domain/BaseItemModel.cpp \
    infrastructure/utils/Themes.cpp \
    infrastructure/repertory/CommodityRepertory.cpp \
    domain/Commodity.cpp \
    model/SalesCommodity/SalesCommodityListModel.cpp \
    service/SalesCommodity/SalesCommodityService.cpp \
    model/SalesCommodity/SalesCommodityEditModel.cpp \
    model/BaseCommodity/BaseCommodityModel.cpp \
    service/SalesQuery/SalesQueryService.cpp \
    infrastructure/utils/FuzzySearchTool.cpp \
    model/SalesQuery/SalesQueryListModel.cpp \
    service/CommodityQuery/CommodityQueryService.cpp \
    service/CommodityQuery/CommodityQueryCondition.cpp \
    model/CommodityQuery/CommodityQueryListModel.cpp \
    service/SalesCommodity/SalesNote.cpp \
    service/SalesQuery/SalesQueryCondition.cpp \
    model/SalesQuery/SalesDocumentsListModel.cpp \
    model/SalesQuery/SalesDocumentsModel.cpp \
    service/AccountService/AccountService.cpp \
    model/AccountModel/AccountModel.cpp \
    domain/AccountItem.cpp \
    model/AccountModel/AccountListModel.cpp \
    windows/QmlWin.cpp \
    windows/MyGuiApplication.cpp \
    windows/GlobalModel.cpp \
    service/NetworkService/NetworkService.cpp \
    service/NetworkService/AccountNetworkService.cpp \
    service/NetworkService/CommodityCategoryNetworkService.cpp \
    service/ConfigService/ConfigService.cpp \
    infrastructure/repertory/GoodsSqlRepo.cpp \
    windows/WinManager.cpp \
    windows/Window.cpp \
    windows/DeclarativeWindow.cpp

RESOURCES += qml.qrc \
    resources.qrc

INCLUDEPATH += windows

INCLUDEPATH += infrastructure/domain \
               infrastructure/utils \
               infrastructure/repertory \
               infrastructure/enum

INCLUDEPATH += model \
               model/BaseCommodity \
               model/SalesCommodity \
               model/GettingCommodity \
               model/SalesQuery \
               model/CommodityQuery \
               model/AccountModel

INCLUDEPATH += service \
               service/SalesCommodity \
               service/SalesQuery \
               service/CommodityQuery \
               service/AccountService \
               service/NetworkService \
               service/ConfigService

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
    model/SalesCommodity/SalesCommodityListModel.h \
    service/SalesCommodity/SalesCommodityService.h \
    model/SalesCommodity/SalesCommodityEditModel.h \
    model/BaseCommodity/BaseCommodityModel.h \
    service/SalesQuery/SalesQueryService.h \
    infrastructure/utils/FuzzySearchTool.h \
    model/SalesQuery/SalesQueryListModel.h \
    infrastructure/enum/EnumComplete.h \
    service/CommodityQuery/CommodityQueryService.h \
    service/CommodityQuery/CommodityQueryCondition.h \
    model/CommodityQuery/CommodityQueryListModel.h \
    service/SalesCommodity/SalesNote.h \
    service/SalesQuery/SalesQueryCondition.h \
    model/SalesQuery/SalesDocumentsListModel.h \
    model/SalesQuery/SalesDocumentsModel.h \
    service/AccountService/AccountService.h \
    model/AccountModel/AccountModel.h \
    domain/AccountItem.h \
    model/AccountModel/AccountListModel.h \
    windows/QmlWin.h \
    windows/MyGuiApplication.h \
    windows/GlobalModel.h \
    service/NetworkService/NetworkService.h \
    service/NetworkService/AccountNetworkService.h \
    service/NetworkService/CommodityCategoryNetworkService.h \
    service/ConfigService/ConfigService.h \
    infrastructure/utils/GlobalDefinition.h \
    infrastructure/repertory/GoodsSqlRepo.h \
    windows/WinManager.h \
    windows/Window.h \
    windows/DeclarativeWindow.h

DISTFILES += \
    model/AccountModel/AccountListModel.qml

DEFINES += VERSION_0.7.9
