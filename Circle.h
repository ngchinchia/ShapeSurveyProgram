#ifndef CIRCLE_H
#define CIRCLE_H
#include "ShapeTwoD.h"


class Circle: public ShapeTwoD
{

private:
	Vertex circleVertex;
    	int radius;

public:
	Circle(std::string n,bool type,int rad):ShapeTwoD(n,type)

    	{
      		radius = rad;
    	}
	Vertex getCrossVertex()
   	 {

	      return circleVertex;
	  }
	virtual double computeArea ();
	std::string toString();
	virtual bool isPointInShape (int x , int y);
	virtual bool isPointOnShape (int x , int y);
	void pointsInShape();
	void pointsOnShape();
	virtual void printPoints();
	void setVertices(Vertex* cv);
	void setRadius(int r);
	int getRadius();

};



#endif
