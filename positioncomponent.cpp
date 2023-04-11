#include "positioncomponent.h"

positioncomponent::positioncomponent()
{
    mMatrix.setToIdentity();
}


void positioncomponent::setPosition(QVector3D offset)
{
    m_Position = offset;
    getTranslateMatrix(&mMatrix);
    mMatrix.lookAt(m_Position, m_Position + worldFront, worldUp);
}
