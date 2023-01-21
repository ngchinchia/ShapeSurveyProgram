#include "ShapeTwoD.h"
#include "Square.h"
#include "Cross.h"
#include "Rectangle.h"
#include "Circle.h"
using namespace std;

ShapeTwoD::ShapeTwoD (string n,bool cws)
{
	  name = n;
	  containsWarpSpace = cws;
}
string ShapeTwoD::getName ()
{
      return name;
}
bool ShapeTwoD::getContainsWarpSpace ()
{
      return containsWarpSpace;
}

string ShapeTwoD::toString()
{
      string empString = "";
      stringstream ss;
      ss<<area;

      if (containsWarpSpace == true)
        empString+= "Name: "+name+ "\nSpecial Type: WS \nArea: "+ss.str() + " units square";

      else
        empString+= "Name: "+name+ "\nSpecial Type: NS \nArea: "+ss.str() + " units square";

      return empString;
 }


void ShapeTwoD::setName (string toSetName)
{
      name = toSetName;
}
void ShapeTwoD::setContainsWarpSpace (bool toSetWarpSpace)
{
      containsWarpSpace = toSetWarpSpace;
}

int ShapeTwoD::getArea()
{
    	return area;
}

float ShapeTwoD::round(float var)
{
	float value = (int)(var*100+.5);
	return(float)value/100;
}
