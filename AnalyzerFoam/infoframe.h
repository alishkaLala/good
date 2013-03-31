#ifndef INFOFRAME_H
#define INFOFRAME_H

#include <QWidget>
#include <QEvent>

namespace Ui {
class InfoFrame;
}

class InfoFrame : public QWidget
{
  Q_OBJECT

public:
  explicit InfoFrame(QWidget *parent = 0);
  void showEvent(QShowEvent *event);
  void closeEvent(QCloseEvent *event);
  void destroyThis();
  ~InfoFrame();

private slots:
  void on_pushButton_clicked();

private:
  Ui::InfoFrame *ui;
  QWidget *p;
};

#endif // INFOFRAME_H
