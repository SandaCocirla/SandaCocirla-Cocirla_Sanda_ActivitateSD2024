//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Galerie Galerie;
//struct Galerie {
//	int cod;
//	char* nume;
//	float pretIntrare;
//};
//
//typedef struct Nod Nod;
//struct Nod {
//	Galerie galerie;
//	Nod* next;
//};
//
//typedef struct HashTable HashTable;
//struct HashTable {
//	Nod** vector;
//	int dim;
//};
//
//HashTable initializareHashTable(int dim) {
//	HashTable hash;
//	hash.vector = (Nod**)malloc(sizeof(Nod*) * dim);
//	for (int i = 0; i < dim; i++) {
//		hash.vector[i] = NULL;
//	}
//	hash.dim = dim;
//	return hash;
//}
//
//Galerie initializareGalerie(int cod, const char* nume, float pretIntrare) {
//	Galerie galerie;
//	
//	galerie.cod = cod;
//	galerie.nume = (char*)malloc(strlen(nume) + 1);
//	strcpy(galerie.nume, nume);
//	galerie.pretIntrare = pretIntrare;
//
//	return galerie;
//}
//
//int calculeazaHash(int cod, const char* nume, int dim) {
//	if (dim > 0) {
//		int rez = cod * strlen(nume);
//		return rez % dim;
//	}
//	return -1;
//}
//
//void inserareLaFinal(Nod** cap, Galerie galerie) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->galerie = galerie;
//	nou->next = NULL;
//	if ((*cap) != NULL) {
//		Nod* aux = (*cap);
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else {
//		(*cap) = nou;
//	}
//}
//
//void inserareGalerieInHashTable(HashTable hash, Galerie galerie) {
//	int pozitie = calculeazaHash(galerie.cod, galerie.nume, hash.dim);
//	inserareLaFinal(&(hash.vector[pozitie]), galerie);
//}
//
//void afisareGalerie(Galerie g) {
//	printf("%d. Intrarea la galeria %s costa %.2f\n", g.cod, g.nume, g.pretIntrare);
//}
//
//void afisareListaGalerii(Nod* cap) {
//	while (cap != NULL) {
//		afisareGalerie(cap->galerie);
//		cap = cap->next;
//	}
//}
//
//void afisareHashTable(HashTable hash) {
//	for (int i = 0; i < hash.dim; i++) {
//		if (hash.vector[i] != NULL) {
//			printf("CLusterul: %d\n", (i + 1));
//			afisareListaGalerii(hash.vector[i]);
//		}
//	}
//}
//
//Galerie cautaGalerieDupaCheie(int cod, const char* nume, HashTable hashTable) {
//	int pozitie = calculeazaHash(cod, nume, hashTable.dim);
//	if (pozitie >= 0 && pozitie < hashTable.dim) {
//		Nod* p = hashTable.vector[pozitie];
//		while (p && p->galerie.cod != cod && strcmp(p->galerie.nume, nume) != 0) {
//			p = p->next;
//		}
//		if (p) {
//			return p->galerie;
//		}
//		else {
//			return initializareGalerie(-1, "", 0);
//		}
//	}
//	else {
//		return initializareGalerie(-1, "", 0);
//	}
//}
//
//void main() {
//	Galerie g1 = initializareGalerie(1, "Orizont", 10);
//	Galerie g2 = initializareGalerie(2, "Cercul armatei", 6);
//	Galerie g3 = initializareGalerie(3, "Louvre", 30);
//	Galerie g4 = initializareGalerie(4, "Antipa", 20);
//	Galerie g5 = initializareGalerie(5, "Istorie", 15);
//	Galerie g6 = initializareGalerie(6, "Geologie", 17);
//
//	HashTable tabela = initializareHashTable(5);
//
//	inserareGalerieInHashTable(tabela, g1);
//	inserareGalerieInHashTable(tabela, g2);
//	inserareGalerieInHashTable(tabela, g3);
//	inserareGalerieInHashTable(tabela, g4);
//	inserareGalerieInHashTable(tabela, g5);
//	inserareGalerieInHashTable(tabela, g6);
//
//	afisareHashTable(tabela);
//	printf("\n\n________________________________________________\n\n");
//
//	Galerie g = cautaGalerieDupaCheie(1, "Orizont", tabela);
//	printf("Cautare:\n");
//	afisareGalerie(g);
//
//
//}