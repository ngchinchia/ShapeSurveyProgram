#include <iostream>
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cross.h"
#include "Assn2.h"

using namespace std;

Assignment2::Assignment2(string studID, string studName)
    {
      studentID = studID;
      studentName = studName;
      Idx = 0;
    }

int Assignment2::printMenu()
    {
      cout<<endl<<endl;
      cout<<"Student ID: "<<studentID<<endl;
      cout<<"Student Name: "<<studentName<<endl;
      cout<<"-----------------------------------------" <<endl;

      cout<<"Welcome to Assn2 program!"<<endl<<endl;
      cout<<"1) \tInput sensor data \n2) \tCompute area (for all records) \n3) \tPrint shapes report \n4) \tSort shape data \n5) \tPress 5 to quit"<<endl<<endl;

      cout<<"Please enter your choice: ";
      char option;
      cin>>option;

      return option;
    }

void Assignment2::inputSensor()
    {
      string name,stype;
      bool returnAs;
      int numOfVertices = 0;
      int r=0;
      try
      {		
      	cout<<"\n[Input Sensor Data]"<<endl;
      	cout<<"Please enter name of shape : "; cin>>name;
      	
		if(!(name == "Circle" or name == "circle" or name == "Rectangle" or name == "rectangle" or name == "square" or name == "Square" or name == "Cross" or name == "cross" ))
		throw exception();

      	cout<<"Please enter special type : "; cin>>stype;
      	if(!(stype=="WS" or stype=="ws" or stype=="NS" or stype=="ns"))
		throw exception();

      	if(stype=="WS" or stype =="ws")
        	returnAs = true;
      	else
       		returnAs = false;

      	if(name == "Cross" or name == "cross")
      	{
       		arr[Idx] = new Cross(name,returnAs);
     		numOfVertices = 12;
      	}
      	else if(name == "Rectangle" or name == "rectangle")
      	{
        	arr[Idx] = new Rectangle(name,returnAs);
        	numOfVertices = 4;
      	}
      	else if(name == "Square" or name == "square")
      	{
        	arr[Idx] = new Square(name,returnAs);
        	numOfVertices = 4;
      	}
      	else if(name == "Circle" or name == "circle")
      	{
			numOfVertices = 1;
      	}

       Vertex* vertices = new Vertex[numOfVertices];

      	for(int i=0; i<numOfVertices; i++)
      	{
        	Vertex vt;
			if (name=="Circle" or name == "circle")
			{
		        cout<<"Please enter x-ordinate of center: "; cin>>vt.x;
				if(vt.x<0)
				throw exception();
				cout<<"Please enter y-ordinate of center: "; cin>>vt.y;
				if(vt.y<0)
				throw exception();
				cout<<"Please enter radius of circle: "; cin>> r;
				arr[Idx] = new Circle(name,returnAs,r);
			}
			else
			{
        		cout<<"Please enter x-ordinate of pt."<<i+1 <<": "; cin>>vt.x;
				if(vt.x<0)
				throw exception();
				cout<<"Please enter y-ordinate of pt."<<i+1 <<" : "; cin>>vt.y;
				if(vt.y<0)
				throw exception();
			}

        	vertices[i] = vt;
      	}
    
      arr[Idx]->setVertices(vertices);
      cout<<"\nRecord Successfully stored. Going back to main menu...\n\n";
      Idx++;
 
	}
	catch(exception)
	{
		cerr<<"Incorrect input is detected,please key in a valid input"<<endl;
		inputSensor();
	}

 }

void Assignment2::computeAreas()
    {
    	for(int i=0; i<Idx;i++)
    	{
    		arr[i]->computeArea();
    	}

    	cout << "Computation completed! ( "<< Idx << " records were updated )" << endl;
    }


void Assignment2::printsReport()
    {
	
    	for(int i=0; i<Idx;i++)
    	{
    		cout << "Shape[" << i << "]\n" << arr[i]->toString() << endl;
		
    		arr[i]->printPoints();
    		cout << endl;

    	}
    }

