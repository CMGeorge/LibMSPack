warning($$PWD)
HEADERS += \
    $$PWD/mspack/cab.h \
    $$PWD/mspack/chm.h \
    $$PWD/mspack/crc32.h \
    $$PWD/mspack/des.h \
    $$PWD/mspack/hlp.h \
    $$PWD/mspack/kwaj.h \
    $$PWD/mspack/lit.h \
    $$PWD/mspack/lzss.h \
    $$PWD/mspack/lzx.h \
    $$PWD/mspack/mspack.h \
    $$PWD/mspack/mszip.h \
    $$PWD/mspack/oab.h \
    $$PWD/mspack/qtm.h \
    $$PWD/mspack/readbits.h \
    $$PWD/mspack/readhuff.h \
    $$PWD/mspack/sha.h \
    $$PWD/mspack/system.h \
    $$PWD/mspack/szdd.h

SOURCES += \
    $$PWD/mspack/cabc.c \
    $$PWD/mspack/cabd.c \
    $$PWD/mspack/chmc.c \
    $$PWD/mspack/chmd.c \
    $$PWD/mspack/crc32.c \
    $$PWD/mspack/hlpc.c \
    $$PWD/mspack/hlpd.c \
    $$PWD/mspack/kwajc.c \
    $$PWD/mspack/kwajd.c \
    $$PWD/mspack/litc.c \
    $$PWD/mspack/litd.c \
    $$PWD/mspack/lzssd.c \
    $$PWD/mspack/lzxc.c \
    $$PWD/mspack/lzxd.c \
    $$PWD/mspack/mszipc.c \
    $$PWD/mspack/mszipd.c \
    $$PWD/mspack/oabc.c \
    $$PWD/mspack/oabd.c \
    $$PWD/mspack/qtmc.c \
    $$PWD/mspack/qtmd.c \
    $$PWD/mspack/system.c \
    $$PWD/mspack/szddc.c \
    $$PWD/mspack/szddd.c

mac{
    INCLUDEPATH += "$$PWD/osx/"
    HEADERS += $$PWD/osx/config.h
}
