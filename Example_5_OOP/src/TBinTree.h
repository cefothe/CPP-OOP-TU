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
using namespace std;

class TBinTree{
	TRow row;
	TBinTree *left;
	TBinTree *right;
public:
	TBinTree *search (string searchWord, TBinTree *binTable);
	void insert(TRow row, TBinTree **binTable);
	void deleteEl(TRow row, TBinTree **binTable);
	void printTable(TBinTree **binTable);
};




#endif /* TBINTREE_H_ */
