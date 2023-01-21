#include <cmath>
#include <iostream>
#include "Rectangle.h"

using namespace std;
double Rectangle::computeArea ()
    {
      Vertex points [2]= {Vertex(),Vertex()};
      double oneVal;
      double secondVal;
      points[0]=recVertice[0];
      for(int i=1;i<4;i++){
        if (recVertice[i].y==points[0].y)
        {
          //the one with same y
          oneVal=abs(recVertice[i].x-points[0].x);

        }
      }

      for(int i=1;i<4;i++){
        if (recVertice[i].x==points[0].x)
        {
          //the one with same x
          secondVal=abs(recVertice[i].y-points[0].y);
        }
      }
      cout << oneVal << " " << secondVal << endl;
      area = oneVal*secondVal;
      return area;
    }

string Rectangle::toString()
    {
      string empString = "";
      stringstream ss;
      ss<<area;

      if (containsWarpSpace == true)
        empString+= "Name: "+name+ "\nSpecial Type: WS \nArea: "+ss.str()+" units square";
      else
        empString+= "Name: "+name+ "\nSpecial Type: NS \nArea: "+ss.str()+" units square";

      empString += "\nVertices:\n";
      string vertice = "";
      for(int i=0; i<4; i++)
      {
        stringstream ss1;
        ss1<<i+1;
        vertice += "Point["+ss1.str()+"]: "+recVertice[i].toString() + "\n";
      }

      return empString+vertice;
    }



bool Rectangle::isPointInShape (int x , int y)
    {

    	Vertex *arr= extremePoints();
    	if( x < arr[1].x && x > arr[0].x && y < arr[3].y && y > arr[2].y)
    	{
    		return true;
    	}

    	return false;
    }

bool Rectangle::isPointOnShape (int x , int y)
    {
    	Vertex point;
    	
	// match the x coordinate to check if it is on Shape

    	for(int i = 0; i < 4; i++)
    	{
    		if(x == recVertice[i].x)
    		{
    			point = recVertice[i];
    			for(int i = 0; i < 4; i++)
    			{
    				if(recVertice[i].x == point.x && recVertice[i].y != point.y)
    				{
    					if((y > point.y && y < recVertice[i].y) || (y < point.y && y > recVertice[i].y))
    					{
    						return true;
    					}
    				}
    			}

    		}
    	}
    	
	// match the y coordinate to check if it is on Shape

		for(int i = 0; i < 4; i++)
		{
			if(y == recVertice[i].y)
			{
				point = recVertice[i];
				for(int i = 0; i < 4; i++)
				{
					if(recVertice[i].y == point.y && recVertice[i].x != point.x)
					{
						if((x > point.x && x < recVertice[i].x) || (x < point.x && x > recVertice[i].x))
						{
							return true;
						}
					}
				}

			}
		}

		return false;

    }


void Rectangle::pointsOnShape()
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

void Rectangle::pointsInShape()
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

void Rectangle::printPoints()
    {
    	pointsOnShape();
    	pointsInShape();
    	cout << endl;
    }
void Rectangle::setVertices(Vertex* arr)
    {
      for(int i=0; i<4; i++)
      {
        recVertice[i] = arr[i];
      }
    }


