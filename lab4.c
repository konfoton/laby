#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef struct array
{
	int* w;		//dynamiczna tablica n elementów
	int n;		//liczba elementów tablicy dynamicznej
				//jeśli tablica przechowuje wsp. dla wielomianu, to w[n-1] - wsp. przy najwyższej potędze, w[0]-wyraz wolny
} array;

void printa(int* arr, int size);
//----------------------------------------------------------------------
//ETAP 1
void print(array w);
int polynomial_generator(array* w, int st, int a, int b);
int multiplication(array w1, array  w2, array*  w3);	

// ETAP 2
int value(array* w, int x);
int find_roots(array w, int** p, int* size);

//ETAP 3
int polyder(array w, array* w_prim);
// int single_root(array w, int i);

//----------------------------------------------------------------------
int main()
{
    		//tablica całkowitych pierwiastków wielomianu
	array w1 = { NULL, 0 };		//tablica wsp. wielomianu w bazie potęgowej
								//w[n] - wsp. przy najwyższej potędze, w[0]-wyraz wolny
	array w2 = { NULL, 0 };		
	array w3 = { NULL, 0 };
    array pochodna = {NULL, 0};
    array pochodna1 = {NULL, 0};
    int* roots = NULL;
	int i;
    int sizee= 0;
    int* roots1 = NULL;
    int size1 = 0;
		
	
	printf("\nETAP1-----------------------------------------------------------------\n");

	//srand((unsigned)time(NULL));
	
	srand(1640635484);
	int b = 5, a=-5;

	if (!polynomial_generator(&w1, 3, a, b) || !polynomial_generator(&w2, 5, a, b)) 
	{
		printf("NIE wylosowano wsp. dla wielomianu w1, w2!\n");
		free(w1.w);
		free(w2.w);
		return 1;
	}

	printf("Wylosowano wsp. dla wielomianu w1:\n");
	print(w1);

	printf("Wylosowano wsp. dla wielomianu w2:\n");
	print(w2);

	if (!multiplication( w1, w2, &w3))
	{
		printf("NIE zdefiniowano wsp. wielomianu w3!\n");
		free(w1.w);
		free(w2.w);
		return 1;
	}

	printf("Wsp. wielomianu w3=w1*w2 w bazie potegowej:\n");
	print(w3);	


	printf("\n\nETAP2-----------------------------------------------------------------\n");
	
	if (!find_roots(w3, &roots, &sizee))
	{
		printf("NIE znaleziono pierwiastkow calkowitych dla wielomianu w3!\n");
		free(w1.w);
		free(w2.w);
		free(w3.w);
		return 1;
	}

	printf("\nZnaleziona lista calkowitych pierwiastkow dla w3");
	printa(roots, sizee);
	printf("\nSprawdzenie, czy to zera wielomianu?");
	for (int i = 0; i < sizee ; i++)
		printf("\ndla x=r%d=%d w(x)=%d", i, roots[i], value(&w3, roots[i]));
	
	
	
	printf("\n\nETAP3-----------------------------------------------------------------\n");
	
	
	printf("Wsp. pochodnej wielomianu:\n");

	//pokaż, jak wywołać polyder oraz print, dla pokazania obliczonych wsp. pochodnej wielomianu w3
    if(!polyder(w3, &pochodna))
    {
        free(pochodna.w);
    }
    print(pochodna);

	// printf("\nCzy pojedyncze zero wielomianu? - przez sprawdzenie wartosci pochodnej:\n");

	// for (int i = 0; i < sizee; i++)
	// 	if (single_root(w3, roots[i]))
	// 		printf("\n zero pojedyncze: r%d=%3d", i, roots[i]);


	
	// free(w1.w);
	// free(w2.w);
	// free(w3.w);
	// free(roots);
	// free(w_prim.w);

	printf("\n\nKONIEC\n");
	
}
int polynomial_generator(array* w, int st, int a, int b)
{
    w->w = (int*)malloc(sizeof(int) * (st + 1));
    w->n = st;
    w->w[0] = pow(a + (rand() % (b-a+1)),st);
    w->w[st] = 1;
    for(int i = 1; i < st; i++)
    {
        w->w[i] = 0;
    }
    return 1;
}
void print(array w)
{
    printf("[ ");
    for(int i = w.n; i >= 0; i--)
    {
        printf("%d ", w.w[i]);
    }
    printf("]");
}
int multiplication(array w1, array w2, array* w3)
{
    w3->n = w1.n + w2.n;
    w3->w = (int*)malloc(sizeof(int) * (w1.n + w2.n + 1));
    w3->w[w3->n] = w1.w[w1.n] * w2.w[w2.n];
    w3->w[w1.n] = w2.w[0];
    w3->w[w2.n] = w1.w[0];
    w3->w[w3->n] = w1.w[w1.n] * w2.w[w2.n]; 
    w3->w[0] = w1.w[0] * w2.w[0];
    return 1;
}
int value(array* w, int x)
{
 int wynik = w->w[w->n];
 for(int i = 1; i <= w->n; i++)
 {
        wynik = (wynik * x) + w->w[w->n - i];
 }  
 return wynik;
}
int find_roots(array w, int** p, int* size)
{
    int counter = 0;
    for(int i = 1; i <= -(w.w[0]); i++)
    {
        if((w.w[0] % i) == 0)
        {
            if(value(&w, i) == 0)
            {
                if(*p != NULL)
                {
                    counter += 1;
                    *p = realloc(*p, counter * sizeof(int));
                    *p[counter- 1] = i;
                }
                else
                {
                    counter +=1;
                    *p = (int*)malloc(sizeof(int) * 1);
                    *p[0] = i;
                }
            }
        }
    }
    *size = counter;
    return 1;
}
void printa(int* arr, int size)
{
    printf(" %d", size);
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int polyder(array w, array* w_prim)
{
    w_prim->n = w.n - 1;
    w_prim->w = (int*)malloc(w_prim->n * sizeof(int));
    for(int i = w.n; i >= 1; i--)
    {
        w_prim->w[i -1] = w.w[i] * i;
    }
    return 1;
}
// int single_root(array w, int i);
// {
//     // polyder(w, &pochodna1);
//     // find_roots(pochodna1, &roots1, &size1);
//     // for(int i = 0; i < size1; i++)
//     // {
//     //     if
//     // }
// }