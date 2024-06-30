/*
* Author: Grace Fletcher
* Class: CS 210
* Program: Airgead Banking App
* Date: June 9th, 2024
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// Declares variables for input
	float initialInvestment, monthlyDeposit, annualInterest, months, years;

	// Declares variables to store year end total amount, interest, and year end interest
	float totalAmount, interestAmount, yearlyTotalInterest;

	// Displays the menu to the user
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	// Gets user input
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $" << endl;
	cin >> initialInvestment;
	cout << "Monthly Deposit: $" << endl;
	cin >> monthlyDeposit;
	cout << "Annual Interest: %" << endl;
	cin >> annualInterest;
	cout << "Number of years: " << endl;
	cin >> years;
	months = years * 12;

	// Updates the total amount to initial investment
	totalAmount = initialInvestment;

	// Displays year end data if there are no no monthly deposits
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// Calculates the yearly interest and year end total
	for (int i = 0; i < years; i++) {
		// Calculates yearly interest amount
		interestAmount = ((totalAmount) * (annualInterest / 100));

		// Calculates year end total
		totalAmount = totalAmount + interestAmount;

		// Shows decimal as dollar amount with a set precision of 2
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}

	// Calculates the monthly interest and month end total
	totalAmount = initialInvestment;

	// Displays the year end data with monthly deposits
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	// Calculates the yearly interest and year end total
	for (int i = 0; i < years; i++) {
		// Initializes yearly interest to 0
		yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			// Calculates monthly interest amount
			interestAmount = (((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12);

			// Calculates month end interest
			yearlyTotalInterest = yearlyTotalInterest + interestAmount;

			// Calculates month end total
			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}

		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearlyTotalInterest << endl;
	}
	return 0;
}