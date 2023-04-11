#ifndef CURVE_H
#define CURVE_H

#include "visualobject.h"
#include <eigen-3.4.0/Eigen/Core>
#include <eigen-3.4.0/Eigen/Eigen>
#include <iostream>

class Curve : public VisualObject
{
public:
    Curve();
    Curve(std::string filnavn);
    void init(GLint matrixUniform) override;
    void draw() override;
    void readFile(std::string filnavn);
    void CalculateCurve();
};

#endif // CURVE_H
