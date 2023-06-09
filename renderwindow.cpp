#include "renderwindow.h"
#include <QTimer>
#include <QMatrix4x4>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLDebugLogger>
#include <QKeyEvent>
#include <QStatusBar>
#include <QDebug>

#include <string>

#include "shader.h"
#include "mainwindow.h"
#include "logger.h"
#include "xyz.h"
#include "trianglesurface.h"
#include "tetrahedron.h"
#include "curve.h"
#include "house.h"
#include "trophy.h"
#include "boxinhouse.h"
#include "scenehouse.h"

House* house = new House(1, QVector3D(1.0f, 2.0f, 1.0f));
SceneHouse* scenehouse = new SceneHouse(1, QVector3D(1.0f, 2.0f, 1.0f));

RenderWindow::RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow)
    : mContext(nullptr), mInitialized(false), mMainWindow(mainWindow)

{
    //This is sent to QWindow:
    setSurfaceType(QWindow::OpenGLSurface);
    setFormat(format);
    //Make the OpenGL context
    mContext = new QOpenGLContext(this);
    //Give the context the wanted OpenGL format (v4.1 Core)
    mContext->setFormat(requestedFormat());
    if (!mContext->create()) {
        delete mContext;
        mContext = nullptr;
        qDebug() << "Context could not be made - quitting this application";
    }

    mPmatrix = new QMatrix4x4{};         // Leksjon 3
    mVmatrix = new QMatrix4x4{};         // Leksjon 3




    //Make the gameloop timer:
    mRenderTimer = new QTimer(this);

    if(bSceneTwo == false){
    //mObjects.push_back(new XYZ());
   // mObjects.push_back(new TriangleSurface());
    tet = new tetrahedron;
   mObjects.push_back(tet);
   // mObjects.push_back(new TriangleSurface("../3dprog22/test.txt",true));
   // mObjects.push_back(new Curve());
 //mObjects.push_back(new Curve("../3dprog22/kurve.txt"));
    mObjects.push_back(house);
    mObjects.push_back(new Trophy(0.5, QVector3D(3.0f,0.0f,-5.0f)));
    mObjects.push_back(new Trophy(0.5, QVector3D(1.0f,0.0f,-2.0f)));
    mObjects.push_back(new Trophy(0.5, QVector3D(2.0f,0.0f,-1.0f)));
    mObjects.push_back(new Trophy(0.5, QVector3D(-1.0f,0.0f,1.0f)));
    mObjects.push_back(new Trophy(0.5, QVector3D(-5.0f,0.0f,2.0f)));
    mObjects.push_back(new Trophy(0.5, QVector3D(-2.0f,0.0f,3.0f)));

}else{
    mObjects.push_back(new BoxInHouse(0.5,QVector3D(3.0f,0.0f,5.0f)));
    mObjects.push_back(scenehouse);
    }
}

RenderWindow::~RenderWindow()
{
    //cleans up the GPU memory
    glDeleteVertexArrays( 1, &mVAO );
    glDeleteBuffers( 1, &mVBO );
}

// Sets up the general OpenGL stuff and the buffers needed to render a triangle
void RenderWindow::init()
{
    //Get the instance of the utility Output logger
    //Have to do this, else program will crash (or you have to put in nullptr tests...)
    mLogger = Logger::getInstance();

    //Connect the gameloop timer to the render function:
    //This makes our render loop
    connect(mRenderTimer, SIGNAL(timeout()), this, SLOT(render()));
    //********************** General OpenGL stuff **********************

    //The OpenGL context has to be set.
    //The context belongs to the instanse of this class!
    if (!mContext->makeCurrent(this)) {
        mLogger->logText("makeCurrent() failed", LogType::REALERROR);
        return;
    }

    //just to make sure we don't init several times
    //used in exposeEvent()
    if (!mInitialized)
        mInitialized = true;

    //must call this to use OpenGL functions
    initializeOpenGLFunctions();

    //Print render version info (what GPU is used):
    //Nice to see if you use the Intel GPU or the dedicated GPU on your laptop
    // - can be deleted
    mLogger->logText("The active GPU and API:", LogType::HIGHLIGHT);
    std::string tempString;
    tempString += std::string("  Vendor: ") + std::string((char*)glGetString(GL_VENDOR)) + "\n" +
            std::string("  Renderer: ") + std::string((char*)glGetString(GL_RENDERER)) + "\n" +
            std::string("  Version: ") + std::string((char*)glGetString(GL_VERSION));
    mLogger->logText(tempString);

    //Start the Qt OpenGL debugger
    //Really helpfull when doing OpenGL
    //Supported on most Windows machines - at least with NVidia GPUs
    //reverts to plain glGetError() on Mac and other unsupported PCs
    // - can be deleted
    startOpenGLDebugger();

    //general OpenGL stuff:
    glEnable(GL_DEPTH_TEST);            //enables depth sorting - must then use GL_DEPTH_BUFFER_BIT in glClear
    //    glEnable(GL_CULL_FACE);       //draws only front side of models - usually what you want - test it out!
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);    //gray color used in glClear GL_COLOR_BUFFER_BIT

    //Compile shaders:
    //NB: hardcoded path to files! You have to change this if you change directories for the project.
    //Qt makes a build-folder besides the project folder. That is why we go down one directory
    // (out of the build-folder) and then up into the project folder.
    mShaderProgram[0] = new Shader("../3DProg22/plainshader.vert", "../3DProg22/plainshader.frag");
    mShaderProgram[1] = new Shader("../3DProg22/textureshader.vert", "../3DProg22/textureshader.frag");


    // It's vital to setup the shaders here, otherwise the program won't run
    // These functions are some of the vital connection points we have from our c++ code to our shaders
    // If these functions are not run, the code won't talk with the shaders, and nothing will be rendered
    setupPlainShader(0);
    setupTextureShader(1);


    mTextures[0]= new Texture();
    mTextures[1] = new Texture("../3DProg22/hund.bmp");

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,mTextures[0]->id());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,mTextures[1]->id());



    // Whenever we wish to change the current shader, we also need to update which uniforms we use
    // Since this is our first time loading the shaders, we will use the plain shader



    for (auto it=mObjects.begin(); it != mObjects.end(); it++)
    {
        (*it)->init(mMatrixUniform);
    }
    glBindVertexArray(0);       //unbinds any VertexArray - good practice
}

