#ifndef SHAPETWOD_H
#define SHAPETWOD_H
#include <string>
#include <sstream>

struct Vertex
{
  int x;
  int y;

  Vertex()
  {
    x=0;
    y=0;
  }
  Vertex(int a, int b)
  {
	  x = a;
	  y = b;
  }

  std::string toString()
  {
    std::string empString = "(";

    std::stringstream ss;
    ss << x;
    empString += ss.str() + ",";
    std::stringstream ss1;
    ss1<<y;
    empString += ss1.str() + ")";

    return empString;
  }

};

class ShapeTwoD
{
  protected:
   std::string name;
   bool containsWarpSpace;
   double area;
  public:
	ShapeTwoD (std::string n,bool cws);
   	virtual double computeArea ()=0;
   	virtual void printPoints()=0;
   	virtual bool isPointInShape (int x , int y)=0;
   	virtual bool isPointOnShape (int x , int y)=0;
    virtual void setVertices(Vertex* v) =0;
	virtual std::string toString();
	bool getContainsWarpSpace ();
	std::string getName ();
	void setName (std::string toSetName);
	void setContainsWarpSpace (bool toSetWarpSpace);
	int getArea();

	float round(float var);
};


#endif
