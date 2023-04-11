// 3D-programmering 2022
#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <iostream>
#include <vector>
#include "vertex.h"

#include "positioncomponent.h"

class VisualObject : public QOpenGLFunctions_4_1_Core, public positioncomponent{
public:
   VisualObject();
   ~VisualObject();
   virtual void init(GLint matrixUniform)=0;
  // virtual void init();
   virtual void draw()=0;
   virtual void move(float x, float y, float z) {  };
   virtual void checkCollision(VisualObject* other){
       float dist = this->m_Position.distanceToPoint(/*this->m_Position,*/ other->m_Position);
       if (dist < this->Radius + other->Radius) {
           //std::cout << "collision" << std::endl;
       }
   }
   int renderValue = 0;

   float Radius = 0.5f;
   QMatrix4x4 mMatrix;
protected:
   std::vector<Vertex> mVertices;
   GLuint mVAO{0};
   GLuint mVBO{0};
   GLint mMatrixUniform{0};



};
#endif // VISUALOBJECT_H
