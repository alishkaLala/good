#include "filewriteread.h"
#include <iostream>
#include <QDebug>

FileWriteRead::FileWriteRead(QObject *parent) :
  QThread(parent)
{
  this->fileopen = false;
  this->fileName="default.txt";
  this->rewrite=false;
}



FileWriteRead::FileWriteRead(QString fileNameTmp, bool rewriteTmp,QObject *parent):
  QThread(0)
{

  this->fileopen = false;
  this->fileName=fileNameTmp;
  this->rewrite=rewriteTmp;
  qDebug()<<"get file name(WRITER) " <<fileName;


}

void FileWriteRead::run ()
{

}

void FileWriteRead:: test()
{
  qDebug ()<<"get signal from getter";
}

bool FileWriteRead::isFileOpen()
{
  return this->fileopen;
}

bool FileWriteRead::tryOpen(QString kode)
{
  if (this->fileopen){
    return fileopen;
  }
  else {


    this->fileStream = new QFile (this->fileName);
    if ( (this->fileStream->exists()==false) || this->rewrite == true ){
      this->fileStream->open(QIODevice::WriteOnly);

    }
    else {
      this->fileStream->open(QIODevice::Append);
    }
    this->textStream = new QTextStream (this->fileStream);


  }
  this->fileopen = this->fileStream->exists();
  return this->fileopen;

}
bool FileWriteRead::write( QString data )
{
  if (!this->fileopen){
    return false;

  }
  else
    {

      *this->textStream << data;
      *this->textStream<<"\n";
      return true;
    }

}
bool FileWriteRead::closeAndSave(){
  if (fileopen){
    this->fileopen=false;
    this->fileStream->close();
    qDebug()<<"close and save";
    deleteThis();
    return true;
  }
  return false;

}

bool FileWriteRead::close(){
  if (fileopen){
    deleteThis();
    return true;
  }
  return false;

}


void FileWriteRead::deleteThis(){
  delete this->textStream;
  delete this->fileStream;
  delete this;
}
FileWriteRead *FileWriteRead::changeFile( QString fileName,bool rewrite ){
  if (fileopen){
    this->closeAndSave();
  }
  return  new FileWriteRead ( fileName,rewrite );

}
QString FileWriteRead::read (){
  if (!this->fileopen  )
    {
      this->fileStream = new QFile (this->fileName);
      if (this->fileStream->exists())
        {
          this->textStreamRead.setDevice(this->fileStream);
          return this->textStreamRead.readAll();
        }

    }
  return "";
}

