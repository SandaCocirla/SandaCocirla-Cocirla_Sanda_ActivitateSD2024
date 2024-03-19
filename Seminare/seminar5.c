#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Cafenea Cafenea;
struct Cafenea {
	char* nume;
	int nrLocuri;
	float suprafata;
};

typedef struct Nod Nod;
struct Nod {
	Cafenea info;
	Nod* next;
};

Cafenea initializareCafenea(const char* nume, int nrLocuri, float suprafata) {
	Cafenea c;
	c.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
	strcpy(c.nume, nume);
	c.nrLocuri = nrLocuri;
	c.suprafata = suprafata;
	
	return c;
}

Nod* inserareInceput(Cafenea c, Nod* cap) {
	Nod* nou = malloc(sizeof(Nod));
	nou->next = cap;
	nou->info = initializareCafenea(c.nume, c.nrLocuri, c.suprafata);
	return nou;
}
void afisareCafenea(Cafenea c) {
	printf("\nCafeneaua: %s are %d locuri si o suprafata de %5.2f mp", c.nume, c.nrLocuri, c.suprafata);
}

void afisareCafenele(Nod* lista) {
	while (lista != NULL) {
		afisareCafenea(lista->info);
		lista = lista->next;
	}
}
//numele cafenelei cu densitatea cea mai mica
char* numeCafeneaDensitateMica(Nod* lista) {
	if (lista!=NULL) {
		if (lista->info.suprafata != 0) {
			float minim = lista->info.nrLocuri / lista->info.suprafata;
			Nod* adresa = lista;
			lista = lista->next;
			while (lista != NULL) {
				if (lista->info.nrLocuri / lista->info.suprafata < minim) {
					minim = lista->info.nrLocuri / lista->info.suprafata;
					adresa = lista;
				}
				lista = lista->next;
			}
			char* nume;
			nume = malloc(sizeof(char) * (strlen(adresa->info.nume) + 1));
			strcpy(nume, adresa->info.nume);
			return nume;
		}
		
	}
	return NULL;
}

void stergeLista(Nod** nod) {
	while (*nod != NULL) {
		Nod* aux;
		aux = *nod;
		*nod = (*nod)->next;
		free(aux->info.nume);
		free(aux);
	}
	*nod = NULL;
}

void inserareFinal(Nod** lista, Cafenea c) {
	if ((*lista) == NULL) {
		(*lista) = inserareInceput(c,*lista);
	}
	else {
		Nod* curent = (*lista);
		while (curent->next!=NULL) {
			curent = curent->next;
		}
		Nod* n = (Nod*)malloc(sizeof(Nod));
		n->info = initializareCafenea(c.nume,c.nrLocuri,c.suprafata);
		n->next = NULL;
		curent->next = n;
	}
	
}

void main() {
	//facem o lista cu pointer la nod
	Nod* cap= NULL;//capul listei ce va retine null

	Cafenea cafenea = initializareCafenea("Bonbon", 20, 70);
	Cafenea cafenea1 = initializareCafenea("Fuche", 30, 80);
	Cafenea cafenea2 = initializareCafenea("Damasque", 40, 90);

	cap = inserareInceput(cafenea, cap);
	cap = inserareInceput(cafenea1, cap);
	cap = inserareInceput(cafenea2, cap);
	printf("Lista cu inserare inceput creata:\n");
	afisareCafenele(cap);
	char* numeMinim = numeCafeneaDensitateMica(cap);
	printf("\n\nCafeneaua cu densitatea minima este: %s",numeMinim);
	
	printf("\n\nAfisare lista inserare final:\n");
	Cafenea cafenea3 = initializareCafenea("Lila", 10, 50);
	inserareFinal(&cap, cafenea3);
	afisareCafenele(cap);
	stergeLista(&cap);
	printf("\n\nLista dupa stergere:\n");
	afisareCafenele(cap);

	free(cafenea.nume);
	cafenea.nume = NULL;

	free(cafenea1.nume);
	cafenea.nume = NULL;

	free(cafenea2.nume);
	cafenea.nume = NULL;

	free(numeMinim);
	
}