#ifndef FILEWRITEREAD_H
#define FILEWRITEREAD_H

#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class FileWriteRead : public QThread
{
  Q_OBJECT
  void run ();
public:
  explicit FileWriteRead(QObject *parent = 0);
  explicit FileWriteRead  (QString fileName, bool rewrite,QObject *parent = 0);
  //  FileWriteRead();
public slots:
  void test();
  bool isFileOpen();
  bool tryOpen(QString kode);
  bool write( QString data ); // QObject ??
  bool closeAndSave(); // delete this ?
  bool close(); // delete this ?
  FileWriteRead *changeFile( QString fileName,bool rewrite );

  QString read (); // Qstring? , return all file, don't tested

public:
  QString fileName;


private:
  void deleteThis();
  bool fileopen;
  bool rewrite;
  QFile *fileStream;
  QTextStream *textStream;
  QTextStream textStreamRead;
  QString code;


};

#endif // FILEWRITEREAD_H
