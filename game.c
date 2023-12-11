#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 25	//liczba kart: piotrek + 12 par (1,1,2,2,3,3,...,12,12,13)
#define PIOTREK 13


//-----------------------------------------------------
//ETAP1 (1,5pkt)
void init(int t[], int n);	//warto�ci: 1,1,2,2,3,3,...,12,12,13
void wypisz(int t[], int n);

//ETAP2 (1,5pkt)
void tasuj(int t[], int n);
void rozdaj(int t[], int n, int ja[], int* n_ja, int komp[], int* n_komp);

//ETAP3 (2pkt)
void usuwaj_karte(int g[], int* n, int nr);
void usuwaj_pary(int g[], int* n_g);

//ETAP4 (2pkt)
void wyciagnij_karte(int ja[], int* n_ja, int komp[], int* n_komp);
int gra(int* g1, int n_g1, int* g2, int n_g2);

//-----------------------------------------------------
int main()
{
	int n = 25;
	int talia[N], ja[N], komp[N];
	int n_ja = 0;		//liczba kart gracza (przed otrzymaniem kart 0)
	int n_komp = 0;	//liczba kart gracza (przed otrzymaniem kart 0)

	//ETAP1 (1,5pkt)
	printf("\n---------- KARTY:\n");
	init(talia, N);
	wypisz(talia, N);

	////ETAP2 (1,pkt)
	srand((unsigned)time(NULL));
	printf("\n---------- POTASOWANE:\n");
	tasuj(talia, N);
	wypisz(talia,N);

	printf("\n----------- ROZDANIE KART:\n");
	rozdaj(talia, N, ja, &n_ja, komp, &n_komp);
	printf("\nMOJE KARTY\n");
	wypisz(ja,n_ja);
	printf("\nKARTY KOMPUTERA\n");
	wypisz(komp, n_komp);

	////ETAP3 (2pkt)
	printf("\n----------- USUWANIE PAR u graczy:\n");
	usuwaj_pary(ja,&n_ja);
	printf("\nMoje karty po USUWANIU par\n");
	wypisz(ja,n_ja);
	usuwaj_pary(komp,&n_komp);
	printf("\nKarty komputera po USUWANIU par\n");
	wypisz(komp,n_komp);

	//ETAP4 (2pkt)
	printf("\n----------- GRA:\n");
	if (gra(ja, n_ja, komp, n_komp))
		printf("\nWygrywam JA !!!\n");
	else
		printf("\nWygrywa KOMPUTER !!!\n");


	return 0;
}
//----------------------------------------------
void init(int t[], int n)
{
	int karty = ((n - 1) / 2) + 1;
	int counter = 0;
	for (int i = 1; i <= karty; i++)
	{
		if (i == 13)
		{
			t[counter] = i;
		}
		else {
			t[counter] = i;
			t[counter + 1] = i;
			counter += 2;
		}
			}
}
//------------------------------------------------
void wypisz(int t[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", t[i]);
	}

}

//-----------------------------------------------
void tasuj(int t[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int random = rand() % n;
		int temp = t[i];
		t[i] = t[random];
		t[random] = temp;
	}


}

//------------------------------------------------
void rozdaj(int t[], int n, int ja[], int* n_ja, int komp[], int* n_komp)
{
	int rola = 0;
	for (int i = 0; i < n; i++)
	{
		if (rola % 2 == 0)
		{
			ja[*n_ja] = t[i];
			*n_ja += 1;
		}
		else {
			komp[*n_komp] = t[i];
			*n_komp += 1;
		}
		rola += 1;
	}

}
//--------------------------------------------------
void usuwaj_karte(int g[], int* n, int nr)
{
	g[nr] = 0;
	for (int j = nr + 1; j < *n ; j++) {
		int temp = g[j];
		g[j] = g[j - 1];
		g[j - 1] = temp; 
	}
	*n -= 1;

}
//--------------------------------------------------
void usuwaj_pary(int g[], int* n_g)
{
	
	for (int i = 0; i < *n_g - 1; i++)
	{
			for (int j = i + 1; j < *n_g; j++)
			{
				if (g[i] == g[j])
				{
					usuwaj_karte(g, n_g, j);
					usuwaj_karte(g, n_g, i);
					i--;
					break;
				}
			}
		}
	}

//--------------------------------------------------
void wyciagnij_karte(int ja[], int* n_ja, int komp[], int* n_komp)
{
	int losowanie = rand() % *n_ja;
	int wybierz = ja[losowanie];
	if (wybierz == 13) {
		usuwaj_karte(ja, n_ja, losowanie);
		*n_komp += 1;
		komp[*n_komp-1] = wybierz;
	}
	else {
		usuwaj_karte(ja, n_ja, losowanie);
		for(int x = 0; x < *n_komp; x++)
		{
			if(komp[x] == wybierz)
			{
				usuwaj_karte(komp, n_komp, x);
			}
		}
		
	}


}//---------------------------------------------------

int gra(int* g1, int n_g1, int* g2, int n_g2)	//GOTOWA!!!
{
	int gra_g1=0;
	int starcie = 1;
	
	if (n_g1 < n_g2)	// zaczyna - ten kto ma mniej kart
		gra_g1 = 1;

	// a� nie zostanie kto� z Piotrkiem (czyli kto� nie ma ju� kart) - ci�gnij na zmian�
	while(n_g1>0 && n_g2>0)
	{
		printf("\nSTARCIE %d  ", starcie++);
		
		if (gra_g1)
		{
			printf(", JA wyciaga karte od KOMP  ");
			wyciagnij_karte(g1,&n_g1,g2,&n_g2);
			gra_g1 = 0; 
		}
		else
		{
			printf(", KOMP wyciaga karte od JA  ");
			wyciagnij_karte(g2,&n_g2,g1,&n_g1);
			gra_g1 = 1;
		}
		// wy�wietl karty
		printf("\nkarty JA: ");
		wypisz(g1,n_g1);
		printf("\nkarty KOMPUTER: ");
		wypisz(g2,n_g2);
	}

	if (n_g1>0) return 0;
	
	return 1;

}//----------------------------------------------------