// Called each frame - doing the rendering!!!
void RenderWindow::render()
{
    mTimeStart.restart(); //restart FPS clock
    mContext->makeCurrent(this); //must be called every frame (every time mContext->swapBuffers is called)

    initializeOpenGLFunctions();    //must call this every frame it seems...

    //clear the screen for each redraw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //what shader to use
    glUseProgram(mShaderProgram[0]->getProgram() );

    //send data to shader
    glUniformMatrix4fv( vMatrixUniform0, 1, GL_TRUE, mCamera->mVmatrix.constData());
    glUniformMatrix4fv( pMatrixUniform0, 1, GL_TRUE, mCamera->mPmatrix.constData());
    glUniformMatrix4fv( mMatrixUniform0, 1, GL_TRUE, mObjects[0]->mMatrix.constData());
    //draw the object
    mObjects[0]->draw();

    // Leksjon 3
    mPmatrix->setToIdentity();
    mVmatrix->setToIdentity();
    mPmatrix->perspective(120, 4.0/3.0, 0.1, 10.0);
    mVmatrix->translate(0, 0, -5); // Flytter kamera
    // Må sende matrisedata til vertexshader


    mCamera->init(pMatrixUniform, vMatrixUniform);
    mCamera->perspective(60, 4.0/3.0, 0.1, 1000.0);
     mVmatrix->translate(0, 0, -10); // Flytter kamera
    mCamera->lookAt(QVector3D{-7,5,-6}, QVector3D{0,0,0}, QVector3D{0,1,0});

    // Må sende matrisedata til vertexshader
//     glUniformMatrix4fv( mPmatrixUniform, 1, GL_FALSE, mPmatrix->constData());
//     glUniformMatrix4fv( mVmatrixUniform, 1, GL_FALSE, mVmatrix->constData());
    mCamera->update();

   // glUniformMatrix4fv( mPmatrixUniform, 1, GL_FALSE, mPmatrix->constData());
   // glUniformMatrix4fv( mVmatrixUniform, 1, GL_FALSE, mVmatrix->constData());

    for (auto it=mObjects.begin(); it != mObjects.end(); it++)
    {
        (*it)->draw();
    }
    calculateFramerate();
    checkForGLerrors(); //using our expanded OpenGL debugger to check if everything is OK.
    mContext->swapBuffers(this);



}

void RenderWindow::setupPlainShader(int shaderIndex)
{
    mMatrixUniform0 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "mMatrix" );
    vMatrixUniform0 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "vMatrix" );
    pMatrixUniform0 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "pMatrix" );
}

void RenderWindow::setupTextureShader(int shaderIndex)
{
    mMatrixUniform1 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "mMatrix" );
    vMatrixUniform1 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "vMatrix" );
    pMatrixUniform1 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "pMatrix" );
    mTextureUniform1 = glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(), "textureSampler");
}

void RenderWindow::setupPhongShader(int shaderIndex)
{
    mMatrixUniform2 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "mMatrix" );
    vMatrixUniform2 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "vMatrix" );
    pMatrixUniform2 = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "pMatrix" );

    mLightColorUniform = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "lightColor" );
    mObjectColorUniform = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "objectColor" );
    mAmbientLightStrengthUniform = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "ambientStrengt" );
    mLightPositionUniform = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "lightPosition" );
    mSpecularStrengthUniform = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "specularStrength" );
    mSpecularExponentUniform = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "specularExponent" );
    mLightPowerUniform = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "lightPower" );
    mCameraPositionUniform = glGetUniformLocation( mShaderProgram[shaderIndex]->getProgram(), "cameraPosition" );
    mTextureUniform2 = glGetUniformLocation(mShaderProgram[shaderIndex]->getProgram(), "textureSampler");
}


