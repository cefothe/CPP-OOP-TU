/*
 * FFile.h
 *
 *  Created on: Mar 23, 2016
 *      Author: cefothe
 */

#ifndef FFILE_H_
#define FFILE_H_
#include "WordCounter.h"
#include "TTable.h"
#include "TRow.h"
using namespace std;

class FFile{
public:
	WordCounter* open(string fileName,  int* numberOfWord);
	void write(string fileName, WordCounter* words, int* numberOfwords);
	TTable writeDictualy(string fileName, int* numberOfwords);
};

#endif /* FFILE_H_ */
