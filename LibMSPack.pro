TARGET = mspack
TEMPLATE = lib
CONFIG += c++14
HEADERS += \
    mspack/cab.h \
    mspack/chm.h \
    mspack/crc32.h \
    mspack/des.h \
    mspack/hlp.h \
    mspack/kwaj.h \
    mspack/lit.h \
    mspack/lzss.h \
    mspack/lzx.h \
    mspack/mspack.h \
    mspack/mszip.h \
    mspack/oab.h \
    mspack/qtm.h \
    mspack/readbits.h \
    mspack/readhuff.h \
    mspack/sha.h \
    mspack/system.h \
    mspack/szdd.h

SOURCES += \
    mspack/cabc.c \
    mspack/cabd.c \
    mspack/chmc.c \
    mspack/chmd.c \
    mspack/crc32.c \
    mspack/hlpc.c \
    mspack/hlpd.c \
    mspack/kwajc.c \
    mspack/kwajd.c \
    mspack/litc.c \
    mspack/litd.c \
    mspack/lzssd.c \
    mspack/lzxc.c \
    mspack/lzxd.c \
    mspack/mszipc.c \
    mspack/mszipd.c \
    mspack/oabc.c \
    mspack/oabd.c \
    mspack/qtmc.c \
    mspack/qtmd.c \
    mspack/system.c \
    mspack/szddc.c \
    mspack/szddd.c

mac{
    INCLUDEPATH += "osx"
    HEADERS += $$PWD/osx/config.h
}

DISTFILES += \
    LibMSPack.pri
