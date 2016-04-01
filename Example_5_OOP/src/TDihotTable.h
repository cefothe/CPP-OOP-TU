/*
 * TTable.h
 *
 *  Created on: Mar 23, 2016
 *      Author: cefothe
 */

#ifndef TDIHOTTABLE_H_
#define TDIHOTTABLE_H_
#include "TRow.h"
#include "string"
using namespace std;

class TDihotTable{
	TRow rows[10];
	int countOfWord;
public:
	TDihotTable(void){countOfWord=0;};
	void refactoring(int start, int end);
	TRow* search(string searchWord, int *counter);
	bool binarySearch(string searchWord, int start, int end, int *currentPossiton);
	void add(string bulgarian, string english);
	void deleteWord(string searchWord);
	void printTable();
};

#endif /* TDIHOTTABLE_H_ */
