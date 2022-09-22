
#include  <string>
#include <iostream>
#include  "Model.h"
#include  "ListBoardObjects.h"

using namespace std;


void touch_all (p_ListBoardObjects aList)
{
	p_BoardObject toIterate;

	toIterate=aList->theFirst();

	while (NULL!=toIterate)
	{
		toIterate->touch();

		//cerr << "Touching "<< toIterate->get_x() <<"," <<toIterate->get_y() << std::endl;
		toIterate=aList->theNext();

	}

}

char game_all (p_ListBoardObjects aList)
{
	
	p_BoardObject toIterate;

	toIterate=aList->theFirst();

	ObjectColours color =  BACKGROUND;

	while (NULL!=toIterate)
	{
		if ( BACKGROUND != toIterate->get_Color() )
		   color=toIterate->get_Color();

		toIterate=aList->theNext();
	}

	switch (color)
	{	case YELLOW : return 'Y';
	 	case BLACK : return '#';
	 	case BLUE : return 'B';
	 	case RED : return 'R';
	 	case INVISIBLE : return 'I';
	 	case BACKGROUND : return '*';
	}
}

void Model:: move(char command)
{
	if ('p'!=command)
	{
	  switch (command)
	   { case 'e': if (player_id_x<=0) break;
			else
			  { 
                            if (!  mySpace[player_id_x-1][player_id_y]->isThereAWall())
			      { mySpace[player_id_x][player_id_y]->removeOnePlayer();
			        player_id_x--;
			        startPlayer = new Player(player_id_x,player_id_y);
                                mySpace[player_id_x][player_id_y]->addOne(startPlayer);

                              }
			  }
		     break;
	     case 'x': if (player_id_x>=the_rows-1) break;
			else
			  { 
                            if (!  mySpace[player_id_x+1][player_id_y]->isThereAWall())
			      { mySpace[player_id_x][player_id_y]->removeOnePlayer();
			        player_id_x++;
			        startPlayer = new Player(player_id_x,player_id_y);
                                mySpace[player_id_x][player_id_y]->addOne(startPlayer);
                              }
			  }
		     break;
	     case 's': if (player_id_y<=0) break;
			else
			  { 
                            if (!  mySpace[player_id_x][player_id_y-1]->isThereAWall())
			      { mySpace[player_id_x][player_id_y]->removeOnePlayer();
			        player_id_y--;
			        startPlayer = new Player(player_id_x,player_id_y);
                                mySpace[player_id_x][player_id_y]->addOne(startPlayer);
                              }
			  }
		     break;
	     case 'd': if (player_id_y>=the_cols-1) break;
                       else
			  { 
                            if (!  mySpace[player_id_x][player_id_y+1]->isThereAWall())
			      { mySpace[player_id_x][player_id_y]->removeOnePlayer();
			        player_id_y++;
			        startPlayer = new Player(player_id_x,player_id_y);
                                mySpace[player_id_x][player_id_y]->addOne(startPlayer);
                              }
			  }
		     break;
	   }
	   int cookieValue = mySpace[player_id_x][player_id_y]->isCookieValue();
	   if (cookieValue>0)
		{
		    std::cerr << "Ate a cookie\n";
		    currentScore+=cookieValue;
		}

	}
}

void Model:: paint()
	{ char draw;
          std::string row;

		row="";
          for (int i=0; i<the_rows; i++)
	   { row="";
	     for (int j=0; j<the_cols; j++)
		{  touch_all (mySpace[i][j]);
		   draw =game_all(mySpace[i][j]);
		   
		//send message to A_Cell (i,j) to reset its color to draw
			emit cellChanged(i,j,draw);
		   row.push_back(draw);
		}
              cout << row << endl;
           }
	   cout << "CURRENT SCORE : "<< currentScore << endl;
	}

