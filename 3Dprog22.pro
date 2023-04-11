QT          += core gui widgets opengl

TEMPLATE    = app
CONFIG      += c++17

TARGET      = 3D-programmering

SOURCES += main.cpp \
    boxinhouse.cpp \
    camera.cpp \
    curve.cpp \
    house.cpp \
    light.cpp \
    logger.cpp \
    mainwindow.cpp \
    positioncomponent.cpp \
    renderwindow.cpp \
    scenehouse.cpp \
    shader.cpp \
    tetrahedron.cpp \
    texture.cpp \
    trianglesurface.cpp \
    trophy.cpp \
    vertex.cpp \
    visualobject.cpp \
    xyz.cpp

HEADERS += \
    boxinhouse.h \
    camera.h \
    curve.h \
    house.h \
    light.h \
    logger.h \
    mainwindow.h \
    positioncomponent.h \
    renderwindow.h \
    scenehouse.h \
    shader.h \
    stb_image.h \
    tetrahedron.h \
    texture.h \
    trianglesurface.h \
    trophy.h \
    vertex.h \
    visualobject.h \
    xyz.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    plainshader.frag \
    plainshader.vert \
    test.txt
