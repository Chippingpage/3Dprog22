#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H
#include "qmatrix4x4.h"
#include <QVector3D>

class positioncomponent
{
public:
       QVector3D m_Position;
       const QVector3D worldRight = QVector3D(1.0f, 0.0f, 0.0f);
       const QVector3D worldUp = QVector3D(0.0f, 1.0f, 0.0f);
       const QVector3D worldFront = QVector3D(0.0f, 0.0f, 1.0f);

       QMatrix4x4 mMatrix;
       positioncomponent();


       void setPosition(QVector3D offset);
       void getTranslateMatrix(QMatrix4x4 *matrise) {

          matrise->lookAt(m_Position, m_Position + worldFront, worldUp);
       }

};

#endif // POSITIONCOMPONENT_H
