#ifndef BOXINHOUSE_H
#define BOXINHOUSE_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class BoxInHouse : public VisualObject
{
public:
    BoxInHouse();
    ~BoxInHouse();
     BoxInHouse(float scale, QVector3D start);
    void init(GLint matrixUniform) override;
    void draw() override;

    std::vector<Vertex> BoxInHousePoints;
    float m_Position[3] = {0.0f, 0.0f, 0.0f};
    float StartPos[3] = {-3.0f, 0.0f, 1.0f};
};

#endif // BOXINHOUSE_H