//This function is called from Qt when window is exposed (shown)
// and when it is resized
//exposeEvent is a overridden function from QWindow that we inherit from
void RenderWindow::exposeEvent(QExposeEvent *)
{
    //if not already initialized - run init() function - happens on program start up
    if (!mInitialized)
        init();

    //This is just to support modern screens with "double" pixels (Macs and some 4k Windows laptops)
    const qreal retinaScale = devicePixelRatio();

    //Set viewport width and height to the size of the QWindow we have set up for OpenGL
    glViewport(0, 0, static_cast<GLint>(width() * retinaScale), static_cast<GLint>(height() * retinaScale));

    //If the window actually is exposed to the screen we start the main loop
    //isExposed() is a function in QWindow
    if (isExposed())
    {
        //This timer runs the actual MainLoop
        //16 means 16ms = 60 Frames pr second (should be 16.6666666 to be exact...)
        mRenderTimer->start(16);
        mTimeStart.start();
    }
}

//The way this function is set up is that we start the clock before doing the draw call,
// and check the time right after it is finished (done in the render function)
//This will approximate what framerate we COULD have.
//The actual frame rate on your monitor is limited by the vsync and is probably 60Hz
void RenderWindow::calculateFramerate()
{
    long nsecElapsed = mTimeStart.nsecsElapsed();
    static int frameCount{0};                       //counting actual frames for a quick "timer" for the statusbar

    if (mMainWindow)            //if no mainWindow, something is really wrong...
    {
        ++frameCount;
        if (frameCount > 30)    //once pr 30 frames = update the message == twice pr second (on a 60Hz monitor)
        {
            //showing some statistics in status bar
            mMainWindow->statusBar()->showMessage(" Time pr FrameDraw: " +
                                                  QString::number(nsecElapsed/1000000.f, 'g', 4) + " ms  |  " +
                                                  "FPS (approximated): " + QString::number(1E9 / nsecElapsed, 'g', 7));
            frameCount = 0;     //reset to show a new message in 30 frames
        }
    }
}

//Uses QOpenGLDebugLogger if this is present
//Reverts to glGetError() if not
void RenderWindow::checkForGLerrors()
{
    if(mOpenGLDebugLogger)  //if our machine got this class to work
    {
        const QList<QOpenGLDebugMessage> messages = mOpenGLDebugLogger->loggedMessages();
        for (const QOpenGLDebugMessage &message : messages)
        {
            if (!(message.type() == message.OtherType)) // get rid of uninteresting "object ...
                                                        // will use VIDEO memory as the source for
                                                        // buffer object operations"
                // valid error message:
                mLogger->logText(message.message().toStdString(), LogType::REALERROR);
        }
    }
    else
    {
        GLenum err = GL_NO_ERROR;
        while((err = glGetError()) != GL_NO_ERROR)
        {
            mLogger->logText("glGetError returns " + std::to_string(err), LogType::REALERROR);
            switch (err) {
            case 1280:
                mLogger->logText("GL_INVALID_ENUM - Given when an enumeration parameter is not a "
                                "legal enumeration for that function.");
                break;
            case 1281:
                mLogger->logText("GL_INVALID_VALUE - Given when a value parameter is not a legal "
                                "value for that function.");
                break;
            case 1282:
                mLogger->logText("GL_INVALID_OPERATION - Given when the set of state for a command "
                                "is not legal for the parameters given to that command. "
                                "It is also given for commands where combinations of parameters "
                                "define what the legal parameters are.");
                break;
            }
        }
    }
}

//Tries to start the extended OpenGL debugger that comes with Qt
//Usually works on Windows machines, but not on Mac...
void RenderWindow::startOpenGLDebugger()
{
    QOpenGLContext * temp = this->context();
    if (temp)
    {
        QSurfaceFormat format = temp->format();
        if (! format.testOption(QSurfaceFormat::DebugContext))
            mLogger->logText("This system can not use QOpenGLDebugLogger, so we revert to glGetError()",
                             LogType::HIGHLIGHT);

        if(temp->hasExtension(QByteArrayLiteral("GL_KHR_debug")))
        {
            mLogger->logText("This system can log extended OpenGL errors", LogType::HIGHLIGHT);
            mOpenGLDebugLogger = new QOpenGLDebugLogger(this);
            if (mOpenGLDebugLogger->initialize()) // initializes in the current context
                mLogger->logText("Started Qt OpenGL debug logger");
        }
    }
}

//Event sent from Qt when program receives a keyPress
// NB - see renderwindow.h for signatures on keyRelease and mouse input
void RenderWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        mMainWindow->close();       //Shuts down the whole program
    }


    //You get the keyboard input like this
    if(event->key() == Qt::Key_W)
    {
        tet->move(0.0f,0.1f,0.0f);
        qDebug() << "keypressW";
    }
   if(event->key() == Qt::Key_S)
   {
       tet->move(0.0f,-0.1f,0.0f);
       qDebug() << "keypressS";
    }
   if(event->key() == Qt::Key_A)
   {
       tet->move(0.1f,0.0f,0.0f);
       qDebug() << "keypressA";
    }
   if(event->key() == Qt::Key_D)
   {
       tet->move(-0.1f,0.0f,0.0f);
       qDebug() << "keypressD";
    }
}
