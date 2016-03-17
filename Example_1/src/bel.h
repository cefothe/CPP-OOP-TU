/*
 * bel.h
 *
 *  Created on: Mar 17, 2016
 *      Author: cefothe
 */

#ifndef BEL_H_
#define BEL_H_
#include "TFibonacii.h"

struct BelRow{
	char Name[12];
	char Fam[15];
	unsigned long Tel;
};

class Bel{
	BelRow *Table;
	int TableEnd;
	int CurrentRecord;
	int maxRow;
	TFibonacii tFibonacii;
	public:
	Bel(int maxRowA);
	int Append(char *Name, char *Fam, unsigned long Tel);
	int Apeend(BelRow *ARow);
	BelRow* FindRowByName(char *Name);
	void Fitst();
	int Next();
	int Prev();
	void Last();
	BelRow* Get();
	void UpdateTableSize();
	~Bel(){delete Table;};
};




#endif /* BEL_H_ */
