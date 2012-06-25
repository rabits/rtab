#ifndef CVOICE_H
#define CVOICE_H

#include "src/common/common.h"

#include <QObject>

#include "cduration.h"
#include "cnote.h"

class CBeat;

class CVoice
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CDuration    duration READ duration WRITE duration NOTIFY durationChanged)
    Q_PROPERTY(QList<CNote> notes READ notes WRITE notes NOTIFY notesChanged)
    Q_PROPERTY(quint8       index READ index WRITE index NOTIFY indexChanged)
    Q_PROPERTY(qint16       direction READ direction WRITE direction NOTIFY directionChanged)
    Q_PROPERTY(bool         empty READ empty WRITE empty NOTIFY emptyChanged)
    Q_PROPERTY(CBeat*       beat READ beat WRITE beat NOTIFY beatChanged)

public:
    explicit CVoice(const quint8 index, QObject *parent = 0);
    CVoice(const CVoice &obj);
    CVoice& operator=(const CVoice &obj);

    inline bool operator==(const CVoice &obj) const { return duration() == obj.duration()
                                                                && index() == obj.index() && direction() == obj.direction()
                                                                && (empty() == obj.empty() || notes() == obj.notes()); }

    enum DIRECTION {
        DIRECTION_NONE = 0,
        DIRECTION_UP   = 1,
        DIRECTION_DOWN = 2
    };

    // ---API--- //
    inline const CDuration&    duration()  const { return m_duration; }
    inline const QList<CNote>& notes()     const { return m_notes; }
    inline quint8              index()     const { return m_index; }
    inline qint16              direction() const { return m_direction; }
    inline bool                empty()     const { return m_empty; }
    inline CBeat*              beat()      const { return p_beat; }

    inline void duration(const CDuration &val) { m_duration = val; emit durationChanged(); }
    inline void notes(const QList<CNote> &val) { m_notes = val; emit notesChanged(); }
    inline void index(const quint8 val)        { m_index = val; emit indexChanged(); }
    inline void direction(const qint16 val)    { m_direction = val; emit directionChanged(); }
    inline void empty(const bool val)          { m_empty = val; emit emptyChanged(); }
    inline void beat(CBeat *val)               { p_beat = val; emit beatChanged(); }

    inline quint16       notesCount()                          const { return m_notes.count(); }
    inline const CNote&  note(const quint16 index)             const { return m_notes[index]; }
    inline void          note(const quint16 index, const CNote &val) { m_notes[index] = val; m_notes[index].voice(this); empty(false); emit notesChanged(); }
    inline void          noteAdd(const CNote &val)                   { m_notes.append(val); m_notes.last().voice(this); empty(false); emit notesChanged(); }
    inline void          noteRemove(const quint16 index)             { m_notes.removeAt(index); emit notesChanged(); }
    inline void          noteRemove(const CNote &val)                { m_notes.removeOne(val); emit notesChanged(); }

    inline bool isRest() const { return notes().isEmpty(); }

signals:
    void durationChanged();
    void notesChanged();
    void indexChanged();
    void directionChanged();
    void emptyChanged();
    void beatChanged();

private:
    void updateThisLinks();

    CDuration    m_duration;
    QList<CNote> m_notes;
    quint8       m_index;
    qint16       m_direction;
    bool         m_empty;
    CBeat       *p_beat;
};

#endif // CVOICE_H
