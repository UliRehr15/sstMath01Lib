TEMPLATE	  = app
CONFIG	 	 += warn_on
CONFIG       -= qt
CONFIG       -= windows

# CONFIG       -= debug  # RELEASE ist aktiv
CONFIG       -= release  # DEBUG ist aktiv

INCLUDEPATH += ../Header

debug{
  LIBS        += ../../libs/libsstMath01Lib_d.a
}
release{
  
  win32-g++:QMAKE_LFLAGS += -static
  win32-g++:QMAKE_LFLAGS -= -mthreads
  win32-g++:QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
  win32-g++:QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads
  
  LIBS        += ../../libs/libsstMath01Lib_r.a
}

HEADERS    += sstMath01LibTest.h

SOURCES    += sstMath01LibTest.cpp

TARGET	  	= sstMath01LibTest

# copy to deployment directory
# DESTDIR     = ../../../../local_deploy
