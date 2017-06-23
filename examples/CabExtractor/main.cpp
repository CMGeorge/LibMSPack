#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <unistd.h>
#include "mspack.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    struct mscab_decompressor *cabd;
    struct mscabd_cabinet *cab;
    struct mscabd_file *file;
    int test;

    MSPACK_SYS_SELFTEST(test);
    if (test != MSPACK_ERR_OK) exit(0);

    if ((cabd = mspack_create_cab_decompressor(NULL))) {
        if ((cab = cabd->open(cabd, "/Users/cmgeorge/Downloads/SimpleDemo.CTX"))) {
            for (file = cab->files; file; file = file->next) {
                qDebug()<<file->filename;
                qDebug()<<"Extracting"<<cabd->extract(cabd,file,QString("/Users/cmgeorge/Downloads/"+QString(file->filename)).toLatin1());
            }
            cabd->close(cabd, cab);
        }else{
            qDebug()<<"Archive not found";
        }
        mspack_destroy_cab_decompressor(cabd);
    }else{
        qDebug()<<"No Compressor Found";
    }
    qDebug()<<"App done";
    return a.exec();
}
