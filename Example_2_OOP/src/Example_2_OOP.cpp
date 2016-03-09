//============================================================================
// Name        : Example_2_OOP.cpp
// Author      : Stefan Angelov(cefothe)
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

//TODO: Need to be check about numbers of character in IBAN
struct BankInfomation{
	char KindOfBankAccount[20];
	char IBAN[12];
	double value;
};

class BankAccount{
	char FirstName[20];
	char LastName[20];
	int numberOfBank;
	BankInfomation Bank[20];
	int acctualNumberOfBank;
public:
	BankAccount(char *FirstNameP, char *LastNameP, int numberOfBank);
	int Append(char *KindOfBankAccountP, char *IBANp,double valueP);
	int pop();
	BankInfomation *SearchByIBAN(char *IBANp);
	BankInfomation *SearchByPrice(double value);
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
