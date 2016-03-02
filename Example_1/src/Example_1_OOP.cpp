//============================================================================
// Name        : Example_1_OOP.cpp
// Author      : Velko Ilchev - TU PLOVDIV
// Editor	   : Stefan Angelov(cefothe)
// Version     :
// Copyright   : 
// Description : Electronic notebook
//============================================================================
#include <stdio.h>
#include <string.h>
#include <memory.h>

using namespace std;

struct BelRow{
	char Name[12];
	char Fam[15];
	unsigned long Tel;
};

// Define a prototype of class Bel
class Bel{
	BelRow Table[100];
	int TableEnd;
public :
	Bel(void){ TableEnd = 0;};
	int Append(char *Name, char *Fam, unsigned long Tel);
	int Append(BelRow *ARow);
	BelRow *FindRowByName(char *Name);
};

int Bel::Append(char *Name, char *Fam, unsigned long Tel){
	if(TableEnd >=100) return 0;
	strcpy(Table[TableEnd].Name, Name);
	strcpy(Table[TableEnd].Fam, Fam);
	Table[TableEnd].Tel = Tel;
	TableEnd++;
	return 1;
}
int Bel::Append(BelRow *ARow){
	if(TableEnd>=100) return 0;
	memcpy(&Table[TableEnd],ARow, sizeof(BelRow));
	TableEnd++;
	return 1;
}
BelRow *Bel::FindRowByName(char *Name){
	for(int i=0; i < TableEnd; i ++){
		if(!strcmp(Table[i].Name,Name))
			return &Table[i];
	}
	return NULL;
}
int main() {

}
