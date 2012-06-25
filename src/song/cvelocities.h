#ifndef CVELOCITIES_H
#define CVELOCITIES_H

#include "src/common/common.h"

#include <QObject>

class CVelocities
{
public:
    // ---API--- //
    static const qint16 MIN_VELOCITY = 15;
    static const qint16 VELOCITY_INCREMENT = 16;
    static const qint16 PIANO_PIANISSIMO = (MIN_VELOCITY);
    static const qint16 PIANISSIMO = (MIN_VELOCITY + VELOCITY_INCREMENT);
    static const qint16 PIANO = (MIN_VELOCITY + (VELOCITY_INCREMENT * 2));
    static const qint16 MEZZO_PIANO = (MIN_VELOCITY + (VELOCITY_INCREMENT * 3));
    static const qint16 MEZZO_FORTE = (MIN_VELOCITY + (VELOCITY_INCREMENT * 4));
    static const qint16 FORTE = (MIN_VELOCITY + (VELOCITY_INCREMENT * 5));
    static const qint16 FORTISSIMO = (MIN_VELOCITY + (VELOCITY_INCREMENT * 6));
    static const qint16 FORTE_FORTISSIMO = (MIN_VELOCITY + (VELOCITY_INCREMENT * 7));
    static const qint16 DEFAULT = FORTE;

private:
    CVelocities();
};

#endif // CVELOCITIES_H
