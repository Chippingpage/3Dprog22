#ifndef SCENEHOUSE_H
#define SCENEHOUSE_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"


class SceneHouse : public VisualObject
{
public:
    SceneHouse();
    SceneHouse(float scale, QVector3D start);
    ~SceneHouse() override;
    void init(GLint matrixUniform) override;
    void draw() override;

   std::vector<Vertex> SceneHousePoints;
     float StartPos[3] = {0.0f, 0.0f, 0.0f};
     float HouseColour[3] = {1.0f, 0.0f, 0.0f};


};

#endif // HOUSE_H
