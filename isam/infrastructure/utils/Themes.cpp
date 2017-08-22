#include "Themes.h"

Themes::Themes()
{
    m_backgroundColor = "#00000000";
}

QString Themes::getBackgroundColor()
{
    return m_backgroundColor;
}

void Themes::setBackgroundColor(QString color)
{
    m_backgroundColor = color;
    emit statusChanged();
}
