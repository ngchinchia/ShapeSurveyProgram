#ifndef CROSS_H
#define CROSS_H
#include <cmath>
#include <vector>
#include "ShapeTwoD.h"


class Cross : public ShapeTwoD
{

private:
	Vertex crossV[12];
    Vertex horizontalRectangle[4];
   	Vertex verticalRectangle[4];

	bool isHorizontal;
	
	std::vector<Vertex>perimeterPoints;
	int countPerimeterPoints;
	std::vector<Vertex> inShapePoints;
    int countInShapePoints;

public:
     	Cross(std::string n,bool type):ShapeTwoD(n,type)
	{
	isHorizontal = false;
    	countInShapePoints = 0;
    	countPerimeterPoints = 0;


	}
		Vertex *extremePoints()
		{
		//To find the max and min of x and y coordinates
    		Vertex *recVertice = new Vertex[4];

    		if (isHorizontal == false)
    		{
    			recVertice = verticalRectangle;

    		}
    		else
    		{
    			recVertice = horizontalRectangle;
    		}
        	Vertex *arr = new Vertex[4];
        	for(int i=0;i<4;i++)
        	{
        		arr[i] = recVertice[0];
        	}

        	for(int i = 1; i < 4; i++)
    		{
    			if(recVertice[i].x < arr[0].x)
    			{
				// min of x
    				arr[0] = recVertice[i];	
    			}
    		}

    		for(int i = 1; i < 4; i++)
    		{
    			if(recVertice[i].y < arr[2].y)
    			{
				// min of y
    				arr[2] = recVertice[i]; 
    			}
    		}

    		for(int i = 1; i < 4; i++)
    		{
    			if(recVertice[i].x > arr[1].x)
    			{
				// max of x
    				arr[1] = recVertice[i]; 
    			}
    		}

    		for(int i = 1; i < 4; i++)
    		{
    			if(recVertice[i].y > arr[3].y)
    			{	
				// max of y
    				arr[3] = recVertice[i]; 
    			}
    		}

    		return arr;
		}
	
	Vertex *diagonalPoints()
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
	
	Vertex* getCrossVertex()
   	{
      		return crossV;
	}
	virtual double computeArea();
	virtual bool isPointInShape (int x , int y);
	virtual bool isPointOnShape (int x , int y);
	virtual void printPoints();
	
	std::string toString();	
	
	void findHorizonRec();
 	void findVerticalRec();
	void pointsOnRec();
	void pointsOnShape();
	void pointsinRectangle();
	void pointsInShape();
	void setVertices(Vertex* arr);
};


#endif
