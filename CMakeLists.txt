cmake_minimum_required(VERSION 3.4)
project(RopeFun)

FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(QT5GUI)

#FIND_PACKAGE(Qt5Multimedia)
FIND_PACKAGE( OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer osgText )

#file(COPY "sound.mp3" DESTINATION "${CMAKE_BINARY_DIR}")

INCLUDE_DIRECTORIES( ${OPENSCENEGRAPH_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)


SET(MYSOURCE
	main.cpp
        ropenode.h
        ropenode.cpp
        rope.h
        rope.cpp
        vector3.h
        vector3.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
        osgwidget.h
        osgwidget.cpp
        wavenode.h
        wavenode.cpp
        fixednode.h
        fixednode.cpp
        inertialnode.h
        inertialnode.cpp
        ropecreate.h
        ropecreate.cpp
        ropecreate.ui
        helperfunctions.h
        helperfunctions.cpp
    )
add_executable(${PROJECT_NAME}
    ${MYSOURCE}
    )


target_link_libraries(${PROJECT_NAME}
    ${OPENSCENEGRAPH_LIBRARIES}
    Qt5::Widgets
    Qt5::Gui
    #Qt5::Multimedia
)
