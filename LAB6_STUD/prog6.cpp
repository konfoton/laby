#include <iostream>
using namespace std;
#include "credit.h"
#include "creditDet.h"
#include "functions.h"


//-------------------------------------------
int main()
{

	cout<<"ETAP 1 - test class credit"<<endl<<endl;
	{
		credit k1(1000,9,5,12,"P 23/2017"), k2(k1), k3;

		k3=k2;

		cout<<"credits:"<<endl;
		cout<<"k1: "<<k1<<endl<<"k2: "<<k2<<endl<<"k3: "<<k3<<endl;

		credit k4(500, 3, 2, 20, "P 10/2021");

		k2 = k4;

		cout << "k2=k4" << k2 << endl;
	}

	cout << "--------------------------------------------------------------" << endl;
	cout<<"ETAP 2 - test class creditDet"<<endl<<endl;
	{
		creditDet kF1( 10000, 4., 2, 3, "K 45/2017"), kF2(kF1), kF3;

		kF3 = kF2;

		cout << "creditDet:" << endl;
		cout << "kF1: " << kF1 << endl << "kF2: " << kF2 << endl << "k3: " << kF3 << endl;
		
		credit* p = new creditDet(20000, 4., 2, 3, "K 50/2021");
		cout << "*p: " << *p << endl;
		delete p;	//czy poprawne?
	}


	cout << "---------------------------------------------------------------"<<endl;
	cout<<endl<<"ETAP 3"<<endl<<endl;

	const int N = 10;
	credit* credits[N]={
			 new creditDet( 10000, 3, 2, 3, "K 23/2021"),
			 new creditDet( 1000, 4, 1, 4, "R 15/2021"),
			 new credit( 10000, 7.5, 2, 4),
			 new creditDet( 1000, 3, 1, 12, "K 37/2021"),
			 new creditDet( 50000, 4.5, 4, 2),
			 new credit( 5000, 5, 2, 4, "R 50/2021"),
			 new creditDet( 1000, 3, 3, 2, "K 35/2021"),
			 new credit( 1000, 4, 2, 3, "K 10/2021"),
			 new creditDet( 100, 9, 1, 4, "K 20/2021"),
			 new credit( 1000, 7, 2, 3, "P 22/2021")
	};

	write(credits, N, "credits:");

	cout << "---------------------------------------------------------------" << endl;
	cout<<endl<<"ETAP 4 - sort"<<endl<<endl;

	sort(credits, N, cmp_value);
	write(credits, N, "sort credits by value:");
	
	sort(credits, N, cmp_value_info);
	write(credits, N, "sort credits by value, info:");

	sort(credits, N);
	write(credits, N, "sort credits by value:");
	

	cout << "---------------------------------------------------------------" << endl;
	cout << endl << "ETAP 5 - clone credits" << endl << endl;

	credit* credits2[N];

	for (int i = 0; i < N; i++) credits2[i] = credits[i]->clone();
	write(credits2, N, "credits2:");


	cout<<endl<<"DELETE credits"<<endl;
	for (int i = 0; i < N; i++) {
		delete credits[i]; delete credits2[i];
	}

	

	cout << "END" << endl;
}