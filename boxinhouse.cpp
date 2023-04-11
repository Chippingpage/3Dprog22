#include "boxinhouse.h"

BoxInHouse::BoxInHouse(){

}

BoxInHouse::BoxInHouse(float scale, QVector3D start)
{


    // NORTH SIDE
    Vertex v1{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 0, 0, 0}; // Lower right
    Vertex v2{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 0, 0, 0}; // Upper left
    Vertex v3{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 0, 0, 0}; // Lower left

    Vertex v4{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 0, 0, 0}; // Upper Right
    Vertex v5{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 0, 0, 0}; // Lower right
    Vertex v6{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 0, 0, 0}; // Upper left

    // EAST SIDE
    Vertex v7{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 1, 0, 0}; // Lower left
    Vertex v8{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 0}; // Upper left
    Vertex v9{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 0, 0}; // Lower right

    Vertex v10{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 0, 0}; // Upper right
    Vertex v11{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 1, 0, 0}; // Lower right
    Vertex v12{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 0}; // Upper left

    // SOUTH SIDE
    Vertex v13{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower right
    Vertex v14{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper left
    Vertex v15{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower left

    Vertex v16{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper Right
    Vertex v17{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 0}; // Lower right
    Vertex v18{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 1, 0}; // Upper left

    // WEST SIDE
    Vertex v19{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 0, 0, 1}; // Lower left
    Vertex v20{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 0, 0, 1}; // Upper left
    Vertex v21{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 0, 1}; // Lower right

    Vertex v22{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 0, 0, 1}; // Upper right
    Vertex v23{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 0, 1}; // Lower right
    Vertex v24{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 0, 0, 1}; // Upper left

    // TOP SIDE
    Vertex v25{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 1}; // Upper north
    Vertex v26{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] - scale, 1, 1, 1}; // Upper east
    Vertex v27{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 0, 1}; // Upper south

    Vertex v28{m_Position[0] + scale, m_Position[1] + scale, m_Position[2] + scale, 1, 0, 1}; // Upper south
    Vertex v29{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] + scale, 1, 1, 1}; // Upper west
    Vertex v30{m_Position[0] - scale, m_Position[1] + scale, m_Position[2] - scale, 1, 0, 1}; // Upper north

    // BOTTOM SIDE
    Vertex v31{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 0, 1, 1}; // Lower north
    Vertex v32{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] - scale, 0, 1, 1}; // Lower east
    Vertex v33{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 1}; // Lower south

    Vertex v34{m_Position[0] + scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 1}; // Lower south
    Vertex v35{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] + scale, 0, 1, 1}; // Lower west
    Vertex v36{m_Position[0] - scale, m_Position[1] - scale, m_Position[2] - scale, 0, 1, 1}; // Lower north

    BoxInHousePoints.push_back(v1);
    BoxInHousePoints.push_back(v2);
    BoxInHousePoints.push_back(v3);
    BoxInHousePoints.push_back(v4);
    BoxInHousePoints.push_back(v5);
    BoxInHousePoints.push_back(v6);

    BoxInHousePoints.push_back(v7);
    BoxInHousePoints.push_back(v8);
    BoxInHousePoints.push_back(v9);
    BoxInHousePoints.push_back(v10);
    BoxInHousePoints.push_back(v11);
    BoxInHousePoints.push_back(v12);

    BoxInHousePoints.push_back(v13);
    BoxInHousePoints.push_back(v14);
    BoxInHousePoints.push_back(v15);
    BoxInHousePoints.push_back(v16);
    BoxInHousePoints.push_back(v17);
    BoxInHousePoints.push_back(v18);

    BoxInHousePoints.push_back(v19);
    BoxInHousePoints.push_back(v20);
    BoxInHousePoints.push_back(v21);
    BoxInHousePoints.push_back(v22);
    BoxInHousePoints.push_back(v23);
    BoxInHousePoints.push_back(v24);

    BoxInHousePoints.push_back(v25);
    BoxInHousePoints.push_back(v26);
    BoxInHousePoints.push_back(v27);
    BoxInHousePoints.push_back(v28);
    BoxInHousePoints.push_back(v29);
    BoxInHousePoints.push_back(v30);

    BoxInHousePoints.push_back(v31);
    BoxInHousePoints.push_back(v32);
    BoxInHousePoints.push_back(v33);
    BoxInHousePoints.push_back(v34);
    BoxInHousePoints.push_back(v35);
    BoxInHousePoints.push_back(v36);

    for (int i = 0; i < BoxInHousePoints.size(); i++)
    {
        mVertices.push_back(BoxInHousePoints[i]);
    }

    mMatrix.setToIdentity();
}

    BoxInHouse::~BoxInHouse() {    }

    void BoxInHouse::init(GLint matrixUniform) {
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


    void BoxInHouse::draw()
    {
       glBindVertexArray( mVAO );
       glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
       glDrawArrays(GL_TRIANGLES, 0, mVertices.size());

    }
