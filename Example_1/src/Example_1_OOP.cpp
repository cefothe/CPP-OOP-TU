#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "bel.h"
#include "TFibonacii.h"

 int main()
{

	int x,y;
	Bel Tef(2);
	Tef.Append("Ivan", "Petrov", 34123L);
	Tef.Append("Stefan", "Stoyanov", 32564L);
	Tef.Append("Gabi", "Gabi", 32523L);
	Tef.Append("Ivan", "dsadasd", 34123L);
	Tef.Append("Stedsadafan", "Stdasdasoyanov", 32564L);
	Tef.Append("Gaasdasdabi", "Gadasdabi", 32523L);
	Tef.Fitst();
	for(int i=0; Tef.Next()!=-1;i++){
		BelRow *ARow = Tef.Get();
		if(ARow){
			printf("\nName = %s, Fam = %s, Tel = %lu", ARow->Name, ARow-> Fam, ARow->Tel);
		}
	}


}
