//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Cafenea Cafenea;
//struct Cafenea {
//	char* nume;
//	int nrLocuri;
//	float suprafata;
//};
//
//typedef struct Nod Nod;
//struct Nod {
//	Cafenea cafenea;
//	Nod* next;
//	Nod* prev;
//};
//
//typedef struct ListaDubla ListaDubla;
//struct ListaDubla {
//	Nod* cap;
//	Nod* coada;
//};
//
//void inserareInceput(ListaDubla* listaDubla, Cafenea cafenea) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->cafenea = cafenea;
//	nou->next = listaDubla->cap;
//	nou->prev = NULL;
//
//	if (listaDubla->cap != NULL) {
//		listaDubla->cap->prev = nou;
//	}
//	else {
//		listaDubla->coada = nou;
//	}
//	listaDubla->cap = nou;
//}
//
//Cafenea initializareCafenea(const char* nume, int nrLocuri, float suprafata){
//	Cafenea cafe;
//	
//	cafe.nume = (char*)malloc(strlen(nume) + 1);
//	strcpy(cafe.nume, nume);
//	cafe.nrLocuri = nrLocuri;
//	cafe.suprafata = suprafata;
//	
//	return cafe;
//}
//
//void afisareCafenea(Cafenea c) {
//	printf("Cafeneaua %s, are %d locuri si o suprafata de %.2f\n", c.nume, c.nrLocuri, c.suprafata);
//}
//
//void afisareInceputLista(ListaDubla lista) {
//	Nod* nod = lista.cap;
//	while (nod) {
//		printf("Cafeneaua %s, are %d locuri si o suprafata de %.2f\n", nod->cafenea.nume, nod->cafenea.nrLocuri, nod->cafenea.suprafata);
//		nod = nod->next;
//	}
//}
//
//ListaDubla stergeCafeneaDupaNume(ListaDubla listaDubla, const char* nume) {
//	Nod* nod = listaDubla.cap;
//	if (nume == NULL) {
//		return listaDubla;
//	}
//	while (nod && strcmp(nod->cafenea.nume, nume) != 0) {
//		nod = nod->next;
//	}
//	if (nod != NULL) {
//		if (nod->next == NULL && nod->prev == NULL) {
//			listaDubla.cap = NULL;
//			listaDubla.coada = NULL;
//		}
//
//		else {
//			if (nod->prev == NULL) {
//				listaDubla.cap = nod->next;
//				listaDubla.cap->prev = NULL;
//			}
//			else if (nod->next == NULL) {
//				listaDubla.coada = nod->prev;
//				listaDubla.coada->next = NULL;
//			}
//			else {
//				nod->prev->next = nod->next;
//				nod->next->prev = nod->prev;
//			}
//		}
//		free(nod->cafenea.nume);
//		free(nod);
//	}
//	return (listaDubla);
//}
//
//int nrLocuriTotal(ListaDubla listaDubla) {
//	if (listaDubla.cap != NULL) {
//		int nrLocuri = 0;
//		Nod* nod = listaDubla.cap;
//		while (nod != NULL) {
//			nrLocuri += nod->cafenea.nrLocuri;
//			nod = nod->next;
//		}
//		return nrLocuri;
//	}
//}
//
//ListaDubla stergeListaDubla(ListaDubla listaDubla) {
//	while (listaDubla.cap != NULL) {
//		free(listaDubla.cap->cafenea.nume);
//		Nod* aux = listaDubla.cap;
//		listaDubla.cap = listaDubla.cap->next;
//		free(aux);
//	}
//	listaDubla.cap = NULL;
//}
//
//void main() {
//
//	ListaDubla listaDubla;
//	listaDubla.cap = NULL;
//	listaDubla.coada = NULL;
//
//	Cafenea cafenea = initializareCafenea("Tucano", 12, 20);
//	Cafenea cafenea2 = initializareCafenea("Teds", 17, 17.3);
//	Cafenea cafenea3 = initializareCafenea("Urban", 65, 33);
//	Cafenea sb = initializareCafenea("Sb", 25, 43);
//
//	inserareInceput(&listaDubla, cafenea);
//	inserareInceput(&listaDubla, cafenea2);
//	inserareInceput(&listaDubla, cafenea3);
//	inserareInceput(&listaDubla, sb);
//
//	afisareInceputLista(listaDubla);
//
//	printf("\n\n__________________________________________________\n\n");
//
//	listaDubla = stergeCafeneaDupaNume(listaDubla, "Tucano");
//	afisareInceputLista(listaDubla);
//
//	printf("\n\n__________________________________________________\n\n");
//
//	listaDubla = stergeCafeneaDupaNume(listaDubla, "Mangiaro");
//	afisareInceputLista(listaDubla);
//
//	printf("\n\n__________________________________________________\n\n");
//
//	listaDubla = stergeCafeneaDupaNume(listaDubla, "Urban");
//	afisareInceputLista(listaDubla);
//
//
//}