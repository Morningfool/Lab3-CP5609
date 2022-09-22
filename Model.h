#ifndef MODEL_H
#define MODEL_H

#define ROWS 20
#define COLUMNS 20

#include <vector>
#include  "BoardObject.h"
#include  "ListBoardObjects.h"
#include  "Player.h"
#include  "Wall.h"
#include  "Cookie.h"
#include  <QWidget>

class Controller;

typedef  ListBoardObjects* p_ListBoardObjects;

class Model : public QWidget
{

	Q_OBJECT

private:

	int the_rows, the_cols;

	bool setOK;
	bool gameOn;
	int lives;
	p_ListBoardObjects   mySpace[ROWS][COLUMNS];
	int player_id_x;
	int player_id_y;
	Player *startPlayer;
	int currentScore;
	Controller * myController;
	

public:

	Model (int rows, int cols)
	{ 
		
	  if ((ROWS >= rows ) && (COLUMNS >= cols)) 
	  {  setOK=false; the_rows=rows; the_cols=cols;
                  lives=3000000; gameOn=true;
			for (int i=0;  i<rows; i++)
			  for (int j=0;  j<cols; j++)
			    {
		              BoardObject* aBackground = new BoardObject(i,j);
			      p_ListBoardObjects aList =new ListBoardObjects(aBackground);
			      mySpace[i][j]=aList;
			    }
		    player_id_x =the_rows/2;
		    player_id_y =the_cols/2;
		    startPlayer = new Player(player_id_x,player_id_y);
		    currentScore =0;

                    (mySpace[player_id_x][player_id_y])->addOne(startPlayer);

	            for	(int i=1; i<the_rows-1; i++)
		       { Wall * aWall = new Wall (i,1);
                         (mySpace[i][1])->addOne(aWall);
		         aWall = new Wall (i,the_cols-2);
                         (mySpace[i][the_cols-2])->addOne(aWall);
			}

	            for	(int i=1; i<the_rows-1; i=i+2)
		       { Cookie * aCookie = new Cookie (i,0);
                         (mySpace[i][0])->addOne(aCookie);
		         aCookie = new Cookie (i,the_cols-1);
                         (mySpace[i][the_cols-1])->addOne(aCookie);
			}
			setOK=true;
		}
	  else
		setOK=false;

	};

	bool setModelOK () {return setOK;};



	bool IamAlive() {if (0<lives) { lives--; return true;}
                         else return false;}
public slots:
	void move(char command);

	void paint();

signals:
	void cellChanged(int i, int j, char draw);
};
#endif
