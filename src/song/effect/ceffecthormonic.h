#ifndef CEFFECTHORMONIC_H
#define CEFFECTHORMONIC_H

#include <QObject>

class CEffectHormonic
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TYPE type READ type WRITE type NOTIFY typeChanged)
    Q_PROPERTY(int data READ data WRITE data NOTIFY dataChanged)

public:
    explicit CEffectHormonic(QObject *parent = 0);
    CEffectHormonic(const CEffectHormonic &obj);
    CEffectHormonic& operator=(const CEffectHormonic &obj);

    static const char* KEY_NATURAL;
    static const char* KEY_ARTIFICIAL;
    static const char* KEY_TAPPED;
    static const char* KEY_PINCH;
    static const char* KEY_SEMI;

    enum TYPE {
        TYPE_NONE       = 0,
        TYPE_NATURAL    = 1,
        TYPE_ARTIFICIAL = 2,
        TYPE_TAPPED     = 3,
        TYPE_PINCH      = 4,
        TYPE_SEMI       = 5
    };

    static const int MIN_ARTIFICIAL_OFFSET = -24;
    static const int MAX_ARTIFICIAL_OFFSET =  24;
    static const int MAX_TAPPED_OFFSET     =  24;

    /*static const int NATURAL_FREQUENCIES[][] = {
        {12, 12}, //AH12 (+12 frets)
        {9 , 28}, //AH9 (+28 frets)
        {5 , 24}, //AH5 (+24 frets)
        {7 , 19}, //AH7 (+19 frets)
        {4 , 28}, //AH4 (+28 frets)
        {3 , 31}  //AH3 (+31 frets)
    };*/

    // ---API--- //
    inline TYPE type()       const { return m_type; }
    inline int  data()       const { return m_data; }

    inline void type(const TYPE val) { m_type = val; emit typeChanged(); }
    inline void data(const int val)  { m_data = val; emit dataChanged(); }

    inline bool isNatural()   const { return m_type == TYPE_NATURAL; }
    inline bool isArtifical() const { return m_type == TYPE_ARTIFICIAL; }
    inline bool isTapped()    const { return m_type == TYPE_TAPPED; }
    inline bool isPinch()     const { return m_type == TYPE_PINCH; }
    inline bool isSemi()      const { return m_type == TYPE_SEMI; }

signals:
    void typeChanged();
    void dataChanged();

private:
    TYPE m_type;
    int  m_data;
};

#endif // CEFFECTHORMONIC_H
