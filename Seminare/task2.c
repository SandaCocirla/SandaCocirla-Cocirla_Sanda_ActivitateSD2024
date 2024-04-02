#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Scoala Scoala;
struct Scoala {
	char* denumire;
	int nr_elevi;
	float medie;
};

Scoala* citesteScoli(int nr_scoli) {
	Scoala* scoli = (Scoala*)malloc(nr_scoli * sizeof(Scoala));
	if (scoli == NULL) {
		printf("Eroare la alocarea memoriei pentru articolul construit ");
	}

	for (int i = 0; i < nr_scoli; i++) {
		printf("Introdu denumirea scolii: ");
		char buffer[100];
		fgets(buffer, sizeof(buffer), stdin);
		scoli[i].denumire = malloc(strlen(buffer) * (sizeof(char) + 1));
		strcpy(scoli[i].denumire, buffer);

		printf("Introdu numarul de elevi: ");
		scanf("%d", &(scoli[i].nr_elevi));

		printf("Introdu media scolara: ");
		scanf("%f", &(scoli[i].medie));
		fgetc(stdin);
		printf("\n");
	}
	return scoli;
}

Scoala* calculeazaScoalaNrMaxElevi(Scoala* scoli, int nr_scoli) {
	int nr_maxim_elevi = 0;
	Scoala* scoalaNrMax = NULL;
	for (int i = 0; i < nr_scoli; i++) {
		if (scoli[i].nr_elevi > nr_maxim_elevi) {
			nr_maxim_elevi = scoli[i].nr_elevi;
			scoalaNrMax = &scoli[i];
		}
	}
	return scoalaNrMax;
}

void modificaDenumireScoalacuNrMaxElevi(Scoala* scoala, const char* denumireScoala) {
	scoala->denumire = denumireScoala;
}

void afiseazaScoala(Scoala* scoala) {
	printf("Scoala cu denumirea %s are %d elevi si o medie de %.2f", scoala->denumire, scoala->nr_elevi, scoala->medie);
}

//----------------------------------------------Vectori----------------------------------------------------------------------------//

//Realizati o functie care va creea un nou vector în care va copia dintr-un vector primit ca parametru obiectele care indeplinesc o anumita conditie. Stabiliti voi conditia in functie de un atribut sau doua atribute.
void copiazaScoalaCuMediaPesteSapte(Scoala* scoala, int nr_scoli) {
	Scoala* scoalaCopiata = (Scoala*)malloc(nr_scoli * sizeof(Scoala));
	if (scoalaCopiata == NULL) {
		printf("Nu exist[ suficient spatiu inmemorie");
	}
	int indexScoalaCopiata = 0;
	for (int i = 0; i < nr_scoli; i++) {
		if (scoala[i].medie > 7) {
			scoalaCopiata[indexScoalaCopiata] = scoala[i];
			indexScoalaCopiata++;
		}
	}

	printf("Scolile care au media mai mare decat 7 sunt: \n");
	for (int i = 0; i < nr_scoli; i++) {
		printf("Scoala %s are media %.2f\n", scoalaCopiata[i].denumire, scoalaCopiata[i].medie);
	}

	free(scoalaCopiata);
}

//Realizati o functie care muta intr-un nou vector obiectele care indeplinesc o alta conditie fata de cerinta precedenta.
Scoala* mutaScoalaCuNrMaiMare(Scoala* scoala, int nr_scoli, int* nr_scoli_nou) {
	Scoala* scoalaMutata = (Scoala*)malloc(nr_scoli * sizeof(Scoala));
	if (scoalaMutata == NULL) {
		printf("Nu exista suficienta memorie");
	}

	int indexScoalaMutata = 0;
	for (int i = 0; i < nr_scoli; i++) {
		if (scoala[i].nr_elevi > 200) {
			scoalaMutata[indexScoalaMutata] = scoala[i];
			indexScoalaMutata++;
		}

	}
	*nr_scoli_nou = indexScoalaMutata;
	return scoalaMutata;
}

//Realizati o functie care concateneaza doi vectori.
Scoala* concateneazaScoli(Scoala* scoala1, int nr_scoli1, Scoala* scoala2, int nr_scoli2) {
	Scoala* scoliConcatenate = (Scoala*)malloc((nr_scoli1 + nr_scoli2) * sizeof(Scoala));
	if (scoliConcatenate == NULL) {
		printf("Nu exista suficienta memorie");
	}
	int indexScoliConcatenate = 0;
	for (int i = 0; i < nr_scoli1; i++) {
		scoliConcatenate[indexScoliConcatenate] = scoala1[i];
		indexScoliConcatenate++;
	}
	for (int i = 0; i < nr_scoli2; i++) {
		scoliConcatenate[indexScoliConcatenate] = scoala2[i];
		indexScoliConcatenate++;
	}
	return scoliConcatenate;
}

void dezalocaMemorie(Scoala* scoala) {
	if (scoala->denumire != NULL) {
		free(scoala->denumire);
	}
	free(scoala);
}

void main() {

	int nr_scoli;
	printf("Introduceti numarul de scoli: ");
	scanf("%d", &nr_scoli);
	fgetc(stdin);
	printf("\n");

	Scoala* scoala = citesteScoli(nr_scoli);

	for (int i = 0; i < 2; i++) {
		printf("\nScoala citita:");
		printf("\nDesnumire: %s", scoala[i].denumire);
		printf("Numar de elevi: %d", scoala[i].nr_elevi);
		printf("\nMedie:%.2f", scoala[i].medie);
		printf("\n");
	}

	printf("\n__________________________________________________\n");
	/*printf("Afisare numar maxim elevi din scolile citite de la tastatura\n");
	Scoala* scoalaMAX = calculeazaScoalaNrMaxElevi(scoala, nr_scoli);
	printf("Scoala %s are nr max de elevi = %d", scoala->denumire, scoala->nr_elevi);

	modificaDenumireScoalacuNrMaxElevi(scoalaMAX, "denumire noua");
	printf("\nDenumirea scolii cu nr max de elevi dupa modificare este: %s", scoalaMAX->denumire);

	printf("\nAfiseaza scoala pe care o vrea zamfi\n");
	afiseazaScoala(scoalaMAX);*/
	//copiazaScoalaCuMediaPesteSapte(scoala, nr_scoli);


	/*int nr_scoli_nou=0;
	Scoala* scoalaMutata = mutaScoalaCuNrMaiMare(scoala, nr_scoli, nr_scoli_nou);
	printf("Scoala mutata:\n");
	for (int i = 0; i < nr_scoli_nou; i++) {
		printf("Scoala %s, Nr. elevi %d, Medie %.2f\n", scoalaMutata[i].denumire, scoalaMutata[i].nr_elevi, scoalaMutata[i].medie);
	}

	free(scoalaMutata);*/
	int nr_scoli2;
	printf("Introduceti numarul de scoli: ");
	scanf("%d", &nr_scoli2);
	fgetc(stdin);
	printf("\n");
	Scoala* scoala2 = citesteScoli(nr_scoli2);

	Scoala* scoalaConcatenata = concateneazaScoli(scoala, nr_scoli, scoala2, nr_scoli2);
	printf("Scoli concatenate:\n");
	for (int i = 0; i < (nr_scoli + nr_scoli2); i++) {
		printf("%s, %d, %.2f\n", scoalaConcatenata[i].denumire, scoalaConcatenata[i].nr_elevi, scoalaConcatenata[i].medie);
	}
}