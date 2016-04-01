//============================================================================
// Name        : Example_5_OOP.cpp
// Author      : Stefan Angelov(cefothe)
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "FFile.h"
#include <string.h>
#include <iostream>
#include "WordCounter.h"
#include "TTable.h"
#include "TRow.h"
using namespace std;

int main() {

	FFile file;
	int numberOFInputElement=0;
	int numberOfDictualyWord=0;
	WordCounter* inputfile = file.open("input.txt",&numberOFInputElement);
	TTable table= file.writeDictualy("dictianaly.txt", &numberOfDictualyWord);
	WordCounter* outputFile = new WordCounter[100];
	for(int i=0; i< numberOFInputElement;i++){
		int counter;
		TRow* row =table.search(inputfile[i].words,&counter);
		outputFile[i].words=row->english;
	}
	file.write("output.txt",outputFile,&numberOFInputElement);
	return 0;
}
