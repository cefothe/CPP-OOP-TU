/*
 * TTable.cpp
 *
 *  Created on: Mar 24, 2016
 *      Author: cefothe
 */
#include "TTable.h"
#include <iostream>
#include <string>

using namespace std;
void TTable::add(string bulgarian, string english){
	if(countOfWord<100){
		rows[++countOfWord].bulgarian = bulgarian;
		rows[countOfWord].english = english;
	}
}
void TTable::printTable(){
	for(int i=0;i<=countOfWord;i++){
		cout << rows[countOfWord].bulgarian << " "<< rows[countOfWord].english;
	}
}
TRow* TTable::search(string bulgarian, int* counter){
	for(int i=0; i<=countOfWord;i++ ){
		if(rows[i].bulgarian.compare(bulgarian) == 0){
			*counter = i;
			return &rows[i];
		}
	}
	return NULL;
}
void TTable::deleteWord(string searchWord){
	int counter;
	TRow* rows = search(searchWord, &counter);
	int i = counter;
	if(rows!=NULL){
		for(; i < countOfWord; ++i)
		{
			TRow[i] = TRow[i+1];
		};
		if(i!=counter){
		countOfWord--;}
	}
}

