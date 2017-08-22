TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    infrastructure/domain/DomainObject.cpp \
    infrastructure/domain/BaseListModel.cpp \
    infrastructure/domain/BaseItemModel.cpp \
    infrastructure/utils/Themes.cpp

RESOURCES += qml.qrc

INCLUDEPATH += infrastructure/domain \
               infrastructure/utils

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
    infrastructure/utils/Themes.h
