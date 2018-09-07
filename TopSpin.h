//Circular Linked list, the previous element to the first element is now referencing the last element and the successor tot he 
//Remember where the viewing window (the subset smaller) starts which node, which element. So find a way to modify so the head pointss tot hat node.

#include<iostream>
using namespace std;
#include "TopSpinADT.h"
#include "CDLL.h"
class TopSpin :public TopSpinADT
{
private:
	int size1;
	int spinSize1;
	CDLL<int> gboardw;// A CDLL object as a member variable of TopSpin to record the gameboard, create a circular double linked list
public:
	TopSpin(int size, int spinSize);//Main Constructor 

	void random(unsigned int times);
	// shifts the pieces 1 to the left
	void shiftLeft();
	//shifts the pieces 1 to the right
	void shiftRight();
	//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
	// 1,4,3,6 we will have 6,3,4,1
	void spin();
	//checks to see if the puzzle is solved that is to say the pieces are in numerical order 1 - 20
   bool isSolved();

	
	~TopSpin();//Destructor
	

	
	
	friend ostream& operator<< (ostream& os, const TopSpin& ts);// Prototype of the overloading operator
	
};

 
