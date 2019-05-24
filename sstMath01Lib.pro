TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH += ../sst_str01_lib/Header
INCLUDEPATH += ./Header


HEADERS   += ./Header/sstMath01Lib.h  \
             sstMath01LibInt.h

SOURCES		+= sstMath01Lib.cpp \
             sstMath01Pnt1.cpp \
             sstMath01Trn1.cpp \
             sstMath01Trn2.cpp \
    sstMath01Mima2.cpp \
    sstMath01Angle.cpp

OTHER_FILES += README.md

debug{
  TARGET		= sstMath01Lib_d
}
release{
  TARGET		= sstMath01Lib_r
}

DESTDIR     = ../libs

