#include <iostream>
#include <cmath>
#include <cstring>
#include "Cross.h"


using namespace std;

double Cross::computeArea ()
{

        // Find area of the vertical rectangle
    	Vertex min = crossV[0];
		Vertex max = crossV[0];
    	int iLength = 0;
    	int iWidth = 0;
    	int length = 0;
    	int width = 0;
    	int vRectArea = 0;
    	int hRectArea = 0;
    	int iRectArea = 0;

    	
    	// Find width of the vertical rectangle 

    	for(int i = 1; i < 12; i++)
    	{
    		if(crossV[i].y < min.y)
    		{
    			min = crossV[i];
    		}
    	}

    	for(int i = 0; i < 12; i++)
    	{
    		if(crossV[i].y == min.y && crossV[i].x != min.x)
    		{
    			width = abs(crossV[i].x - min.x);
    			iWidth = width;
    			break;
    		}
    	}

    	// Find length of the vertical rectangle 
    	for(int i = 1; i < 12; i++)
    	{
    		if(crossV[i].x == min.x && crossV[i].y > max.y)
    		{
    			max = crossV[i];
    		}
    	}

    	length = abs(min.y - max.y);
    	vRectArea = length * width;

    	// Find length of the horizontal rectangle
    	min = crossV[0];
	max = crossV[0];

    	for(int i = 1; i < 12; i++)
		{
			if(crossV[i].x < min.x)
			{
				min = crossV[i];
			}
		}

    	for(int i = 0; i < 12; i++)
    	{
    		if(crossV[i].x == min.x && crossV[i].y != min.y)
    		{
    			length = abs(crossV[i].y - min.y);
    			iLength = length;
    			break;
    		}
    	}

    	// Find width of the horizontal rectangle
    	for(int i = 1; i < 12; i++)
    	{
    		if(crossV[i].y == min.y && crossV[i].x > max.x)
    		{
    			max = crossV[i];
    		}
    	}

    	width = abs(min.x - max.x);
    	hRectArea = length * width; // Find area of the horizontal rectangle

	
    	iRectArea = iLength * iWidth;
    	area = hRectArea + vRectArea - iRectArea;

    	return area;
}


void Cross::findHorizonRec()
{

    	Vertex point = crossV[0];

    	for(int i = 1; i < 12; i++)
    	{
    		if(crossV[i].x < point.x)
    		{
    			point = crossV[i];
    		}
    	}

    	for(int i = 0; i < 12; i++)
    	{
    		if(crossV[i].x == point.x && crossV[i].y != point.y)
    		{
    			horizontalRectangle[0] = crossV[i];
    			horizontalRectangle[1] = point;
    			break;
    		}
    	}

    	point = crossV[0];
    	for(int i = 1; i < 12; i++)
    	{
    		if(crossV[i].x > point.x)
    		{
    			point = crossV[i];
    		}
    	}

    	for(int i = 0; i < 12; i++)
    	{
    		if(crossV[i].x == point.x && crossV[i].y != point.y)
    		{
    			horizontalRectangle[2] = crossV[i];
    			horizontalRectangle[3] = point;
    			break;
    		}
    	}
}

void Cross::findVerticalRec()
{
    	Vertex point = crossV[0];

    	for(int i = 1; i < 12; i++)
    	{
    		if(crossV[i].y < point.y)
    		{
    			point = crossV[i];
    		}
    	}

    	for(int i = 0; i < 12; i++)
    	{
    		if(crossV[i].y == point.y && crossV[i].x != point.x)
    		{
    			verticalRectangle[0] = crossV[i];
    			verticalRectangle[1] = point;
    			break;
    		}
    	}

    	point = crossV[0];
    	for(int i = 1; i < 12; i++)
    	{
    		if(crossV[i].y > point.y)
    		{
    			point = crossV[i];
    		}
    	}

    	for(int i = 0; i < 12; i++)
    	{
    		if(crossV[i].y == point.y && crossV[i].x != point.x)
    		{
    			verticalRectangle[2] = crossV[i];
    			verticalRectangle[3] = point;
    			break;
    		}
    	}

}


