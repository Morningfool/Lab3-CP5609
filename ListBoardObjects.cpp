#include <iostream>
#include "BoardObject.h"
#include "ListBoardObjects.h"

ListBoardObjects:: ListBoardObjects(p_BoardObject newOne):list()
	{
	 	std::vector <p_BoardObject>:: iterator it;
	 	it=list.begin();
	 	list.insert(it,newOne);
        }

p_BoardObject ListBoardObjects:: theFirst()
	{
	   if (0 < list.size()  ) 
		{ internalIterator=list.begin();
	   	  return (*internalIterator);
		}
	   else
		return NULL;
	}


void ListBoardObjects:: addOne(p_BoardObject newOne)
	 { 
	 	std::vector <p_BoardObject>:: iterator it;
	 	it=list.begin();
	 	list.insert(it,newOne);
	 }

p_BoardObject ListBoardObjects :: theNext()
	{ 
	   internalIterator++;
	   if (internalIterator < list.end())
	   {
		   return (*internalIterator);
	   }
	   else
		return NULL;
	}

void ListBoardObjects :: removeOnePlayer()
	{
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_PLAYER==(*it)->get_Type())
		   { list.erase(it); return;}
                  it++;
		}

	   return ;
	}


bool ListBoardObjects :: isThereAWall()
	{
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_WALL==(*it)->get_Type())
		   {  return true;}
                  it++;
		}

	   return false ;
	}


int ListBoardObjects :: isCookieValue()
	{   int temp=0;
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_COOKIE==(*it)->get_Type())
		   { temp= ((Cookie *)(*it))->get_value();
		     list.erase(it); 
		     return temp;
                   }
                  it++;
		}

	   return temp ;
	}




struct Room
{
private:
	int bed;
	char number[20];
	char gender;
public:
	void print_info();
};
Void Room::print_info()
{
	cout << bed << endl;
	cout << number << endl;
	cout << gender << endl;
};





class enemy {
private:
	char enemyname[30];  //enemy name
public:
	int number;  //enemy number
	void enemyname(char* name);
	void getname(char* name);
	void averagenumber(enemy el, enemy e2);
};
void enemy::setName(char* name) {
	strcpy(enemyname, name);  //correct
}
void enemy::getname(char* name) {
	strcpy(name, szName);  //correct
}
void enemy::averagenumber(enemy el, enemy e2)
{
	number = (el.number + e2.number) / 2;
}
int main()
{
	enemy e;
	strcpy(e.enemyname, "monster23");  //wrong
	e.setName("monster");  //correct
	e.number = 5000;  //correct
	return 0;
}