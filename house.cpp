#include "house.h"
#include <iostream>

House::House(){

}


House::House(float scale, QVector3D start)
{
    m_Position = start;

    Vertex v1{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v2{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v3{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[1], HouseColour[1], HouseColour[2]};

    Vertex v4{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v5{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v6{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[1], HouseColour[1], HouseColour[2]};

    // FRONT UPPER
    Vertex v7{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v8{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v9{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v10{m_Position[0] + StartPos[0] - scale, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v11{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1] + scale*2, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v12{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    // FRONT RIGHT
    Vertex v13{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v14{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[1], HouseColour[1], HouseColour[2]};
    Vertex v15{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v16{m_Position[0] + StartPos[0] - scale*2, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v17{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[1], HouseColour[1], HouseColour[2]};
    Vertex v18{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    // WEST
    Vertex v19{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v20{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v21{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v22{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v23{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v24{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    // BACK
    Vertex v25{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v26{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v27{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v28{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v29{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v30{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};

    // EAST
    Vertex v31{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v32{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v33{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};

    Vertex v34{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v35{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[1], HouseColour[2]};
    Vertex v36{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1] + scale*3, m_Position[2] + StartPos[2], HouseColour[0], HouseColour[1], HouseColour[2]};

    // FLOOR
    Vertex v61{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[0], HouseColour[2]};
    Vertex v62{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[0], HouseColour[2]};
    Vertex v63{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[0], HouseColour[2]};

    Vertex v64{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2], HouseColour[0], HouseColour[0], HouseColour[2]};
    Vertex v65{m_Position[0] + StartPos[0], m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[0], HouseColour[2]};
    Vertex v66{m_Position[0] + StartPos[0] - scale*4, m_Position[1] + StartPos[1], m_Position[2] + StartPos[2] + scale*3, HouseColour[0], HouseColour[0], HouseColour[2]};


    HousePoints.push_back(v1);
    HousePoints.push_back(v2);
    HousePoints.push_back(v3);
    HousePoints.push_back(v4);
    HousePoints.push_back(v5);
    HousePoints.push_back(v6);

    HousePoints.push_back(v7);
    HousePoints.push_back(v8);
    HousePoints.push_back(v9);
    HousePoints.push_back(v10);
    HousePoints.push_back(v11);
    HousePoints.push_back(v12);

    HousePoints.push_back(v13);
    HousePoints.push_back(v14);
    HousePoints.push_back(v15);
    HousePoints.push_back(v16);
    HousePoints.push_back(v17);
    HousePoints.push_back(v18);

    HousePoints.push_back(v19);
    HousePoints.push_back(v20);
    HousePoints.push_back(v21);
    HousePoints.push_back(v22);
    HousePoints.push_back(v23);
    HousePoints.push_back(v24);

    HousePoints.push_back(v25);
    HousePoints.push_back(v26);
    HousePoints.push_back(v27);
    HousePoints.push_back(v28);
    HousePoints.push_back(v29);
    HousePoints.push_back(v30);

    HousePoints.push_back(v31);
    HousePoints.push_back(v32);
    HousePoints.push_back(v33);
    HousePoints.push_back(v34);
    HousePoints.push_back(v35);
    HousePoints.push_back(v36);

    HousePoints.push_back(v61);
    HousePoints.push_back(v62);
    HousePoints.push_back(v63);
    HousePoints.push_back(v64);
    HousePoints.push_back(v65);
    HousePoints.push_back(v66);

    for (int i = 0; i < HousePoints.size(); i++)
    {
        mVertices.push_back(HousePoints[i]);
    }

    mMatrix.setToIdentity();
}

House::~House() {    }

void House::init(GLint matrixUniform) {
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


void House::draw()
{
   glBindVertexArray( mVAO );
   glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
   glDrawArrays(GL_TRIANGLES, 0, mVertices.size());

}





