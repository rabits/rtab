#ifndef CSCALE_H
#define CSCALE_H

#include "src/common/common.h"

#include <QObject>

class CScale
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int key READ key WRITE key NOTIFY keyChanged)

public:
    explicit CScale(QObject *parent = 0);

    // ---API--- //
    inline int key() const { return m_key; }

    inline void key(const int val) { m_key = val; emit keyChanged(); }

    inline bool note(const uint note)          const { return m_notes[((note + (12 - key())) % 12)]; }
    inline void note(const uint note, const int val) { if( note < 12 ) { m_notes[note] = val; emit notesChanged(); } }

    void clear();

signals:
    void keyChanged();
    void notesChanged();

private:
    int        m_key;
    bool m_notes[12];
};

#endif // CSCALE_H
