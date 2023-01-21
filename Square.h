#ifndef SQUARE_H
#define SQUARE_H
#include "ShapeTwoD.h"


class Square: public ShapeTwoD
{
private:
	Vertex sqVertice[4];

public:
	Square(std::string n,bool type):ShapeTwoD(n,type)
	{
	}
	Vertex *extremePoints()
    	{
    	Vertex *arr = new Vertex[4];
    	for(int i=0;i<4;i++)
    	{
    		arr[i] = sqVertice[0];
    	}

    	for(int i = 1; i < 4; i++)
		{
			if(sqVertice[i].x < arr[0].x)
			{	
				// smallest x-axis
				arr[0] = sqVertice[i];	
			}
		}

		for(int i = 1; i < 4; i++)
		{
			if(sqVertice[i].y < arr[2].y)
			{
				// smallest y-axis
				arr[2] = sqVertice[i]; 
			}
		}

		for(int i = 1; i < 4; i++)
		{
			if(sqVertice[i].x > arr[1].x)
			{
				// highest x-axis
				arr[1] = sqVertice[i]; 
			}
		}

		for(int i = 1; i < 4; i++)
		{
			if(sqVertice[i].y > arr[3].y)
			{
				//highest y-axis
				arr[3] = sqVertice[i]; 
			}
		}

		return arr;
	    }

		Vertex *diagonalPoints()
   	{

    	Vertex *arr = new Vertex[2];

    	Vertex min = sqVertice[0];
		int minX = sqVertice[0].x;
		int minY = sqVertice[0].y;


		// smallest Vertex;
		for(int i = 1; i < 4; i++)
		{
			if(sqVertice[i].x < minX)
			{
				minX = sqVertice[i].x;
				min = sqVertice[i];
			}
		}
		for(int i = 0; i < 4; i++)
		{
			if(sqVertice[i].x == minX && sqVertice[i].y < min.y)
			{
				minY = sqVertice[i].y;
				min = sqVertice[i];
			}
		}


		Vertex max = sqVertice[0];
		int maxX = sqVertice[0].x;
		int maxY = sqVertice[0].y;

		// largest Vertex;

		for(int i = 1; i < 4; i++)
		{
			if(sqVertice[i].x > maxX)
			{
				maxX = sqVertice[i].x;
				max = sqVertice[i];
			}
		}

		for(int i = 0; i < 4; i++)
		{
			if(sqVertice[i].x == maxX && sqVertice[i].y > max.y)
			{

				maxY = sqVertice[i].y;
				max = sqVertice[i];
			}
		}

		arr[0] = min;
		arr[1] = max;

		return arr;
    	}
	Vertex* getSquareVertex()
   	{
 	     return sqVertice;
    	}

	std::string toString();
	

	virtual double computeArea ();
	virtual bool isPointInShape (int x , int y);
	virtual bool isPointOnShape (int x , int y);
	virtual void printPoints();

	void pointsOnShape();
	void pointsInShape();
	void setVertices(Vertex* arr);
	
};


#endif
