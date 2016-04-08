/*
 * TBinTree.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: cefothe
 */

#include <iostream>
#include <string>
#include "TBinTree.h"
#include "stdio.h"
using namespace std;

 TRow *TBinTree::search(string searchWord, TBinTree *binTable){
	if(NULL == binTable){
		return NULL;
	}else if(searchWord.compare(binTable->row.bulgarian)<0){
		return TBinTree::search(searchWord, binTable->left);
	}else if(searchWord.compare(binTable->row.bulgarian)>0){
		return TBinTree::search(searchWord, binTable->right);
	}else
		return &(binTable->row);
}
 void TBinTree::insert(TRow row, TBinTree **binTable){
	if(NULL == *binTable){
		*binTable = new TBinTree(row);
	}else if(row.bulgarian.compare((*binTable)->row.bulgarian)<0){
		TBinTree::insert(row, &(*binTable)->left);
	}else if(row.bulgarian.compare((*binTable)->row.bulgarian)>0){
		TBinTree::insert(row, &(*binTable)->right);
	}
	else printf("this element already exit in table");

}
void TBinTree::printTable(TBinTree* binTable){
	if(NULL == binTable) return ;
		printf("bulgarian: %s english: %s",binTable->row.bulgarian.c_str(),binTable->row.english.c_str());
		TBinTree::printTable(binTable->left);
		TBinTree::printTable(binTable->right);

}
void TBinTree::deleteEl(TRow roe, TBinTree **binTable){

}




