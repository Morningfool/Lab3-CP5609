/*	
 *
 *
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QTimer>
#include <QPushButton>

#include "Model.h"
#include "BoardCells.h"


#include "Common.h"

class QPushButton;
class QTimer;

class Controller: public QWidget
{
	Q_OBJECT

	QPushButton 	*startButton; 		// Starts
	QPushButton 	*upButton; 		// up button
	QPushButton 	*downButton; 		// down button
	QPushButton 	*leftButton; 		// left button
	QPushButton 	*rightButton; 		// rigght button


	QTimer		*gameTimer;		// 

	bool		gameRunning;		// 
	bool		setupComplete;		// 

	Model	*myModel;
	BoardCells *myBoard;

public:
	Controller(QWidget *parent = 0);
	~Controller();


private slots:
	void startGame();
	void update();
	void sendUp();
	void sendDown();
	void sendLeft();
	void sendRight();
	void forwardChangeColor(int i, int j, char c);

};

#endif

