#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <QWidget>

class GameCell : public QWidget
 {
     Q_OBJECT
 private:
     QColor currentColor;

 public:
     GameCell(QWidget *parent = 0);

     //QColor currentColor() const { return currentColor; }

 public slots:
     void setColor(QColor aColor);

 protected:
     void paintEvent(QPaintEvent *event);

 };

#endif

