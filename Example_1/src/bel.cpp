/*
 * bel.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: cefothe
 */
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "bel.h"
#define EOT -1

Bel::Bel(int maxRowA){
	int tf= tFibonacii.Set(maxRowA);
	TableEnd = 0;
	CurrentRecord=0;
	Table = new BelRow[tf];
	maxRow = tf;
}

void Bel::UpdateTableSize(){
	int tf = tFibonacii.Get();
	BelRow * tempTable = new BelRow[tf];
	memcpy(tempTable, Table, sizeof(BelRow)*maxRow);
	maxRow = tf;
	delete Table;
	Table = tempTable;


}

void Bel::Fitst(){
	CurrentRecord = 0;
}

int Bel::Next(){
	if((CurrentRecord+1)<TableEnd){
		CurrentRecord++;
		return CurrentRecord;
	}else {
        return EOT;
	}
}

int Bel::Prev(){
	if(CurrentRecord <= 0){
    	CurrentRecord = 0;
	}else{
		CurrentRecord--;
	}
	return CurrentRecord;
}

void Bel::Last(){
	CurrentRecord = TableEnd -1;
}

BelRow *Bel::Get(){
	return &Table[CurrentRecord];
}
int Bel::Append(char *Name, char *Fam, unsigned long Tel){
	if(TableEnd >= maxRow)UpdateTableSize();
	strcpy(Table[TableEnd].Name, Name);
	strcpy(Table[TableEnd].Fam, Fam);
	Table[TableEnd].Tel = Tel;
	TableEnd ++;
	return 1;
	}
int Bel::Apeend(BelRow* Arow){
	if(TableEnd >= maxRow)UpdateTableSize();
	memcpy(&Table[TableEnd], Arow, sizeof(BelRow));
	TableEnd ++;
	return 1;
}

BelRow *Bel::FindRowByName(char *Name){
	for (int i=0; i < TableEnd; i++) {
		if(!strcmp(Table[i].Name, Name)){
			return &Table[i];
		}
	}
	return NULL;
}


