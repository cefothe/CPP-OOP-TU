/*
 * TFibonacii.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: cefothe
 */
#include "TFibonacii.h"

int TFibonacii::Get(){
	int current = first + second;
	first = second;
	return second = current;
}

int TFibonacii::Set(int number){
	while(Get()<=number);
	return Get();
}

