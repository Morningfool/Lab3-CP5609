#ifndef BOARD_CELL_H
#define BOARD_CELL_H


#include "GameCell.h"
#include "Common.h"
#include <QGridLayout>

class BoardCells : public QGridLayout
{
 private:
	GameCell *theCells[SIZE_X][SIZE_Y];

 public:
     BoardCells();

     void forwardChangeColor(int i, int j, char c);

};

#endif

