
#include "GameCell.h"

GameCell::GameCell(QWidget *parent ) :QWidget(parent)
{

	currentColor=Qt::darkBlue;
	setPalette( QPalette(currentColor));
	setAutoFillBackground(true);
	setMinimumSize(25, 25);
}

void GameCell:: setColor(QColor aColor)
	{ currentColor=aColor;  setPalette( QPalette(currentColor));}


void GameCell::paintEvent(QPaintEvent *event)
	{
	}



