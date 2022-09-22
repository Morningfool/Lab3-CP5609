


#include "BoardObject.h"
#include "Cookie.h"

int PrizeValues[]={10,20,30,40};

void Cookie :: touch ()
		{ switch (status)
		  { case VISIBLE : if (color1==get_Color() )
			            set_color(color2);
			          else
			             set_color(color1);
                                   break;
		    case  EATEN :
		    case  EXPIRED :
			             set_color(BACKGROUND);
		  }
		}

int Cookie :: get_value ()
	{return PrizeValues[valueIndex]; }

