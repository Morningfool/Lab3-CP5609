#include <vector>
#include  "BoardObject.h"
#include  "Player.h"
#include  "Cookie.h"
#ifndef H_LIST_OF_OBJECTS
#define H_LIST_OF_OBJECTS
typedef BoardObject* p_BoardObject;


class  ListBoardObjects
{
	std::vector <p_BoardObject> list;
	std::vector < p_BoardObject>::iterator internalIterator;
public:
	ListBoardObjects(p_BoardObject theFirst);

	p_BoardObject theFirst();
	p_BoardObject theNext();
	void addOne(p_BoardObject newOne);
	void removeOnePlayer();
	bool isThereAWall();
	int isCookieValue();
};
#endif
