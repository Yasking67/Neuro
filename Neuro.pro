QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Header.h


#INCLUDEPATH += C:/opencv/build/build_debug/install/include
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_core451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_highgui451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_imgproc451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_features2d451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_calib3d451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_video451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_videoio451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_imgcodecs451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_dnn451d
#LIBS += -L"C:/opencv/build/build_debug/install/x64/vc16/lib" -lopencv_tracking451d

INCLUDEPATH += C:/opencv/build/build_release/install/include
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_core451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_highgui451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_imgproc451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_features2d451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_calib3d451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_video451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_videoio451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_imgcodecs451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_dnn451
LIBS += -L"C:/opencv/build/build_release/install/x64/vc16/lib" -lopencv_tracking451
