/*
 * FFile.cpp
 *
 *  Created on: Mar 24, 2016
 *      Author: cefothe
 */
#include "FFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

WordCounter* FFile::open(string fileName, int *numberOfWord){

	WordCounter* words = new WordCounter[100];

	string str; //temp variable
	ifstream myfile (fileName);
	  if (myfile.is_open())
	  {
		  int i = 0;
		  for (; (myfile >> str) && (i < 100); ++i) // Will read up to eof() and stop at every
		    {                                                // whitespace it hits. (like spaces!)
		      words[i] = str;
		    } // We now also need to stop before we hit the no define array space.
		  *numberOfWord = i;
		  myfile.close();
	  }
	  else cout << "Unable to open file";

	  return words;
}

void FFile::write(string fileName, WordCounter *words, int numberOfwords){
	  ofstream myfile (fileName);
	  if (myfile.is_open())
	  {
		for(int i=0 ; i<= numberOfwords; i++){
			myfile << words[i]<<" ";
		}
	    myfile.close();
	  }
	  else cout << "Unable to open file";
}
TTable* writeDictualy(string fileName, TRow* dictualy, int numberOfwords){

}



