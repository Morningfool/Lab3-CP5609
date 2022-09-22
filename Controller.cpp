/*	
 *
 *
 */
#include <QtGui>
#include "Controller.h"




Controller :: Controller(QWidget *parent ) : QWidget (parent)

{
	gameTimer = new QTimer(this);
	connect(gameTimer, SIGNAL(timeout()), this, SLOT(update()));
	
	
	startButton = new QPushButton(tr("&START"));
        startButton->hide();
	upButton = new QPushButton(tr("&UP"));
        upButton->hide();
	downButton = new QPushButton(tr("&DOWN"));
        downButton->hide();
	rightButton = new QPushButton(tr("&RIGHT"));
        rightButton->hide();
	leftButton = new QPushButton(tr("&LEFT"));
        leftButton->hide();

	QGridLayout *buttonLayout1 = new QGridLayout;
	buttonLayout1->addWidget (upButton,0,1);
	buttonLayout1->addWidget (leftButton,1,0);
	buttonLayout1->addWidget (rightButton,1,2);
	buttonLayout1->addWidget (downButton,2,1);
	

	QGridLayout *buttonLayout2 = new QGridLayout;
	buttonLayout2->addWidget(startButton);

	QVBoxLayout *gameLayout = new QVBoxLayout;
	gameLayout->addLayout(buttonLayout1);
	gameLayout->addLayout(buttonLayout2);
	setLayout(gameLayout);

	connect(startButton,SIGNAL(clicked()),this,SLOT(startGame()));
	connect(upButton,SIGNAL(clicked()),this,SLOT(sendUp()));
	connect(downButton,SIGNAL(clicked()),this,SLOT(sendDown()));
	connect(leftButton,SIGNAL(clicked()),this,SLOT(sendLeft()));
	connect(rightButton,SIGNAL(clicked()),this,SLOT(sendRight()));

	
	myBoard = new BoardCells;

	gameLayout->addLayout(myBoard);
	setLayout(gameLayout);
	
	myModel = new Model(SIZE_X,SIZE_Y);
	
	connect(myModel, SIGNAL(cellChanged(int, int, char)), this, SLOT(forwardChangeColor(int , int , char )));
	
	setWindowTitle(tr("VLAD's SIMPLE PACK-MAN"));
	
	if (myModel->setModelOK() ) {
		startButton->show();
	}
	
}

Controller::~Controller()
{
	delete gameTimer;
}

void Controller::startGame()
{
	if (myModel->setModelOK() ) {
		startButton->hide();
			upButton->show();
		downButton->show();
		leftButton->show();
		rightButton->show();
		gameTimer->start(500);
	}
}

void Controller::update()
	{
		
		myModel->paint();

	}
			
void Controller::sendUp()
{ myModel->move('e'); 	
}	

void Controller::sendDown()
{ myModel->move('x'); 	
}	
			
void Controller::sendLeft()
{ myModel->move('s'); 	
}	

void Controller::sendRight()
{ myModel->move('d'); 	
}	

void Controller::forwardChangeColor(int i, int j, char c)
{
	myBoard->forwardChangeColor(i,j,c);
}



