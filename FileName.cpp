/*
Zachary Leyes

5/22/2023

Sorting and Searching Arrays
*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;


void loadArrays(string[], double[], int&);
void showArrays(string[], double[], int);
void lookUpPrice(string[], double[], int);
void sortPrices(string[], double[], int);
void highestPrice(string[], double[], int);
int showMenu();
void swap(double[], int, int);

const int SIZE = 30;

int main()
{
	int selection;
	int go = 1;
	string consoleNames[SIZE];
	double  consolePrices[SIZE];
	int numOfConsoles;

	//Function to read values from a file into parallel arrays
	loadArrays(consoleNames, consolePrices, numOfConsoles);

	//Displays a menu and asks user for a selection then executes the correct function depending on their choice 
	do {
		selection = showMenu();
		if (selection == 1)
		{
			showArrays(consoleNames, consolePrices, numOfConsoles);
		}
		if (selection == 2)
		{
			lookUpPrice(consoleNames, consolePrices, numOfConsoles);
		}
		if (selection == 3)
		{
			sortPrices(consoleNames, consolePrices, numOfConsoles);
		}
		if (selection == 4)
		{
			highestPrice(consoleNames, consolePrices, numOfConsoles);
		}
		if (selection == 5)
		{
			go = 5;
		}


	} while (go == 1);

}

int showMenu()
{
	int selection;
	//Display menu
	cout << "Console Pricing - Main Menu";
	cout << endl << "1. Display all console prices";
	cout << endl << "2. Look up the price of particular console";
	cout << endl << "3. Sort prices in descending order";
	cout << endl << "4. Display the console with the highest price";
	cout << endl << "5. Exit the program" << endl << endl;

	//Gets user input and validates that the input recieved is between 1 and 5
	cin >> selection;
	while (selection > 5 || selection < 1)
	{
		cout << "Please enter a valid response 1-5" << endl << endl;
		cin >> selection;
	}

	//Returns user return input to main
	return selection;
}


void loadArrays(string consoleNames[], double consolePrices[], int& numOfConsoles)
{
	//Creates file object 
	ifstream inputFile;

	//Links the file object and opens the file
	inputFile.open("C:\\Users\\zachary.leyes.SCC-NT\\OneDrive - Sinclair Community College\\Documents\\C++Dev\\prices.txt");

	//Displays error message if the file was not loaded
	if (!inputFile)
	{
		cout << "Your file did not load :(" << endl << endl;

	}

	
	numOfConsoles = 0;

	//Temporary stores the console name from the file (because of getline and files)
	string line;

	//Reads the file and stores them in parallel arrays
	while (numOfConsoles < SIZE && getline(inputFile, line))
	{
		consoleNames[numOfConsoles] = line;
		inputFile >> consolePrices[numOfConsoles];

		inputFile.ignore();

		numOfConsoles++;
	}

	//Closes the file
	inputFile.close();
}


void lookUpPrice(string consoleNames[], double consolePrices[], int numOfConsoles)
{
	string search;
	int found = -1;

	cin.ignore();

	cout << endl << "Console Name?  ";
	getline(cin, search);

	for (int x = 0; x < numOfConsoles && found == -1; x++)
	{
		if (search == consoleNames[x])
		{
			cout << setprecision(2) << fixed;
			cout << endl << "The current price for " << consoleNames[x] << " is $" << consolePrices[x] << endl << endl;
			found = 1;
		}
		cout << "meep" << endl;

	}

	if (found == -1)
	{
		cout << "The console name provided has no matches" << endl << endl;
	}

}


void showArrays(string consoleNames[], double consolePrices[], int numOfConsoles)
{
	cout << endl << endl << "Console" << setw(48) << "Price";
	for (int x = 0; x < numOfConsoles; x++)
	{
		cout << setprecision(2) << fixed;
		cout << endl << left << setw(50) << consoleNames[x];
		cout << consolePrices[x];
		cout << right;
	}

	cout << endl << endl;

}


void sortPrices(string consoleNames[], double consolePrices[], int numOfConsoles)
{



	for (int y = 0; y < numOfConsoles; y++)
	{
		for (int x = y + 1; x < numOfConsoles; x++)
		{

			if (consolePrices[x] > consolePrices[y])
			{
				swap(consolePrices, x, y);
			}


		}
	}
}

void highestPrice(string consoleNames[], double consolePrices[], int numOfConsoles)
{
	double highestPrice = 0;
	string highestPrcieName;


	for (int x = 0; x < numOfConsoles; x++)
	{
		if (highestPrice == 0 || highestPrice < consolePrices[x])
		{
			highestPrice = consolePrices[x];
			highestPrcieName = consoleNames[x];
		}
	}

	cout << setprecision(2) << fixed;
	cout << endl << "The " << highestPrcieName << " has the highest price of $" << highestPrice << endl << endl;

}


void swap(double consolePrices[], int x, int y)
{
	int temp = consolePrices[y];
	consolePrices[y] = consolePrices[x];
	consolePrices[x] = temp;
}