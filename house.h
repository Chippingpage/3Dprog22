#ifndef HOUSE_H
#define HOUSE_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"


class House : public VisualObject
{
public:
    House();
    House(float scale, QVector3D start);
    ~House() override;
    void init(GLint matrixUniform) override;
    void draw() override;

   std::vector<Vertex> HousePoints;
     float StartPos[3] = {0.0f, 0.0f, 0.0f};
     float HouseColour[3] = {1.0f, 0.0f, 0.0f};


};

#endif // HOUSE_H
