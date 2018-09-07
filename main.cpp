#include<iostream>
#include"TopSpin.h"
#include "CDLL.h"
#include<ctime>
using namespace std;

void errorchecking(int input, int min, int max);


int main()
{
	cout << "Welcome to the TopSpin Game!" << endl;
	TopSpin Cozo(20, 4);// Creating a top spin object and passing 20 as the full board game and 4 as the spin window. Calling the only constructor
	cout << Cozo << endl;//Displaying and Outputing the game board of the TopSpin object just created.
	
	int a = 0;
	cout << "How many random moves would you like the puzzle to be disfigured into?" << endl;
	cin >> a;
	if (a <= 0)
		cout << "Please input a number greater than zero" << endl;
	Cozo.random(a);// Assigning the user's input to the random function
	cout << Cozo << endl;// Outputs the game board after being jumbled and randomized



	int b = 0;
	while (!(b == 3))// The user's menu of moves are in this loop constantly until the user chooses quit.
	{
		cout << endl;//
		if (Cozo.isSolved() == 1)//Checks if the board is solved everytime in enters this loop after all the menus
		{
			cout << endl<<"CONGRATULATIONS! you have solved this puzzle" << endl;
			return 0;// Exits the program
		}
		cout << "Please choose from the following options enter your choice by entering the corresponding number : " << endl
			<< "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
		cin >> b;
		errorchecking(b, 1, 3);//Function that sees if input is between 1 and 3, if not asks for input again.

		if (b == 1)// If b=1, it goes into shift menus of which direction and how many times.
		{
			int d;
			cout << "To Shift left choose 1 and to shift right choose 2" << endl;
			cin >> d;
			errorchecking(d, 1, 2);

			int f;
			cout << "Now how many times do you want to shift in this direction: " << endl;
			cin >> f;
			if (f <= 0)
				cout << "Please input a number greater than zero" << endl;
			if (d == 1)//For choice 1 of shifting left, f input number of times
			{
				for (int i = 1; i <= f; i++) {
					Cozo.shiftLeft();
				}
			}
			else//For choice 2 of shifting right, f input number of times
			{
				for (int i = 1; i <= f; i++) {
					Cozo.shiftRight();
				}
			}
			cout << Cozo;//Displaying it after the complete shift to show result
			
		}

		else if (b == 2)//If input b=2, then spin and calls the spin function
		{
			Cozo.spin();
			cout << Cozo;
		
		}
	}
}



void errorchecking(int input, int min, int max)// Created a custom error checking function that takes user input, the minimum choice option and max choice option, in order to define what the user's range of inputs can be and loops to enter again if not.
{
	int c;
	while (!((input <= max) && (input >= min)))
	{
		cout << "Please enter a choice with in the boundaries provide: " << endl;
		cin >> c;
		input = c;
	}
}

