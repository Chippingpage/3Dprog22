#ifndef TROPHY_H
#define TROPHY_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class Trophy : public VisualObject
{
private:
    bool HasCollided = false;
public:
    Trophy();
    Trophy(float scale, QVector3D start);
    ~Trophy();
    void init(GLint matrixUniform) override;
    void draw() override;

    std::vector<Vertex> TrophyPoints;


    void checkCollision(VisualObject* other) override {

        float dist = m_Position.distanceToPoint(other->m_Position);
        if (dist < Radius + other->Radius) {
            std::cout << "collision" << std::endl;
            renderValue = 2; // Invisible
        }
        else
        {
            std::cout << "No collision" << std::endl;
            renderValue = 0; // Wireframe
        }
    }
};

#endif // TROPHY_H
