//For Function Implementations,so only prototypes defined in class header file
#include"TopSpin.h"
#include <iostream>
using namespace std;
#include<ctime>


TopSpin::TopSpin(int size, int spinSize)// Main and only Constructor
{
	if (!((size >= 1) && (spinSize <= size)))// Checking the parameters passed in, if size less than one or spinSize is greater than size, setting default values of 20 and 4 respectively.
	{
		TopSpin::size1 = 20;
		TopSpin::spinSize1 = 4;
	}

	else// If parameters are valid, then assign them to their respective member variables within class TopSpin
	{
		TopSpin::size1 = size;
		TopSpin::spinSize1 = spinSize;
	}
for (int x = 1; x <= size; x++)// This is now creating the circular double linked list and adding elements into the list from 1 to size using the add data method within class CDLL for member variable gboardw (a CDLL object) of class TopSpin.
{
	gboardw.addData(x);
}

}

void TopSpin::random(unsigned int times)// This function is randomizing the list before puzzle solving begins
{
	for (int y=1; y<=times;y++)// This is so the following method of disfiguring is done the number of times that is passed in the parameter through a for loop
	{
	srand(time(NULL));
	unsigned int randnum= 1 + rand() % 19;   // formula for creating random positive integers from 1-19 using the srand, time as reference to computer clock to make it random each time program is restarted/repeated
	
	for (int x = 1; x <= randnum; x++)// Now this shifts the list to the left random number of times that was created above
	{
		shiftLeft();
	}
	spin();// This is in the bigger loop, so does it once for one run and does the number of times that passed from the user.
	}
}

void TopSpin:: shiftLeft()// A method of shiftLeft means it decrements head of member variable- the CDLL object gboardw
{
	gboardw.decrementHead();
}

void TopSpin::shiftRight()// A method of shiftRight means it increments head of member variable- the CDLL object gboardw
{
	gboardw.incrementHead();
}

void TopSpin::spin()//A method of shiftRight means it swaps all the elements in the circular double linked list of member variable (of TopSpin)- the CDLL object gboardw
{
	int x = 0;// This is a temporary variable initialized at 0, used to subtract from spinSize1 to get to the last, second last and so on.
	for (int i = 1; i<=((spinSize1)/2);i++)// This swap loops only till the middle of the list or else if it goes through the whole list, all elements reswapped back to their original place (hence /2)
	{
		gboardw.swap(i, spinSize1-x);//This is just swapping the first element and the last, second & second last and so on till the middle.
		x++;
	}

	}


bool TopSpin:: isSolved()
{
	int w=1;//Initialized outside the scope of the for loop to still retrive it outside and use it for the next for loop. This finds what nth element in the list has 1.
	while (!(gboardw.getData(1) == 1)) // This loop is trying to find 1 and shifts right until then. And then that becomes its head.
	{
		shiftRight();
		w++;

	}
	
	for (int i = 1; i < size1;i++)// Once everthing has been shifted right so the list starts with 1 as its first element which means every element after must 2,3,4.. in order.
	{
		
		if (gboardw.getData(i) == i){}// This is checking if each element is equal to its node, so first node =1 and 2 3 and so on. Checking if list is in order. Loops for each element in the list.
		else// If even one node doesn't have the correct element inside, not in order so. it does the following.
		{
			for (int f=1; f<w; f++)// This loop is to shift the list left back to the original using the counter w to know how many times shifted right, just undoing that.
			{
				shiftLeft();
			}
			return 0;// As soon as it enters the else agrument that one element is not in order, the list/game is not solved so it returns 0 as false for this bool function which we can print and indicate in main.
		}
		
	}
	return 1;
}



TopSpin::~TopSpin()//Deconstructor 
{
}


ostream& operator<< (ostream& os, const TopSpin& ts)// This is the overloading operator, that defines what it means to print the object of TopSpin
{
	
		//For the TOP LINE in the SpinSize Window
		os << "| ";// Starts with the left hand side line with a space

		for (int g = 1; g <= ts.spinSize1; g++)// for each element's equivalent, it assigns 3 dashes on the top
		{
			os << "---";
		}
			os << " |" << endl;//And finishes with a space and a right hand side line.


	
		//MIDDLE
		os << "|  ";// Same as Top Line but with two spaces after
		for (int k = 1; k <= ts.spinSize1; k++)// After the right hand size line, this loops goes and outputs each element it list with a condition
			// that if the number is a single digit, it outputs the number and one space. and if it is two digits, outputs 2 spaces
		{
			if (ts.gboardw.getData(k)>9)
			os << ts.gboardw.getData(k) << " ";
			else
			os << ts.gboardw.getData(k) << "  ";
		}
		os << "|";// This is for the end of the line
		for (int i = ts.spinSize1; i < ts.size1; i++)// This loops through all the elements inside the list but is outside the spinsize window.
		{
			os << ts.gboardw.getData(i + 1) << " ";// For non-window
		}
		os << endl;
		

	
		//Bottom: Exactly same as top line
		os << "| ";
		for (int t = 1; t <= ts.spinSize1; t++)
		{
			os << "---";
		}
			os << " |";
	
	
	
	
	return os;
}
