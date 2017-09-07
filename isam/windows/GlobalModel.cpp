#include "GlobalModel.h"

GlobalModel::GlobalModel()
{
    m_window = QVariant();
}

QVariant GlobalModel::getWindow()
{
    return m_window;
}

void GlobalModel::setWindow(QVariant window)
{
    m_window = window;
    emit statusChanged();
}