string Cross::toString()
{
      string empString = "";
      stringstream ss;
      ss<<area;

      if (containsWarpSpace == true)
        empString+= "Name: "+name+ "\nSpecial Type: WS \nArea: "+ss.str() + " units square";
      else
        empString+= "Name: "+name+ "\nSpecial Type: NS \nArea: "+ss.str() + " units square";

      empString += "\nVertices:\n";
      string vertice = "";
      for(int i=0; i<12; i++)
      {
        stringstream ss1;
        ss1<<i+1;
        vertice += "Point["+ss1.str()+"]: "+crossV[i].toString() + "\n";
      }

      return empString+vertice;
}


bool Cross::isPointInShape (int x , int y)
{

        	Vertex *arr= extremePoints();
        	if( x < arr[1].x && x > arr[0].x && y < arr[3].y && y > arr[2].y)
        	{
        		return true;
        	}

        	return false;
}
bool Cross::isPointOnShape (int x , int y)
{
        	Vertex *recVertice = new Vertex[4];

			if (isHorizontal == false)
			{
				recVertice = verticalRectangle;

			}
			else
			{
				recVertice = horizontalRectangle;
			}

        	Vertex point;
        	
		// Check whether x is on shape

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

        	// Check whether y is on shape

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


void Cross::pointsOnRec()
{
    		Vertex *arr = diagonalPoints();
    		Vertex min = arr[0];
    		Vertex max = arr[1];

    		for(int i = min.x; i <= max.x;i++)
    		{

    			for(int j = min.y; j <= max.y; j++)
    			{

    				if(isPointOnShape(i,j))
    				{
    					bool found = false;
    					Vertex v(i,j);

    					for(size_t k= 0; k < perimeterPoints.size();k++)
    					{
    						if((perimeterPoints[k].x == v.x) && (perimeterPoints[k].y == v.y))
    						{
    							found = true;
    							break;
    						}

    					}
    					if(found == false)
    					{
    						perimeterPoints.push_back(v);
    					}

    				}
    			}
    		}


    		if(perimeterPoints.empty())
    		{
    			cout << "There are no points on shape.\n";
    		}



}

void Cross::pointsOnShape()
        {
        	pointsOnRec();
        	isHorizontal = true;
        	pointsOnRec();
        	isHorizontal = false;

}

void Cross::pointsInShape()
        {
        	pointsinRectangle();
        	isHorizontal = true;
        	pointsinRectangle();
        	isHorizontal = false;
}

void Cross::pointsinRectangle()
{
	Vertex *arr = diagonalPoints();
	Vertex min=arr[0];
	Vertex max = arr[1];
	bool inShape=false;
	for(int i =min.x; i<max.x;i++)
	{
		for(int j=min.y;j<max.y;j++)
		{
			if(isPointInShape(i,j))
			{
				inShape=true;
				bool found=false;
				Vertex v(i,j);
				for(size_t k=0; k <inShapePoints.size();k++)
				{
					if(inShapePoints[k].x == v.x && inShapePoints[k].y==v.y)
					{
						found = true;
						break;
					}
				}
				if(found==false)
				{
				inShapePoints.push_back(v);
				}
			}
		}
	}
	if(inShapePoints.empty())
	{
		cout<<"There are no points in shape.\n";
	}
}

void Cross::printPoints()
	{

     	pointsInShape();
		pointsOnShape();
		int size =  perimeterPoints.size();
		cout << "Points on perimeter: ";

		for(int i = 0; i < size;i++)
		{
			bool found = false;
			for(int k = 0; k < inShapePoints.size();k++)
			{

				if(inShapePoints[k].x == perimeterPoints[i].x && inShapePoints[k].y == perimeterPoints[i].y)
				{
					found = true;
					continue;
				}

			}
			for(int k = 0; k < 12;k++)
			{

				if(crossV[k].x == perimeterPoints[i].x && crossV[k].y == perimeterPoints[i].y)
				{
					found = true;
					continue;
				}

			}

			if(found == false)
			{
				cout << perimeterPoints[i].toString() << " ";
			}

		}
		cout << endl;
		cout << "Points within shape: ";
		for(int i = 0; i < inShapePoints.size();i++)
		{
			cout << inShapePoints[i].toString() << " ";
		}

		cout << endl;
}
void Cross::setVertices(Vertex* arr)
    {
      for(int i=0; i<12; i++)
      {
        crossV[i] = arr[i];
      }

	  findHorizonRec();
	  findVerticalRec();

}


