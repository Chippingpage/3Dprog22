#ifndef QUAD_H
#define QUAD_H

#include <QOpenGLFunctions_4_1_Core>
#include <vector>
#include <matrix4x4.h>
#include "visualobject.h"

class Quad : public VisualObject
{
public:
    Quad(bool smooth);
    ~Quad() override;

    void init() override;
    void draw() override;
};

#endif // QUAD_H
