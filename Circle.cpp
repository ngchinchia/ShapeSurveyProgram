#include <iostream>
#include <cmath>
#include "Circle.h"


using namespace std;

double Circle::computeArea()
{
    area= M_PI*radius*radius;
	area=ShapeTwoD::round(area);
	return area;
}

string Circle::toString()
{
      string empString = " ";
      stringstream ss;
      ss<<area;


      if (containsWarpSpace == true)
        empString+= "Name: "+name+ "\nSpecial Type: WS \nArea: "+ss.str() + " units square";
      else
        empString+= "Name: "+name+ "\nSpecial Type: NS \nArea: "+ss.str() + " units square";

      empString += "\nVertices:\n";

      empString += "Point[0]: "+circleVertex.toString() + "\nRadius: ";

      stringstream ss1;
      ss1<<radius;
      empString += ss1.str()+"\n";

      return empString;
}


bool Circle::isPointInShape (int x , int y)
{
    	int diameter = pow(radius,2);
    	int d = pow(x-circleVertex.x,2) + pow(y-circleVertex.y,2);

    	if(d < diameter)
    	{
    		return true;
    	}

    	return false;

}

bool Circle::isPointOnShape (int x , int y)
{
    	int diameter = pow(radius,2);
    	int d = pow(x-circleVertex.x,2) + pow(y-circleVertex.y,2);

    	if(d == diameter)
    	{
    		return true;
    	}

    	return false;
}


void Circle::pointsInShape()
{
    	int minx = circleVertex.x-radius;
    	int miny = circleVertex.y-radius;

    	int maxx = circleVertex.x+radius;
    	int maxy = circleVertex.y+radius;

    	bool onShape = false;
    	cout << "Points within Shape: ";
    	for(int i = minx; i < maxx; i++)
    	{
    		for(int j = miny; j<maxy; j++)
    		{
    			if(isPointInShape(i,j))
    			{
    				onShape = true;
    				cout << "(" << i << "," << j <<") ";
    			}
    		}
    	}

    	if(onShape == false)
    	{
    		cout << "There are no points in the shape.";
    	}
    	cout << endl;
}


void Circle::pointsOnShape()
    {
    	int minx = circleVertex.x-radius;
		int miny = circleVertex.y-radius;

		int maxx = circleVertex.x+radius;
		int maxy = circleVertex.y+radius;

		bool onShape = false;
		cout << "Points on perimeter: ";
		for(int i = minx; i <= maxx; i++)
		{
			for(int j = miny; j <= maxy; j++)
			{
				if(isPointOnShape(i,j))
				{
					onShape = true;
					cout << "(" << i << "," << j <<") ";
				}
			}
		}

		if(onShape == false)
		{
			cout << "There are no points in the perimeter.";
		}
		cout << endl;
    }


void Circle::printPoints()
{
    	pointsOnShape();
    	pointsInShape();
    	cout << endl;
}


void Circle::setVertices(Vertex* cv)
{
      for(int i=0; i<1; i++)
      {
        circleVertex = cv[i];
      }
}


void Circle::setRadius(int r)
{
      radius = r;
}

int Circle::getRadius()
{
      return radius;
}
