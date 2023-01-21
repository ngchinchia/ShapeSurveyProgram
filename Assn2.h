#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H
#include "ShapeTwoD.h"

class Assignment2
{

private:
  	std::string studentID;
  	std::string studentName;
  	ShapeTwoD* arr[1000];
  	int Idx;

public:
	Assignment2(std::string studID, std::string studName);
	int printMenu();
	void inputSensor();
	void computeAreas();
	void printsReport();
	void sortData();

};
#endif
