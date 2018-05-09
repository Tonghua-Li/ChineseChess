include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \
        tst_test1.h \
        GreeterTests.h \
    ShiTests.h \
    MockBoard.h
SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AppLib/release/ -lAppLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AppLib/debug/ -lAppLib
else:unix: LIBS += -L$$OUT_PWD/../AppLib/ -lAppLib

INCLUDEPATH += $$PWD/../AppLib
DEPENDPATH += $$PWD/../AppLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../AppLib/release/libAppLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../AppLib/debug/libAppLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../AppLib/release/AppLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../AppLib/debug/AppLib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../AppLib/libAppLib.a
