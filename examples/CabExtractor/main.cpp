#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <unistd.h>
#include "mspack.h"
#include <QDebug>
#include <QTemporaryFile>
#include <QTemporaryDir>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    struct mscab_decompressor *cabd;
    struct mscabd_cabinet *cab;
    struct mscabd_file *file;
    int test;

    MSPACK_SYS_SELFTEST(test);
    if (test != MSPACK_ERR_OK) exit(0);
    QFile _source(":/SimpleDemo.CTX");
    if (!_source.exists()){
        qDebug()<<"Archive does not exists";
        exit(1);
    }
    QDir _tempDir(QDir::tempPath());
    if (_tempDir.exists()){
        if (!_tempDir.removeRecursively()){
            qDebug()<<"Can't clean temp directory";
        }
    }
    QString _tempDirectory = _tempDir.path();
    _tempDir.mkpath(_tempDirectory);
    QString _tempFileName("new.cab");
    //    _tempFile.remove();
    QFile _tempFilePath(_tempDirectory+"/"+_tempFileName);
    QFile::setPermissions(_tempFilePath.fileName(),QFileDevice::ReadOwner|QFileDevice::WriteOwner);
    qDebug()<<"Temp file: "<<_tempDirectory<<" using "<<_tempFilePath.fileName();

    qDebug()<<"Copying file... "<<_source.copy(_tempFilePath.fileName());//<<" = "<<_file.errorString();
    _source.flush();
    if (!_tempDir.exists()){
        qDebug()<<"Temp dir is not valid";
    }
    if (!_tempFilePath.open((QIODevice::ReadOnly))){
        qDebug()<<"File can't be oppened";
    }
    _tempFilePath.close();
    if ((cabd = mspack_create_cab_decompressor(NULL))) {
        if ((cab = cabd->open(cabd, _tempFilePath.fileName().toLatin1()))) {
            //            _tempDir.
            for (file = cab->files; file; file = file->next) {
                //                qDebug()<<file->filename;
                QString _extractedFileName = QString(_tempDirectory)+"/"+QString(file->filename);
                QFile _newFile(_extractedFileName);
                if (_newFile.exists()){
                    _newFile.remove();
                }
                int cabExtractStatus = -1;

                qDebug()<<"Extract "<<cabd->extract(cabd,file,_extractedFileName.toLatin1());

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
