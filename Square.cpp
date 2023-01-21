#include <iostream>
#include "Square.h"
#include <cmath>
using namespace std;

double Square::computeArea ()
    {

      Vertex points[2] = {Vertex(),Vertex()};
      points[0]=sqVertice[0];
      for(int i=1;i<4;i++){
        if(sqVertice[i].y==points[0].y){
            points[1]=sqVertice[i];
            i=4;
        }
      }
      double value=abs(points[0].x-points[1].x);
      area = value*value;
      return area;

    }

string Square::toString()
    {
      string empString = "";
      stringstream ss;
      ss<<area;

      if (containsWarpSpace == true)
        empString+= "Name: "+name+ "\nSpecial Type: WS \nArea: "+ss.str() +" units square";
      else
        empString+= "Name: "+name+ "\nSpecial Type: NS \nArea: "+ss.str()+ " units square";

      empString += "\nVertices:\n";
      string vertice = "";
      for(int i=0; i<4; i++)
      {
        stringstream ss1;
        ss1<<i+1;
        vertice += "Point["+ss1.str()+"]: "+sqVertice[i].toString() + "\n";
      }

      return empString+vertice;
    }


bool Square::isPointInShape (int x , int y)
    {

    	Vertex *arr= extremePoints();
    	if( x < arr[1].x && x > arr[0].x && y < arr[3].y && y > arr[2].y)
    	{
    		return true;
    	}
    	return false;
    }

bool Square::isPointOnShape (int x , int y)
    {
    	Vertex point;
    	
	//Uses x coordinate to check if it is on shape

    	for(int i = 0; i < 4; i++)
    	{
    		if(x == sqVertice[i].x)
    		{
    			point = sqVertice[i];
    			for(int i = 0; i < 4; i++)
    			{
    				if(sqVertice[i].x == point.x && sqVertice[i].y != point.y)
    				{
    					if((y > point.y && y < sqVertice[i].y) || (y < point.y && y > sqVertice[i].y))
    					{
    						return true;
    					}
    				}
    			}

    		}
    	}
    	

	//Uses y coordinate to check if it is on shape

		for(int i = 0; i < 4; i++)
		{
			if(y == sqVertice[i].y)
			{
				point = sqVertice[i];
				for(int i = 0; i < 4; i++)
				{
					if(sqVertice[i].y == point.y && sqVertice[i].x != point.x)
					{
						if((x > point.x && x < sqVertice[i].x) || (x < point.x && x > sqVertice[i].x))
						{
							return true;
						}
					}
				}

			}
		}

		return false;

    }


void Square::pointsOnShape()
    {

    	Vertex *arr = diagonalPoints();
    	Vertex min = arr[0];
    	Vertex max = arr[1];
    	bool onShape = false;

    	cout << "Points on perimeter: ";

    	for(int i = min.x; i <= max.x;i++)
    	{

    		for(int j = min.y; j <= max.y; j++)
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


void Square::pointsInShape()
    {
    	Vertex *arr = diagonalPoints();
    	Vertex min = arr[0];
    	Vertex max = arr[1];
    	bool inShape = false;
    	cout << "Points within shape: ";

    	for(int i = min.x; i < max.x;i++)
    	{
    		for(int j = min.y; j <max.y; j++)
    		{
    			if(isPointInShape(i,j))
    			{
    				inShape = true;
    				cout << "(" << i << "," << j <<") ";
    			}
    		}
    	}
    	if(inShape == false)
    	{
    		cout << "There are no points in the shape.";
    	}
    	cout << endl << endl;
    }


void Square::printPoints()
    {
    	pointsOnShape();
    	pointsInShape();
    	cout << endl;
    }


void Square::setVertices(Vertex* arr)
    {
      for(int i=0; i<4; i++)
      {
        sqVertice[i] = arr[i];
      }
    }



