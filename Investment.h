/*
Investment.h

Date: November 28, 2021
Author: Andreas Galatis
*/

#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <string>

using namespace std;

class Investment {
public:
	Investment(double m_investAmt = 0.0, double m_monthlyDep = 0.0,
		double m_yearlyInt = 0.0, int m_totalYears = 0);

	// Mutator functions
	void SetInvestAmount(double m_investAmt);
	void SetMonthlyDep(double m_monthlyDep);
	void SetYearlyInt(double m_yearlyInt);
	void SetTotalYears(int m_totalYears);

	// Accessor functions
	double GetInvestAmount();
	double GetMonthlyDep();
	double GetYearlyInt();
	int GetTotalYears();

	// Calculation and printing functions
	double closingAmount(int t_years, double t_deposit);
	double earnedInterest(int t_years, double t_deposit);
	void printData(int t_years);
	

private:
	double m_investAmt;
	double m_monthlyDep;
	double m_yearlyInt;
	int m_totalYears;

};

#endif

