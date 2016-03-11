#include <stdio.h>
#include <string.h>
#include <memory.h>
#define EOT -1
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
	public:
	Bel(int maxRowA){TableEnd = 0; CurrentRecord=0; Table = new BelRow[maxRowA];maxRow = maxRowA;}
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

void Bel::UpdateTableSize(){
	BelRow * tempTable = new BelRow[maxRow*2];
	memcpy(tempTable, Table, sizeof(BelRow)*maxRow);
	maxRow = maxRow*2;
	delete Table;
	Table = tempTable;


}

void Bel::Fitst(){
	CurrentRecord = 0;
}

int Bel::Next(){
	if((CurrentRecord+1)<TableEnd){
		CurrentRecord++;
		return CurrentRecord;
	}else {
        return EOT;
	}
}

int Bel::Prev(){
	if(CurrentRecord <= 0){
    	CurrentRecord = 0;
	}else{
		CurrentRecord--;
	}
	return CurrentRecord;
}

void Bel::Last(){
	CurrentRecord = TableEnd -1;
}

BelRow *Bel::Get(){
	return &Table[CurrentRecord];
}
int Bel::Append(char *Name, char *Fam, unsigned long Tel){
	if(TableEnd >= maxRow)UpdateTableSize();
	strcpy(Table[TableEnd].Name, Name);
	strcpy(Table[TableEnd].Fam, Fam);
	Table[TableEnd].Tel = Tel;
	TableEnd ++;
	return 1;
	}
int Bel::Apeend(BelRow* Arow){
	if(TableEnd >= maxRow)UpdateTableSize();
	memcpy(&Table[TableEnd], Arow, sizeof(BelRow));
	TableEnd ++;
	return 1;
}

BelRow *Bel::FindRowByName(char *Name){
	for (int i=0; i < TableEnd; i++) {
		if(!strcmp(Table[i].Name, Name)){
			return &Table[i];
		}
	}
	return NULL;
}


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
