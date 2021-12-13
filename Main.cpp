/*
Main.cpp

Date: November 28, 2021
Author: Andreas Galatis
*/

#include <iostream>
#include "Investment.h"
#include <iomanip>
#include <limits>

using namespace std;

int main() {

	double userAmt;
	double userDep;
	double userInt;
	int userYears;
	bool inputVal = false;
	char userChar = 'n';
	
	// Initialized new Investment class type
	Investment userInvestment;
	
	// Main loop for user input and validation
	LOOP: while (userChar == 'n') {
		system("CLS");

		// Print initial display title;
		cout << setfill('*') << setw(42) << '*' << endl;
		cout << setfill('*') << setw(15) << '*' << " DATA INPUT ";
		cout << setfill('*') << setw(15) << '*' << endl;

		// First block to input investment amount
		cout << "Enter initial investment ammount: $";
		cin >> userAmt;
		// Used while loop for input validation
		while (inputVal == false) {
			if ((userAmt < 0) || cin.fail()) {
				cout << "Error: Amount must be a positive number" << endl;
				cout << "Please re-enter initial investment ammount: $";
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin >> userAmt;
			}
			else inputVal = true;
		}
		// Set investment amount with mutator function
		userInvestment.SetInvestAmount(userAmt);

		// Second input block for deposit amount
		inputVal = false;
		cout << "Enter monthly deposit amount: $";
		cin >> userDep;
		// While loop for input validation
		while (inputVal == false) {
			if ((userDep < 0) || cin.fail()) {
				cout << "Error: Amount must be a positive number" << endl;
				cout << "Please re-enter monthly deposit amount: $";
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin >> userDep;
			}
			else inputVal = true;
		}
		// Set deposit amount with mutator function
		userInvestment.SetMonthlyDep(userDep);

		// Third input block for interest rate
		inputVal = false;
		cout << "Enter annual interest rate: %";
		cin >> userInt;
		// Used while loop for input validation
		while (inputVal == false) {
			if ((userInt < 0) || cin.fail()) {
				cout << "Error: Amount must be a positive number" << endl;
				cout << "Please re-enter annual interest rate: $";
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin >> userInt;
			}
			else inputVal = true;
		}
		// Set yearly interest rate with mutator function
		userInvestment.SetYearlyInt(userInt);

		// Fourth input block for number of years
		inputVal = false;
		cout << "Enter number of years: ";
		cin >> userYears;
		// Used while loop for input validation
		while (inputVal == false) {
			if ((userYears < 0) || cin.fail()) {
				cout << "Error: Amount must be a positive number" << endl;
				cout << "Please re-enter number of years: $";
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin >> userYears;
			}
			else inputVal = true;
		}
		//Set number of years using mutator function 
		userInvestment.SetTotalYears(userYears);
		cout << endl;

		// Display entered amounts
		cout << "You entered: " << endl;
		cout << "Initial investment ammount: $" << userAmt << endl;
		cout << "Monthly deposit amount: $" << userDep << endl;
		cout << "Annual interest rate: %" << userInt << endl;
		cout << "Number of years: " << userYears << endl;

		cout << endl;

		// Option for user to change entered values
		inputVal = false;
		cout << "Would you like to enter new data?" << endl;
		cout << "Enter 'y' to input new data or 'n' to see the results" << endl;
		cin >> userChar;
		// while loop to validate input
		while (inputVal == false) {
			if (userChar == 'y') {
				userChar = 'n';
				inputVal = true;
				goto LOOP;
			}
			// Call to function that prints data results if user selects not to change values
			else if (userChar == 'n') {
				userInvestment.printData(userYears);
				inputVal = true;
			}
			else {
				cout << "Error: Please enter 'y' to input new data or 'n' to see the results: ";
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin >> userChar;
			}
		}
		
		// Option for user to enter new data after seeing initial results
		inputVal = false;
		cout << "\n\nWould you like to enter new data?" << endl;
		cout << "Enter 'y' to input new data or 'n' to exit: ";
		cin >> userChar;
		// While loop to validate input
		while (inputVal == false) {
			if (userChar == 'y') {
				userChar = 'n';
				inputVal = true;
				continue;
			}
			else if (userChar == 'n') {
				userChar = 'y';
				cout << "Thank you, Good-bye \n \n";
				inputVal = true;
				break;
			}
			else {
				cout << "Error: Please enter 'y' to input new data or 'n' to exit: ";
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin >> userChar;
			}
		}

	}
}