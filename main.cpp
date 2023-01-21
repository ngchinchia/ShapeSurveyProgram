#include <iostream>
#include "ShapeTwoD.h"
#include "Square.h"
#include "Rectangle.h"
#include "Cross.h"
#include "Circle.h"
#include "Assn2.h"

using namespace std;

int main() {
  
  Assignment2 obj("7058901","Ng Chin Chia");
  char option;

  do
  {
    option=obj.printMenu();

    if(option == '1')
    {
    	obj.inputSensor();
    }
    else if(option == '2')
    {
     	obj.computeAreas();
	
    }
    else if(option == '3')
    {	
     	obj.printsReport();
    
	
    }
    else if(option == '4')
    {
     	obj.sortData();
    }
    else if(option == '5')
    {
      break;
    }
    else 
    {
	    cout<<"Input only 1-5!"<<endl;
    }
  }
while(option!=5);

}
