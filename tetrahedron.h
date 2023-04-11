#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include <QKeyEvent>
#include "vertex.h"
#include "visualobject.h"

class tetrahedron : public VisualObject
{
public:
    tetrahedron();
    ~tetrahedron() override;
    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z);

    void rotate(bool rotating);


private:
   float mx, my, mz;
};

#endif // TETRAHEDRON_H


