#ifndef CTABULATURE_H
#define CTABULATURE_H

#include "src/common/common.h"

#include <QObject>

class CTabulature
    : public QObject
{
    Q_OBJECT
public:
    explicit CTabulature(QObject *parent = 0);
};

#endif // CTABULATURE_H
