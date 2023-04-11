#include "trianglesurface.h"
#include <iostream>

TriangleSurface::TriangleSurface()
{
    Vertex v0{0.0,0.0,0.0, 1,0,0};    mVertices.push_back(v0);
    Vertex v1(0.5,0.0,0.0, 0,1,0);    mVertices.push_back(v1);
    Vertex v2{0.5,0.5,0.0, 0,0,1};    mVertices.push_back(v2);
    Vertex v3{0.0,0.0,0.0, 0,0,1};    mVertices.push_back(v3);
    Vertex v4{0.5,0.5,0.0, 0,1,0};    mVertices.push_back(v4);
    Vertex v5{0.0,0.5,0.0, 1,0,0};    mVertices.push_back(v5);

    mMatrix.setToIdentity();
}

TriangleSurface::~TriangleSurface()
{

}

TriangleSurface::TriangleSurface(std::string filnavn, bool write)
{
    if (write)
    {
        float xmin=-2.f, xmax=2.0f, ymin=-2.0f, ymax=2.0f, h=0.25f;
                    for (auto x=xmin; x<xmax; x+=h)
                    {
                        for (auto y=ymin; y<ymax; y+=h)
                        {
                        // f(x,y) = x * sin(y)
                        float z = x*sin(y);
                        mVertices.push_back(Vertex{x,y,z,x,y,z});
                        z = (x+h)*sin(y);
                        mVertices.push_back(Vertex{x+h,y,z,x,y,z});
                        z = x*(sin(y+h));
                        mVertices.push_back(Vertex{x,y+h,z,x,y,z});
                        mVertices.push_back(Vertex{x,y+h,z,x,y,z});
                        z = (x+h)*sin(y);
                        mVertices.push_back(Vertex{x+h,y,z,x,y,z});
                        z = (x+h) * (sin(y+h));
                        mVertices.push_back(Vertex{x+h,y+h,z,x,y,z});

                        }
                    }
        writeFile(filnavn);
    }

    readFile(filnavn);

}


void TriangleSurface::readFile(std::string filnavn)
{
    std::ifstream inn;
    inn.open(filnavn.c_str());

    if (inn.is_open())
    {
        int n;
        Vertex vertex;
        inn >> n;
        mVertices.reserve(n);
        for (int i=0; i<n; i++)
        {
             inn >> vertex;
             mVertices.push_back(vertex);
        }
        inn.close();
    }
}

void TriangleSurface::writeFile(std::string filnavn)
{
    std::ofstream ut;
    ut.open(filnavn.c_str());

    if (ut.is_open())
    {
        auto n = mVertices.size();

        Vertex vertex;
        ut << n << std::endl;
        for (auto it=mVertices.begin(); it != mVertices.end(); it++)
        {
            ut << *it << std::endl;
        }

        ut.close();
    }
}


// Parameternavnet er byttet ut fra leksjonen
// Koden er ellers som for XYZ::init()
void TriangleSurface::init(GLint matrixUniform)
{
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
}

void TriangleSurface::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}
