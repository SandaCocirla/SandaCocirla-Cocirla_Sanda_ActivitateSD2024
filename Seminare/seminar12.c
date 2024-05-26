#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Metrou Metrou;
typedef struct NodPrincipal NodPrincipal;
typedef struct NodSecundar NodSecundar;

struct Metrou {
	int serie;
	int nrStatii;
	char* magistrala;
};

struct NodPrincipal {
	Metrou info;
	NodPrincipal* next;
	NodSecundar* vecini;
};

struct NodSecundar {
	NodPrincipal* nod;
	NodSecundar* next;
};

//initializare metrou
Metrou initializareMetrou(int serie, int nrStatii, const char* magistrala) {
	Metrou m;
	m.serie = serie;
	m.nrStatii = nrStatii;
	m.magistrala = (char*)malloc(sizeof(char)*(strlen(magistrala) + 1));
	strcpy(m.magistrala, magistrala);
	return m;
}

//inserare in lista secundara final
void inserareInListaPrinsipalaInceput(NodPrincipal** cap, Metrou m) {
	NodPrincipal* nou = (NodPrincipal*)malloc(sizeof(NodPrincipal));
	nou->info = m;
	nou->next = *cap;
	nou->vecini = NULL;
	*cap = nou;
}

//functie cauta nod dupa serie
NodPrincipal* cautaNodDupaSerie(NodPrincipal* graf, int serie) {
	while (graf && graf->info.serie != serie) {
		graf = graf->next;
	}
	return graf;
}

//inserare in lista secundara final
NodSecundar* inserareInListaSecundaraFinal(NodSecundar* cap, NodPrincipal* nod) {
	NodSecundar* nou = (NodSecundar*)malloc(sizeof(NodSecundar));
	nou->next = NULL;
	nou->nod = nod;
	if (cap) {
		NodSecundar* p = cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
		return cap;
	}
	else {
		return nou;
	}
}

// functie de inserare muchie
void inserareMuchie(NodPrincipal* graf, int serieStart, int serieStop) {
	NodPrincipal* nodStart = cautaNodDupaSerie(graf, serieStart);
	NodPrincipal* nodStop = cautaNodDupaSerie(graf, serieStop);
	if (nodStart && nodStop) {
		nodStart->vecini = inserareInListaSecundaraFinal(nodStart->vecini, nodStop);
		nodStop->vecini = inserareInListaSecundaraFinal(nodStop->vecini, nodStart);
	}
}

void main() {
	NodPrincipal* graf = NULL;

	inserareInListaPrinsipalaInceput(&graf, initializareMetrou(4, 6, "M2"));
	inserareInListaPrinsipalaInceput(&graf, initializareMetrou(3, 7, "M1"));
	inserareInListaPrinsipalaInceput(&graf, initializareMetrou(2, 8, "M4"));
	inserareInListaPrinsipalaInceput(&graf, initializareMetrou(1, 12, "M5"));
	inserareInListaPrinsipalaInceput(&graf, initializareMetrou(0, 4, "M6"));

	inserareMuchie(graf, 0, 1);
	inserareMuchie(graf, 1, 2);
	inserareMuchie(graf, 1, 3);
	inserareMuchie(graf, 1, 4);
	inserareMuchie(graf, 2, 3);
}