void Assignment2::sortData()
    {
		cout<<"\ta) Sort by area (ascending) \n\tb) Sort by area (descending) \n\tc) Sort by special type and area\n"<<endl;
		cout<<"Please select sorting option (press q to go main menu): ";
		char option;
		cin>>option;

		if(option == 'a')
		{
			cout << "\nSorting by area (from smallest to largest)...\n";

			int tempOne;
			int tempTwo;

			int idxNum[Idx] = {0};
			int aSort[Idx] = {0};
			for(int i=0; i< Idx; i++)
			{
				idxNum[i] = i;
				aSort[i] = arr[i]->getArea();

			}

			for(int i=0; i<Idx;i++)
			{
				for(int j = i+1; j < Idx; j++)
				{
					if(aSort[i] > aSort[j])
					{
						tempOne = aSort[i];
						aSort[i] = aSort[j];
						aSort[j] =tempOne;

						tempTwo = idxNum[i];
						idxNum[i] = idxNum[j];
						idxNum[j] = tempTwo;

					}
				}
			}


			for(int i=0; i<Idx;i++)
			{

				cout << "Shape[" << i << "]\n" << arr[idxNum[i]]->toString() << endl;
				arr[idxNum[i]]->printPoints();
				cout << endl;

			}


		}

		else if(option == 'b')
		{
			cout << "\nSorting by area (from largest to smallest)...\n";

			int tempOne;
			int tempTwo;

			int idxNum[Idx] = {0};
			int aSort[Idx] = {0};
			for(int i=0; i< Idx; i++)
			{
				idxNum[i] = i;
				aSort[i] = arr[i]->getArea();

			}

			for(int i=0; i<Idx;i++)
			{
				for(int j = i+1; j < Idx; j++)				{

					if(aSort[i] < aSort[j])
					{
						tempOne = aSort[i];
						aSort[i] = aSort[j];
						aSort[j] = tempOne;

						tempTwo = idxNum[i];
						idxNum[i] = idxNum[j];
						idxNum[j] = tempTwo;

					}
				}
			}


			for(int i=0; i<Idx;i++)
			{
				cout << "Shape[" << i << "]\n" << arr[idxNum[i]]->toString() << endl;
				arr[idxNum[i]]->printPoints();
				cout << endl;
			}

		}
		else if(option == 'c')
		{
			cout << "\nSort by special type and area\n";
			double max;
			ShapeTwoD* temp;
			int tempOne;
			int tempTwo;
			int aSort[Idx] = {0};
			int idxNumbering[Idx] = {0};
			bool type[Idx];
			for(int i=0; i< Idx; i++)
			{
				idxNumbering[i] = i;
				type[i] = arr[i]->getContainsWarpSpace();
			}

			for(int i=0; i<Idx;i++)
			{
				if(arr[i]->getContainsWarpSpace()!=true)
			{
				for(int j = i+1; j < Idx; j++)
				{
					if(arr[j]->getContainsWarpSpace()==true)
					{
						
						temp= arr[i];
						arr[i] = arr[j];
						arr[j] = temp;

			
					}
				}
			}
}
			for(int i=0; i<Idx;i++)
			{
				max=arr[i]->getArea();
			
				if(arr[i]->getContainsWarpSpace()==true)
				{
				 
					for(int j=i+1;j<Idx;j++)
					{
						if(arr[j]->getArea()>max && arr[j]->getContainsWarpSpace()==true)
						{
							max=arr[j]->getArea();
							temp=arr[j];
							arr[j]=arr[i];
							arr[i]=temp;

					
						}
					}
				}
		}


			for(int i=0; i<Idx;i++)
			{
				if(arr[i]->getContainsWarpSpace()==false)
				
				{
					max=arr[i]->getArea();		 	
					for(int j=i+1;j<Idx;j++)
					{
						if(arr[j]->getArea()>max && arr[j]->getContainsWarpSpace()==false)
						{
							max=arr[j]->getArea();
							temp=arr[j];
							arr[j]=arr[i];
							arr[i]=temp;


						}
					}
				}
		}					
		
		
			for(int i=0; i<Idx;i++)
			{

				cout << "Shape[" << i << "]\n" << arr[i]->toString() << endl;
				arr[i]->printPoints();

			}
		}
		else if(option == 'q')
		{
			option = '\0';
			return;
		}

		option = '\0';
  }
