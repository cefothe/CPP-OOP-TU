/*
 * TTable.cpp
 *
 *  Created on: Mar 24, 2016
 *      Author: cefothe
 */
#include "TDihotTable.h"

#include <iostream>
#include <string>

using namespace std;

void TDihotTable::add(string bulgarian, string english){
	if(countOfWord<10){
		int currentPosition;
		if(!binarySearch(bulgarian,0,countOfWord,&currentPosition)){
			refactoring(currentPosition,countOfWord);
			rows[currentPosition].bulgarian=bulgarian;
			rows[currentPosition].english= english;
			countOfWord++;
		}
	}
}

void TDihotTable::refactoring(int start, int end){
	for(int i= end; i>=start;i--){
		rows[i+1]= rows[i];
	}
}

void TDihotTable::printTable(){
	for(int i=0;i<=countOfWord;i++){
		cout << rows[countOfWord].bulgarian << " "<< rows[countOfWord].english;
	}
}
TRow* TDihotTable::search(string bulgarian, int* counter){
	int currentPosition;
	if(binarySearch(bulgarian,0, countOfWord,&currentPosition)){
		return &rows[currentPosition];
	}
	return NULL;
}

bool TDihotTable::binarySearch(string searchWord, int start, int end, int* currentPossition){
	if(start>end){
		*currentPossition = start;
		return false;
	}else
	if(searchWord.compare(rows[(start+end)/2].bulgarian)==0){
		*currentPossition = (start+end)/2;
		return true;
	}else if(searchWord.compare(rows[(start+end)/2].bulgarian)<0){
		binarySearch(searchWord, start,(start+end)/2-1, currentPossition);
	}else if(searchWord.compare(rows[(start+end)/2].bulgarian)>0){
		binarySearch(searchWord, (start+end)/2+1,end, currentPossition);
	}

}
void TDihotTable::deleteWord(string searchWord){
	int counter;
	TRow* rows = search(searchWord, &counter);
	int i = counter;
	if(rows!=NULL){
		for(; i < countOfWord; ++i)
		{
			rows[i] = rows[i+1];
		};
		if(i!=counter){
		countOfWord--;}
	}
}

