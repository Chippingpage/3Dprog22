#include "curve.h"

Curve::Curve()
{
    mVertices.push_back(Vertex{-2, 6, 0, 0, 0, 0});
    mVertices.push_back(Vertex{-1, 3, 0, 0, 0, 0});
    mVertices.push_back(Vertex{0, 2, 0, 0, 0, 0});
    mVertices.push_back(Vertex{1, 3, 0, 0, 0, 0});
    mVertices.push_back(Vertex{2, 6, 0, 0, 0, 0});
    mVertices.push_back(Vertex{3, 8, 0, 0, 0, 0});
}

Curve::Curve(std::string filnavn)
{
    readFile(filnavn);
    mMatrix.setToIdentity();

}

void Curve::readFile(std::string filnavn)
{
    std::ifstream input;
    input.open(filnavn.c_str());

    if (input.is_open())
    {
        int n;
        Vertex vertex;
        input >> n;
        mVertices.reserve(n);
        for (int i = 0; i < n; i++)
        {
             input >> vertex;
             mVertices.push_back(vertex);
        }
        input.close();
    }
}

void Curve::init(GLint matrixUniform){
    mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_STATIC_DRAW );

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof( Vertex ),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    //CalculateCurve();
}

void Curve::CalculateCurve(){

    Eigen::MatrixXd y(5,1);
      y(0,0) = 3;
      y(1,0) = 2;
      y(2,0) = 1;
      y(3,0) = -2;
      y(4,0) = -1;





    Eigen::MatrixXd A(5,3);
              //x^2         x^1         x^0
    A(0,0) = -3; A(0,1) = 3; A(0,2)= 1;
    A(1,0) = -1; A(1,1) = 1; A(1,2)= 1;
    A(2,0) = 1; A(2,1) = -2; A(2,2)= 1;
    A(3,0) = -1; A(3,1) = 1; A(3,2)= 1;
    A(4,0) = -3; A(4,1) = 3; A(4,2)= 1;




    Eigen::MatrixXd B = A.transpose()*A;
    Eigen::MatrixXd c = A.transpose()*y;
    Eigen::MatrixXd x = B.inverse()*c;

    std::cout << "Min matrise er " <<std::endl;
    std::cout << x << std::endl;
}

void Curve::draw(){

    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_LINE_STRIP, 0, mVertices.size());

}
