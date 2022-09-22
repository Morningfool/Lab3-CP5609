#include <iostream>
#include "BoardCells.h"



BoardCells  :: BoardCells():QGridLayout ()
{GameCell * aCell;
	this->setVerticalSpacing(0);
	this->setHorizontalSpacing(0);
	for (int i=0; i<SIZE_X; i++) {
		for (int j=0; j<SIZE_Y; j++) {
			aCell= new GameCell;
			this->addWidget(aCell, i, j);
			theCells[i][j]=aCell;
		}
	}
}


void BoardCells::forwardChangeColor(int i, int j, char c)
{ 
	QColor temp;
	
	switch (c) {
		case 'Y':temp =Qt::yellow; break; case '#':temp=Qt::black; break;
		case'B':temp=Qt::blue; break;
			case 'R':
			temp=Qt::red;
				break;
		case 'I': temp=Qt::white;
				break;
		default:temp=Qt::darkBlue;
			break;
	}
	theCells[i][j]->setColor(temp);	
	theCells[i][j]->update();
	
}	
