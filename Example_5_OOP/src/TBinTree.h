/*
 * TBinTree.h
 *
 *  Created on: Apr 8, 2016
 *      Author: cefothe
 */

#ifndef TBINTREE_H_
#define TBINTREE_H_
#include <iostream>
#include <string>
#include "TRow.h"
using namespace std;

class TBinTree{
	TRow row;
	TBinTree *left;
	TBinTree *right;
public:
	static TRow *search (string searchWord, TBinTree *binTable);
	TBinTree(TRow rowParam){
		row = rowParam;
		left= NULL;
		right = NULL;
	}
	static void insert(TRow row, TBinTree **binTable);
	void deleteEl(TRow row, TBinTree **binTable);
	static void printTable(TBinTree *binTable);
};




#endif /* TBINTREE_H_ */
