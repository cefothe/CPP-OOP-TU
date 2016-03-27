/*
 * FFile.h
 *
 *  Created on: Mar 23, 2016
 *      Author: cefothe
 */

#ifndef FFILE_H_
#define FFILE_H_

using namespace std;

class FFile{
public:
	WordCounter* open(string fileName,  int *numberOfWord);
	void write(string fileName, WordCounter* words, int numberOfwords);
	TTable* writeDictualy(string fileName, TRow* dictualy, int numberOfwords);
};

#endif /* FFILE_H_ */
