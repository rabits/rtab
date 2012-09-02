/**
 * @file    pstyle.h
 * @date    2012-07-01T02:18:31+0400
 *
 * @author  Rabits <home.rabits@gmail.com>
 * @copyright GNU General Public License, version 3 <http://www.gnu.org/licenses/>
 *
 * This file is a part of rTab project <https://github.com/rabits/rtab>
 *
 * @brief   Style basic
 *
 */

#ifndef PSTYLE_H
#define PSTYLE_H

#include <QObject>
#include <QColor>

class PStyle
    : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool   inverted  READ inverted WRITE inverted NOTIFY invertedChanged)
    Q_PROPERTY(qint16 size      READ size WRITE size NOTIFY sizeChanged)
    Q_PROPERTY(qint16 lineWidth READ lineWidth WRITE lineWidth NOTIFY lineWidthChanged)
    Q_PROPERTY(bool   smooth    READ smooth WRITE smooth NOTIFY smoothChanged)

    Q_PROPERTY(qint16 leftPadding     READ leftPadding WRITE leftPadding NOTIFY leftPaddingChanged)
    Q_PROPERTY(qint16 rightPadding    READ rightPadding WRITE rightPadding NOTIFY rightPaddingChanged)
    Q_PROPERTY(qint16 topPadding      READ topPadding WRITE topPadding NOTIFY topPaddingChanged)
    Q_PROPERTY(qint16 bottomPadding   READ bottomPadding WRITE bottomPadding NOTIFY bottomPaddingChanged)

    Q_PROPERTY(QColor foregroundColor         READ foregroundColor WRITE foregroundColor NOTIFY foregroundColorChanged)
    Q_PROPERTY(QColor backgroundColor         READ backgroundColor WRITE backgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor borderColor             READ borderColor WRITE borderColor NOTIFY borderColorChanged)
    Q_PROPERTY(QColor selectedForegroundColor READ selectedForegroundColor WRITE selectedForegroundColor NOTIFY selectedForegroundColorChanged)
    Q_PROPERTY(QColor selectedBackgroundColor READ selectedBackgroundColor WRITE selectedBackgroundColor NOTIFY selectedBackgroundColorChanged)
    Q_PROPERTY(QColor selectedBorderColor     READ selectedBorderColor WRITE selectedBorderColor NOTIFY selectedBorderColorChanged)

public:
    explicit PStyle(QObject *parent = 0);
    PStyle(const PStyle &obj);
    PStyle& operator=(const PStyle &obj);

    inline bool operator==(const PStyle &obj) const { return inverted() == obj.inverted() && size() == obj.size() && lineWidth() == obj.lineWidth()
                                                             && smooth() == obj.smooth() && leftPadding() == obj.leftPadding()
                                                             && rightPadding() == obj.rightPadding() && topPadding() == obj.topPadding()
                                                             && bottomPadding() == obj.bottomPadding() && foregroundColor() == obj.foregroundColor()
                                                             && backgroundColor() == obj.backgroundColor() && borderColor() == obj.borderColor()
                                                             && selectedForegroundColor() == obj.selectedForegroundColor()
                                                             && selectedBackgroundColor() == obj.selectedBackgroundColor()
                                                             && selectedBorderColor() == obj.selectedBorderColor(); }

    inline static const PStyle defaultStyle() { return PStyle(); }

    // --API--- //
    inline bool             inverted()                const { return m_inverted; }
    inline qint16           size()                    const { return m_size; }
    inline qint16           lineWidth()               const { return m_lineWidth; }
    inline bool             smooth()                  const { return m_smooth; }
    inline qint16           leftPadding()             const { return m_leftPadding; }
    inline qint16           rightPadding()            const { return m_rightPadding; }
    inline qint16           topPadding()              const { return m_topPadding; }
    inline qint16           bottomPadding()           const { return m_bottomPadding; }
    inline const QColor&    foregroundColor()         const { return m_foregroundColor; }
    inline const QColor&    backgroundColor()         const { return m_backgroundColor; }
    inline const QColor&    borderColor()             const { return m_borderColor; }
    inline const QColor&    selectedForegroundColor() const { return m_selectedForegroundColor; }
    inline const QColor&    selectedBackgroundColor() const { return m_selectedBackgroundColor; }
    inline const QColor&    selectedBorderColor()     const { return m_selectedBorderColor; }

    inline void inverted(const bool val)                   { if( m_inverted == val ) return; m_inverted = val; emit invertedChanged(); }
    inline void size(const qint16 val)                     { if( m_size == val ) return; m_size = val; emit sizeChanged(); }
    inline void lineWidth(const qint16 val)                { if( m_lineWidth == val ) return; m_lineWidth = val; emit lineWidthChanged(); }
    inline void smooth(const bool val)                     { if( m_smooth == val ) return; m_smooth = val; emit smoothChanged(); }
    inline void leftPadding(const qint16 val)              { if( m_leftPadding == val ) return; m_leftPadding = val; emit leftPaddingChanged(); }
    inline void rightPadding(const qint16 val)             { if( m_rightPadding == val ) return; m_rightPadding = val; emit rightPaddingChanged(); }
    inline void topPadding(const qint16 val)               { if( m_topPadding == val ) return; m_topPadding = val; emit topPaddingChanged(); }
    inline void bottomPadding(const qint16 val)            { if( m_bottomPadding == val ) return; m_bottomPadding = val; emit bottomPaddingChanged(); }
    inline void foregroundColor(const QColor &val)         { if( m_foregroundColor == val ) return; m_foregroundColor = val; emit foregroundColorChanged(); }
    inline void backgroundColor(const QColor &val)         { if( m_backgroundColor == val ) return; m_backgroundColor = val; emit backgroundColorChanged(); }
    inline void borderColor(const QColor &val)             { if( m_borderColor == val ) return; m_borderColor = val; emit borderColorChanged(); }
    inline void selectedForegroundColor(const QColor &val) { if( m_selectedForegroundColor == val ) return; m_selectedForegroundColor = val; emit selectedForegroundColorChanged(); }
    inline void selectedBackgroundColor(const QColor &val) { if( m_selectedBackgroundColor == val ) return; m_selectedBackgroundColor = val; emit selectedBackgroundColorChanged(); }
    inline void selectedBorderColor(const QColor &val)     { if( m_selectedBorderColor == val ) return; m_selectedBorderColor = val; emit selectedBorderColorChanged(); }

signals:
    void invertedChanged();
    void sizeChanged();
    void lineWidthChanged();
    void smoothChanged();
    void leftPaddingChanged();
    void rightPaddingChanged();
    void topPaddingChanged();
    void bottomPaddingChanged();
    void foregroundColorChanged();
    void backgroundColorChanged();
    void borderColorChanged();
    void selectedForegroundColorChanged();
    void selectedBackgroundColorChanged();
    void selectedBorderColorChanged();

protected:
    bool   m_inverted;
    qint16 m_size;
    qint16 m_lineWidth;
    bool   m_smooth;
    qint16 m_leftPadding;
    qint16 m_rightPadding;
    qint16 m_topPadding;
    qint16 m_bottomPadding;
    QColor m_foregroundColor;
    QColor m_backgroundColor;
    QColor m_borderColor;
    QColor m_selectedForegroundColor;
    QColor m_selectedBackgroundColor;
    QColor m_selectedBorderColor;
};

#endif // PSTYLE_H
