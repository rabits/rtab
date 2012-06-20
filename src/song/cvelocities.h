#ifndef CVELOCITIES_H
#define CVELOCITIES_H

#include "src/common/common.h"

#include <QObject>

class CVelocities
{
public:
    // ---API--- //
    static const int MIN_VELOCITY = 15;
    static const int VELOCITY_INCREMENT = 16;
    static const int PIANO_PIANISSIMO = (MIN_VELOCITY);
    static const int PIANISSIMO = (MIN_VELOCITY + VELOCITY_INCREMENT);
    static const int PIANO = (MIN_VELOCITY + (VELOCITY_INCREMENT * 2));
    static const int MEZZO_PIANO = (MIN_VELOCITY + (VELOCITY_INCREMENT * 3));
    static const int MEZZO_FORTE = (MIN_VELOCITY + (VELOCITY_INCREMENT * 4));
    static const int FORTE = (MIN_VELOCITY + (VELOCITY_INCREMENT * 5));
    static const int FORTISSIMO = (MIN_VELOCITY + (VELOCITY_INCREMENT * 6));
    static const int FORTE_FORTISSIMO = (MIN_VELOCITY + (VELOCITY_INCREMENT * 7));
    static const int DEFAULT = FORTE;

private:
    CVelocities();
};

#endif // CVELOCITIES_H
