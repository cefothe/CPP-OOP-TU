//============================================================================
// Name        : Example_2_OOP.cpp
// Author      : Stefan Angelov(cefothe)
// Version     :
// Copyright   : 
// Description : Simple Banking System
//============================================================================
#include <stdio.h>
#include <string.h>
#include <memory.h>
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
	BankInfomation *Bank;
	int acctualNumberOfBank;
public:
	BankAccount(char *FirstNameP, char *LastNameP, int numberOfBankP);
	int Append(char *KindOfBankAccountP, char *IBANp,double valueP);
	void Delete(int index);
	BankInfomation *SearchByIBAN(char *IBANp);
	BankInfomation *SearchByPrice(double value);
	double SumOnAllBankAccount();
};

BankAccount::BankAccount(char *FirstNameP, char *LastNameP, int numberOfBankP){
	Bank = new BankInfomation[numberOfBankP];
	strcpy(FirstName, FirstNameP);
	strcpy(LastName, LastNameP);
	numberOfBank = numberOfBankP;
	acctualNumberOfBank =0;
}
int BankAccount::Append(char *KindOfBankAccountP, char *IBANp,double valueP){
	if(acctualNumberOfBank>=numberOfBank){
		return -1;
	}
	strcpy(Bank[acctualNumberOfBank].KindOfBankAccount, KindOfBankAccountP);
	strcpy(Bank[acctualNumberOfBank].IBAN, IBANp);
	Bank[acctualNumberOfBank].value = valueP;
	acctualNumberOfBank++;
	return 1;
}

BankInfomation *BankAccount::SearchByIBAN(char *IBANp){
	for(int i=0; i<acctualNumberOfBank; i++){
		if(!strcmp(IBANp, Bank[i].IBAN)){
			return &Bank[i];
		}
	}
	return NULL;
}
BankInfomation *BankAccount::SearchByPrice(double valup){
	for(int i=0; i<acctualNumberOfBank; i++){
		if(Bank[i].value==valup){
			return &Bank[i];
		}
	}
	return NULL;
}

//TODO: should be use more user friendly function for example memmove or something like that
void BankAccount::Delete(int index){
	int i = index;
	for(; i < acctualNumberOfBank; ++i)
	{
		Bank[i] = Bank[i+1];
	};
	if(i!=index){
	acctualNumberOfBank--;}
}

double BankAccount::SumOnAllBankAccount(){
	double sum=0;
	for(int i=0; i<acctualNumberOfBank; i++){
			sum+=Bank[i].value;
		}
	return sum;
}

int main() {
	BankAccount stefan("Stefan", "Angelov", 5);
	stefan.Append("Pay account", "123445676",9);
	stefan.Append("Credit account", "123445223",122);
	BankInfomation *test = stefan.SearchByIBAN("123445223");
	if(test){
		printf("%s", test->KindOfBankAccount);
	}
	stefan.Delete(1);
	printf("\n %lf", stefan.SumOnAllBankAccount());
	return 0;
}
