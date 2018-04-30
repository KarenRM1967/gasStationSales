#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

/**********************************************
Karen Rees-Milton
Section number 105
COMP1100 Assignment2
A program to produce a 
***********************************************/

int main()
{
	//housekeeping: Declare variables, open files

	string customerName;
	char gasType;
	double numberOfLitres, salesAmount, gasolinePrice, totalSales = 0., averageSales;
	int noSales = 0;

	ofstream fout("gas.rpt");

	if (!fout.is_open())
	{
		cout << "Error: Unable to open file";
		system("pause");
		exit(666);
	}

	//Input: Obtain prime read, begin while loop, print titles, obtain and validate more data

	cout << "Enter customer name or ctrl Z to end: ";
	getline(cin, customerName);
	if (cin.eof())
	{
		cout << "Program was ended by user" << endl;
	}
	while (!cin.eof())
	{
		noSales++;
		if (noSales == 1)
		{
			fout << fixed;
			fout << left << setw(20) << "Customer Name"
				<< setw(20) << "Type of Gasoline"
				<< right << setw(15) << "Price/Litre"
				<< setw(15) << "# of Litres"
				<< setw(15) << "Sales Amount" << endl << endl;
		}

		cout << "Enter litres of gas: ";
		cin >> numberOfLitres;
		while (cin.fail() || numberOfLitres < 0 || numberOfLitres > 100)
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Error. Litres of gas must be a number between 0 and 100 only. Re-enter: ";
			cin >> numberOfLitres;
		}

		cout << "Enter type of gas: ";
		cin >> gasType;
		gasType = toupper(gasType);
		while (gasType != 'R' && gasType != 'D' && gasType != 'P')
		{
			cout << "Error. Gas type can only be R(regular), D(diesel) or P(propane)"
				<< endl << "Re-enter: R, D or P: ";
			cin >> gasType;
			gasType = toupper(gasType);
		}

		//Processing: Code nested if, arithmetic

		if (gasType == 'R')
		{
			gasolinePrice = 1.28;
		}
		else if (gasType == 'D')
		{
			gasolinePrice = 1.08;
		}
		else
		{
			gasolinePrice = 2.50;
		}

		salesAmount = numberOfLitres * gasolinePrice;
		totalSales += salesAmount;

		//output: Print data to file, get next data, end while loop

		fout << left << setw(20) << customerName
			<< setw(20) << gasType
			<< right << setprecision(2) << setw(15) << gasolinePrice
			<< setprecision(1) << setw(15) << numberOfLitres
			<< setprecision(2) << setw(15) << salesAmount << endl << endl;

		cin.ignore(80, '\n');
		cout << "Enter customer name or ctrl Z to end: ";
		getline(cin, customerName);
	}
	//Calculate and print average sales, print total sales and customers
	if (noSales > 0)
	{
		averageSales = totalSales / noSales;
		fout << left << setw(25) << "Total sales"
			<< right << setw(60) << totalSales << endl
			<< left << setw(25) << "Average sales"
			<< right << setw(60) << averageSales << endl
			<< left << setw(25) << "Total number of customers"
			<< right << setprecision(0) << setw(60) << noSales << endl;
	}

	//print ending message and allow user to view output

	cout << endl << "Program ended successfully" << endl << endl;
	system("type gas.rpt");
	system("pause");
}


/************************************************
Input output dialog
***************************************************

***********************************************************
****Input output dialog when ^Z entered at first prompt*******
Nothing is printed to output file (no titles, no data, no totals)
Therefore, see nothing on console input output in response
to system("type gas.rpt") command
************************************************************

Enter customer name or ctrl Z to end: ^Z
Program was ended by user

Program ended successfully

Press any key to continue . . .


*********************************************************************
Input output dialog: Valid and invalid data input for several customers.
Output file contents are shown below input output dialog on console.
File contents display on console in response to
system("type gas.rpt") command.
*********************************************************************

Enter customer name or ctrl Z to end: Jane Doe
Enter litres of gas: 33
Enter type of gas: D
Enter customer name or ctrl Z to end: John Smith
Enter litres of gas: 222
Error. Litres of gas must be a number between 0 and 100 only. Re-enter: 22
Enter type of gas: R
Enter customer name or ctrl Z to end: Sheldon Cooper
Enter litres of gas: 44
Enter type of gas: d
Enter customer name or ctrl Z to end: Jerry Seinfeld
Enter litres of gas: 77
Enter type of gas: q
Error. Gas type can only be R(regular), D(diesel) or P(propane)
Re-enter: R, D or P: P
Enter customer name or ctrl Z to end: Jim Cramer
Enter litres of gas: -10
Error. Litres of gas must be a number between 0 and 100 only. Re-enter: 10
Enter type of gas: P
Enter customer name or ctrl Z to end: Bob Dylan
Enter litres of gas: TWO
Error. Litres of gas must be a number between 0 and 100 only. Re-enter: 66
Enter type of gas: R
Enter customer name or ctrl Z to end: ^Z

Program ended successfully

Customer Name       Type of Gasoline        Price/Litre    # of Litres   Sales Amount

Jane Doe            D                              1.08           33.0          35.64

John Smith          R                              1.28           22.0          28.16

Sheldon Cooper      D                              1.08           44.0          47.52

Jerry Seinfeld      P                              2.50           77.0         192.50

Jim Cramer          P                              2.50           10.0          25.00

Bob Dylan           R                              1.28           66.0          84.48

Total sales                                                                    413.30
Average sales                                                                   68.88
Total number of customers                                                           6
Press any key to continue . . .


*/