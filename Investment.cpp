/* 
Investment.cpp

Date: November 28, 2021
Author: Andreas Galatis
*/

#include "Investment.h"
#include<iostream>
#include<iomanip>

using namespace std;

double userAmt;
double userDep;
double userInt;
int userYears;

double earnedInt;
double closingBal;
double compoundInt;

// Constructor
Investment::Investment(double m_investAmt, double m_monthlyDep,
	double m_yearlyInt, int m_totalYears) {

	this->m_investAmt = m_investAmt;
	this->m_monthlyDep = m_monthlyDep;
	this->m_yearlyInt = m_yearlyInt;
	this->m_totalYears = m_totalYears;
}

// Mutators
void Investment::SetInvestAmount(double t_userAmt) {
	m_investAmt = t_userAmt;
}

void Investment::SetMonthlyDep(double t_userDep) {
	m_monthlyDep = t_userDep;
}
void Investment::SetYearlyInt(double t_userInt) {
	m_yearlyInt = t_userInt;
}

void Investment::SetTotalYears(int t_userYears) {
	m_totalYears = t_userYears;
}

// Accessors
double Investment::GetInvestAmount() {
	return m_investAmt;
}

double Investment::GetMonthlyDep() {
	return m_monthlyDep;
}

double Investment::GetYearlyInt() {
	return m_yearlyInt;
}

int Investment::GetTotalYears() {
	return m_totalYears;
}

// Function to calculate earned interest 
double Investment::earnedInterest(int t_years, double t_deposit) {
	closingBal = GetInvestAmount();
	earnedInt = 0;
	compoundInt = 0;
	for (unsigned j = 1; j < t_years + 1; ++j) {
		earnedInt = 0;
		for (unsigned i = 1; i < 12 + 1; ++i) {
			compoundInt = (closingBal + t_deposit) * ((GetYearlyInt() / 100) / 12);
			closingBal = (closingBal + t_deposit) + compoundInt;
			earnedInt = compoundInt + earnedInt;
		}
	}
	return earnedInt;
}

// Function to calculate closing balance
double Investment::closingAmount(int t_years, double t_deposit) {
	closingBal = GetInvestAmount();
	earnedInt = 0;
	compoundInt = 0;
	for (unsigned i = 1; i < (t_years * 12) + 1; ++i) {
		compoundInt = (closingBal + t_deposit) * ((GetYearlyInt() / 100) / 12);
		closingBal = (closingBal + t_deposit) + compoundInt;
	}
	return closingBal;
}



// Function to print balance sheets
void Investment::printData(int t_years) {
	
	// Print balance sheet Without monthly deposit
	cout << setfill(' ') << setw(15) << ' ' <<
		"Balance and Interest without additional monthly deposits" <<
		setfill(' ') << setw(15) << ' ' << endl;
	cout << setfill('=') << setw(90) << '=' << endl;
	cout << setfill (' ') << setw(10) << "Year";
	cout << setw(30) << "Year End Balance";
	cout << setw(40) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(90) << '-' << endl;

	for (unsigned i = 1; i < (t_years+1); ++i) {
		cout << setfill(' ') << setw(10) << i << ' ';
		cout << right << setw(30) << fixed << setprecision(2) << closingAmount(i, 0);
		cout << right << setw(40) << earnedInterest(i, 0) << endl;
	}
	cout << endl; 

	// Print balance sheet with monthly deposit included
	cout << setfill(' ') << setw(15) << ' ' <<
		"Balance and Interest with additional monthly deposits" <<
		setfill(' ') << setw(15) << ' ' << endl;
	cout << setfill('=') << setw(90) << '=' << endl;
	cout << setfill(' ') << setw(10) << "Year";
	cout << right << setw(30) << "Year End Balance";
	cout << right << setw(40) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(90) << '-' << endl;

	for (unsigned i = 1; i < (GetTotalYears() + 1); ++i) {
		cout << setfill(' ') << right << setw(10) << i << ' ';
		cout << right << setw(30) << closingAmount(i, GetMonthlyDep());
		cout << right << setw(40) << earnedInterest(i, GetMonthlyDep()) << endl;
	}
}