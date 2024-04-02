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

//Realizati o functie cu ajutorul careia sa cititi de la tastatura un articol de tipul construit de voi. Funcția returnează obiectul citit.
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

//Realizati o functie care calculeaza ceva pentru un obiect de tipul implementat de voi. (o medie sau o suma, un maxim, un minim...sau orice altceva)
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

//Realizati o functie care modifica pentru un obiect primit ca parametru, un anumit camp.noua valoare este primita ca parametru.
void modificaDenumireScoalacuNrMaxElevi(Scoala* scoala, const char* denumireScoala) {
	scoala->denumire = denumireScoala;
}

//Realizați o funcție care afișează un obiect de tipul creat. Afișarea se face la console, și sunt afișate toate informațiile.
void afiseazaScoala(Scoala* scoala) {
	printf("Scoala cu denumirea %s are %d elevi si o medie de %.2f", scoala->denumire, scoala->nr_elevi, scoala->medie);
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
	printf("Afisare numar maxim elevi din scolile citite de la tastatura\n");
	Scoala* scoalaMAX = calculeazaScoalaNrMaxElevi(scoala, nr_scoli);
	printf("Scoala %s are nr max de elevi = %d", scoala->denumire, scoala->nr_elevi);

	modificaDenumireScoalacuNrMaxElevi(scoalaMAX, "denumire noua");
	printf("\nDenumirea scolii cu nr max de elevi dupa modificare este: %s", scoalaMAX->denumire);

	printf("\nAfiseaza scoala pe care o vrea zamfi\n");
	afiseazaScoala(scoalaMAX);
}
