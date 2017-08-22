TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    Infrastructure/domain/DomainObject.cpp \
    Infrastructure/domain/BaseListModel.cpp \
    Infrastructure/domain/BaseItemModel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Infrastructure/domain/ObjectListModelImpl.h \
    Infrastructure/domain/ObjectListModel.h \
    Infrastructure/domain/JsonListConvertorImpl.h \
    Infrastructure/domain/JsonListConvertor.h \
    Infrastructure/domain/DomainObject.h \
    Infrastructure/domain/BaseListModel.h \
    Infrastructure/domain/BaseItemModel.h
