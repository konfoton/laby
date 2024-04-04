#include <iostream>
using namespace std;
#include "credit.h"



bool cmp_value(const credit& k1, const credit& k2)
{
	if(k1.value < k2.value){
		return true;
	}

	return false;	//popraw!
}

bool cmp_value_info(const credit& k1, const credit& k2)
{
	if(k1.value < k2.value){
		return true;
	}
	if(k1.value == k2.value){
		 if(k1.info < k2.info){
		 return true;
		 }
	}

	return false;
}

//-----------------------------------------------------------------
void write(credit** cr, int n, const char* description)	//GOTOWA
{
	cout << endl << description;
	for (int i = 0; i < n; i++) cout << *cr[i];
	cout << endl;
}

void sort(credit** credits, int n, bool (*operation)(const credit&, const credit&)){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(!(operation(*credits[i], *credits[j]))){
				credit* temp = (*credits[i]).clone();
				credits[i] = credits[j];
				credits[j] = temp; 
			}
		}
	}
}