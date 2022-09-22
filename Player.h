#ifndef H_PLAYER
#define H_PLAYER
#include <iostream>

enum PlayerState { ALIVE, DEAD};

#include "BoardObject.h"

class Player : public BoardObject
{

private:
	PlayerState status;
	ObjectColours color1;
	ObjectColours  color2;

public:
	Player (int start_x, int start_y):BoardObject(start_x,start_y)
		{ status=ALIVE;
		  color1 = RED;
		  color2  = BLUE;
		  myClass=A_PLAYER;
		};

	virtual void touch ();
};
#endif
