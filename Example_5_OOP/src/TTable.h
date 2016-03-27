/*
 * TTable.h
 *
 *  Created on: Mar 23, 2016
 *      Author: cefothe
 */

#ifndef TTABLE_H_
#define TTABLE_H_

using namespace std;

class TTable{
	TRow rows[100];
	int countOfWord;
protected:
	void refactoring();
public:
	TTable(void){countOfWord=-1;};
	TRow* search(string searchWord, int *counter);
	void add(string bulgarian, string english);
	void deleteWord(string searchWord);
	void printTable();
};

#endif /* TTABLE_H_ */
