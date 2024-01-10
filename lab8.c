#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 50

//-----------------------------------------------------
typedef struct who {
	char firstName[M];
	char lastName[M];
}who;

//-----------------------------------------------------
typedef struct car {
	char* model;
	who* driver;
}car;

//-----------------------------------------------------
typedef struct el {
	struct el* next;
	car* s;
} el;

//-----------------------------------------------------
typedef struct list {
	el* head;
} list;


//ETAP 1 (2p)
list* init_list(); //0.5p
int push_front(list* L, char* model); //1p
void print_list(list L); //0.5p

//ETAP 2 (2.5p)
int push_priority(list* L, char* model); //1.5p
void tab2list(char* T[][2], list* renault, list* toyota, int liczba); //1p

//ETAP 3 (1.5p)
el* search(list* L, char* model); //0.5p
who* driver_to_car(el* s, char* firstName, char* lastName); //1p

//ETAP 4 (1p)
void remove_empty_car(list* L);

//-----------------------------------------------------------
int main(void)
{
	list* renault = NULL, * toyota = NULL;
	int ok;
	el* n;
	who* o;

	char* cary[][2] = { {"renault", "Megane"},{"renault", "Talisman"},{"toyota", "Yaris"},
						{"renault", "Scenic"},{"peugeot","206"}, {"toyota", "Rav 4"},{"renault", "Laguna 1"},
						{"renault", "Clio 2"},{"toyota", "Corolla"},{"toyota", "Avensis"},{"toyota", "Corolla"} };


	//Etap 1
	printf("\n*******ETAP 1********\n");
	renault = init_list();
	if (!renault) { printf("\nNiepowodzenie init_list...\n");  return 0; }

	ok = push_front(renault, "Laguna 1");
	if (!ok)  printf("\nNIE dodano ...\n");

	ok = push_front(renault, "Clio 1");
	if (!ok)  printf("\nNIE dodano ...\n");

	printf("\n\nLista RENAULT:\n");
	print_list(*renault);


	printf("\n*******ETAP 2********\n");

	char* model1[] = { "Corolla" ,"Avensis" ,"Rav 4" ,"Corolla" };
	toyota = init_list();
	if (!toyota) { printf("\nNiepowodzenie init_list...\n");  return 0; }

	for (int i = 0; i < 4; i++)
	{
		ok = push_priority(toyota, model1[i]);
		if (!ok)  printf("\nNIE dodano ...\n");
	}

	printf("\nAlfabetyczna lista TOYOTA:\n");
	print_list(*toyota);


	printf("\nDodanie wszystkich samochodow z tablicy:\n");
	tab2list(cary, renault, toyota, sizeof(cary) / sizeof(char*) / 2);
	printf("\nsamochody RENAULT:\n");
	print_list(*renault);
	printf("\nsamochody TOYOTA:\n");
	print_list(*toyota);

	//Etap 3
	printf("\n*******ETAP 3********");
	printf("\nWyszukiwanie modelu bez kierowcy:\n");
	n = search(toyota, "Corolla");
	if (n) printf("\nZnaleziony car: %s", n->s->model);
	else printf("Brak modelu Corolla na liscie\n");

	n = search(toyota, "Corola");
	if (n) printf("\nZnaleziony car: %s", n->s->model);
	else printf("\nBrak modelu Corola na liscie\n");

	char* model2[] = { "Rav 4","Rav 4","Yaris" ,"Yaris" };
	char* who[][2] = { {"Marek", "Konieczny"},{"Mateusz", "Niekonieczny"},{"Marzena", "Witek"},{"Gabriela", "Kotek"} };

	for (int i = 0; i < 4; i++)
	{
		printf("\n%d driver:\n", i + 1);
		n = search(toyota, model2[i]);
		o = driver_to_car(n, who[i][0], who[i][1]);
		if (o) print_list(*toyota);
		else printf("driver juz jest; brak wolnego modelu %s\n", model2[i]);
	}

	//Etap 4
	printf("\n*******ETAP 4********");
	printf("\nUsuwanie wolnych samochodow (bez kierowcy):\n");
	remove_empty_car(renault);
	remove_empty_car(toyota);

	printf("\nsamochody RENAULT (z kierowca):\n");
	print_list(*renault);
	printf("\nsamochody TOYOTA (z kierowca):\n");
	print_list(*toyota);

	printf("\n");
	system("pause");
	return 0;
}
list* init_list()
{
	list* temp = (list*)malloc(sizeof(list));
	temp->head = NULL;
	return temp;
}
int push_front(list* L, char* model)
{
	if (L->head == NULL)
	{
		el* temp = (el*)malloc(sizeof(el));
        if(!temp)
        {
            return 0;
        }
		car* temp1 = (car*)malloc(sizeof(car));
        if(!temp1){
            return 0;
        }
		temp1->model = model;
		temp->s = temp1;
		temp->next = NULL;
		L->head = temp;
	}
	else
	{
		el* temp = (el*)malloc(sizeof(el));
        if(!temp)
        {
            return 0;
        }
		car* temp1 = (car*)malloc(sizeof(car));
        if(!temp1){
            return 0;
        }
		temp1->model = model;
		temp->s = temp1;
		temp->next = NULL;
		el* temp4 = L->head;
		L->head = temp;
		temp->next = temp4;
	}
    return 1;
}
void print_list(list L) {
	el* temp = L.head;
	while (temp != NULL)
	{
		printf("%s\n", temp->s->model);
		temp = temp->next;
	}
}
int push_priority(list* L, char* model) {
    if (L == NULL || model == NULL) {
        return 0;
    }

    el* new_element = (el*)malloc(sizeof(el));
    if (!new_element) {
        return 0;
    }

    car* new_car = (car*)malloc(sizeof(car));
    if (!new_car) {
        free(new_element);
        return 0;
    }

    new_car->model = model;
    new_car->driver = NULL;
    new_element->s = new_car;
    new_element->next = NULL;

    if (L->head == NULL || strcmp(model, L->head->s->model) < 0) {
        new_element->next = L->head;
        L->head = new_element;
    } else {

        el* current = L->head;
        while (current->next != NULL && strcmp(model, current->next->s->model) > 0) {
            current = current->next;
        }

        new_element->next = current->next;
        current->next = new_element;
    }

    return 1;
}
void tab2list(char* T[][2], list* renault, list* toyota, int liczba)
{
    for(int i = 0; i < liczba; i++)
    {
        if(!(strcmp(T[i][0], "renault")))
        {
            push_priority(renault, T[i][1]);
        }
        else{
            push_priority(toyota, T[i][1]);
        }
    }
}
el* search(list* L, char* model)
{
    el* current = L->head;
    while(current != NULL)
    {
        if(current->s->driver == NULL && !(strcmp(current->s->model, model)))
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
who* driver_to_car(el* s, char* firstName, char* lastName)
{
    if (s == NULL || s->s == NULL) {
        return NULL;
    }
    if(s->s->driver != NULL)    
    {
        return NULL;
    }else{
    who* temp = (who*)malloc(sizeof(who));
    strcpy(temp->firstName, firstName);
    strcpy(temp->lastName, lastName);
    s->s->driver = temp;
    return temp;
    }
}
void remove_empty_car(list* L) {
    if (L == NULL || L->head == NULL) {
        return; // Check if the list is empty or L is NULL
    }

    el* current = L->head;
    el* before = NULL;

    while (current != NULL) {
        if (current->s->driver == NULL) {
            if (before == NULL) {

                L->head = current->next;
                free(current->s);
                free(current);
                current = L->head;
            } else {

                before->next = current->next;
                free(current->s);
                free(current);
                current = before->next;
            }
        } else {
            before = current;
            current = current->next;
        }
    }
}