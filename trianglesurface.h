#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "visualobject.h"

class TriangleSurface : public VisualObject
{
public:
   TriangleSurface();
   ~TriangleSurface() override;
     TriangleSurface(std::string filnavn, bool write);
   void init(GLint matrixUniform) override;
   void draw() override;
   void readFile(std::string filnavm);
   void writeFile(std::string filnavn);

};

#endif // TRIANGLESURFACE_H
