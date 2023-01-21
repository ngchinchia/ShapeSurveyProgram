#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "ShapeTwoD.h"



class Rectangle: public ShapeTwoD
{
private:
    	Vertex recVertice[4];

public:
	Rectangle(std::string n,bool type):ShapeTwoD(n,type)
	{
	}
	
		Vertex *extremePoints()
    	{
    	Vertex *arr = new Vertex[4];
    	for(int i=0;i<4;i++)
    	{
    		arr[i] = recVertice[0];
    	}

    	for(int i = 1; i < 4; i++)
		{
			if(recVertice[i].x < arr[0].x)
			{
				// smallest x axis
				arr[0] = recVertice[i];
			}
		}

		for(int i = 1; i < 4; i++)
		{
			if(recVertice[i].y < arr[2].y)
			{
				// smallest y axis
				arr[2] = recVertice[i]; 
			}
		}

		for(int i = 1; i < 4; i++)
		{
			if(recVertice[i].x > arr[1].x)
			{
				// highest x axis
				arr[1] = recVertice[i]; 
			}
		}

		for(int i = 1; i < 4; i++)
		{
			if(recVertice[i].y > arr[3].y)
			{
				// higest y axis
				arr[3] = recVertice[i]; 
			}
		}

		return arr;
    	}

	Vertex *diagonalPoints()
	{

    	Vertex *arr = new Vertex[2];

    	Vertex min = recVertice[0];
		int minX = recVertice[0].x;
		int minY = recVertice[0].y;


		// smallest Vertex;
		for(int i = 1; i < 4; i++)
		{
			if(recVertice[i].x < minX)
			{
				minX = recVertice[i].x;
				min = recVertice[i];
			}
		}
		for(int i = 0; i < 4; i++)
		{
			if(recVertice[i].x == minX && recVertice[i].y < min.y)
			{
				minY = recVertice[i].y;
				min = recVertice[i];
			}
		}


		Vertex max = recVertice[0];
		int maxX = recVertice[0].x;
		int maxY = recVertice[0].y;

		// largest Vertex;

		for(int i = 1; i < 4; i++)
		{
			if(recVertice[i].x > maxX)
			{
				maxX = recVertice[i].x;
				max = recVertice[i];
			}
		}

		for(int i = 0; i < 4; i++)
		{
			if(recVertice[i].x == maxX && recVertice[i].y > max.y)
			{

				maxY = recVertice[i].y;
				max = recVertice[i];
			}
		}

		arr[0] = min;
		arr[1] = max;

		return arr;
	    }

	Vertex* getRectVertex()
    	{
      		return recVertice;
    	}

	
	std::string toString();

	virtual double computeArea();
	virtual bool isPointInShape (int x , int y);
	virtual bool isPointOnShape (int x , int y);
	virtual void printPoints();

	void pointsOnShape();
	void pointsInShape();
	void setVertices(Vertex* arr);


};


#endif
