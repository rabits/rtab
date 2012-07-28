/**
 * @file    cmarker.h
 * @date    2012-07-27T17:58:18+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Marker
 *
 */

#ifndef CMARKER_H
#define CMARKER_H

#include "src/common/common.h"

#include <QObject>

#include <QColor>

class CMarker
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint16  measure READ measure WRITE measure NOTIFY measureChanged)
    Q_PROPERTY(QString title READ title WRITE title NOTIFY titleChanged)
    Q_PROPERTY(QColor  color READ color WRITE color NOTIFY colorChanged)

public:
    explicit CMarker(QObject *parent = 0);
    CMarker(const CMarker &obj);
    CMarker& operator=(const CMarker &obj);

    inline bool operator==(const CMarker &obj) const { return measure() == obj.measure() && title() == obj.title() && color() == obj.color(); }

    // ---API--- //
    inline qint16         measure() const { return m_measure; }
    inline const QString& title()   const { return m_title; }
    inline const QColor&  color()   const { return m_color; }

    inline void measure(const qint16 val) { m_measure = val; emit measureChanged(); }
    inline void title(const QString &val) { m_title = val; emit titleChanged(); }
    inline void color(const QColor &val)  { m_color = val; emit colorChanged(); }

signals:
    void measureChanged();
    void titleChanged();
    void colorChanged();

private:
    static const Qt::GlobalColor DEFAULT_COLOR = Qt::red;
    static const char*           DEFAULT_TITLE;

    qint16  m_measure;
    QString m_title;
    QColor  m_color;
};

#endif // CMARKER_H
