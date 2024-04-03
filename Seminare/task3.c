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
	printf("Scoala cu denumirea %s are %d elevi si o medie de %.2f\n", scoala->denumire, scoala->nr_elevi, scoala->medie);
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

//----------------------------------------------Fisiere----------------------------------------------------------------------------//

//Scrieti intr-un program C functia care sa citeasca obiectele din fisier si sa le salveze intr-un vector.
void inserareScoala(Scoala** vectorScoli, int* dim, Scoala scoala) {
	Scoala* copie;
	int dimensiuneNoua = (*dim) + 1;
	copie = malloc(sizeof(Scoala) * dimensiuneNoua);
	for (int i = 0; i < (*dim); i++) {
		copie[i] = (*vectorScoli)[i];
	}
	copie[(*dim)] = scoala;
	(*dim) = dimensiuneNoua;
	if ((*vectorScoli) != NULL) {
		free((*vectorScoli));
	}
	(*vectorScoli) = copie;
}

void citireScoliDinFIsier(const char* nume_fisier, Scoala** vector, int* dim) {
	if (nume_fisier != NULL && strlen(nume_fisier) > 0) {
		FILE* f = fopen(nume_fisier, "r");
		if (f != NULL) {
			(*dim) = 0;
			char buffer[100];
			char delimitator[] = ",\n";
			while (fgets(buffer, 100, f) != NULL) {
				char* token;
				token = strtok(buffer, delimitator);
				Scoala scoala;
				scoala.denumire = (char*)malloc(strlen(token) + 1);
				strcpy(scoala.denumire, token);
				token = strtok(NULL, delimitator);
				scoala.nr_elevi = atoi(token);
				token = strtok(NULL, delimitator);
				scoala.medie = atoi(token);
				inserareScoala(vector, dim, scoala);
			}
			fclose(f);
		}
	}
}
//Scrieti o functie care va salva un obiect  intr-un fisier text.
void salveazaScoalaInFisier(Scoala* scoala, const char* nume_fisier) {
	
	if (scoala != NULL && strlen(nume_fisier) > 0) {
		FILE* f = fopen(nume_fisier, "a");
		if (f == NULL) {
			printf("Eroare: nu s-a putut deschide fisierul %s pentru scriere.\n", nume_fisier);
		}
		fprintf(f, "%s,", scoala->denumire);
		fprintf(f, "%d,", scoala->nr_elevi);
		fprintf(f, "%.2f", scoala->medie);

		fclose(f);
		printf("Obiectul de tip Scoala a fost salvat cu succes in fisierul %s.\n", nume_fisier);
	}
}



void afisareScoliCititeDinVector(Scoala* scoala) {
	printf("%s , %d, %.2f\n", scoala->denumire, scoala->nr_elevi, scoala->medie);
}

void afisareVectorScoli(Scoala* vector, int dim) {
	for (int i = 0; i < dim; i++) {
		afisareScoliCititeDinVector(&vector[i]);
	}
}

//Scoala* initializeazaScoala() {
//	Scoala* scoala = (Scoala*)malloc(sizeof(Scoala));
//	
//	char buffer[100];
//	fgets(buffer, 100, stdin);
//	scoala->denumire = (char*)malloc(strlen(buffer) + 1);
//	strcpy(scoala->denumire, buffer);
//
//	scanf("%s", &scoala->denumire);
//	scanf("%d", &scoala->nr_elevi);
//	scanf("%f", &scoala->medie);
//
//	return scoala;
//}

void initializeazaScoalaCuApelInMain(Scoala** scoala) {
	*scoala= (Scoala*)malloc(sizeof(Scoala));
	char buffer[100];
	printf("Introdu denumirea scolii: ");
	fgets(buffer, 100, stdin);
	(*scoala)->denumire = (char*)malloc(strlen(buffer) + 1);
	strcpy((*scoala)->denumire, strtok(buffer,"\n"));
	printf("Introdu nr de elevi: ");
	scanf("%d", &((*scoala)->nr_elevi));
	printf("Introdu media: ");
	scanf("%f", &((*scoala)->medie));
	
}

void initializeazaVectorScoliCuApelInMain(Scoala** vectorScoli, int nr_scoli) {
	*vectorScoli = (Scoala*)malloc(nr_scoli * sizeof(Scoala));
	for (int i = 0; i < nr_scoli; i++) {
		printf("Introdu denumirea scolii: ");
		char buffer[100];
		fgets(buffer, 100, stdin);
		
		(*vectorScoli)[i].denumire = (char*)malloc(strlen(buffer) + 1);
		strcpy((*vectorScoli)[i].denumire, strtok(buffer, "\n"));
		printf("Introduceti nr de elevi: ");
		scanf("%d", &((*vectorScoli)[i].nr_elevi));
		printf("Introduceti media: ");
		scanf("%f", &((*vectorScoli)[i].medie));
		printf("\n");

		fgetc(stdin);
	}
}

//Scrieti o functie care va salva un vector de obiecte intr-un fisier text.
void salveazaVectorScoliInFisier(Scoala* vectorScoli, int nr_scoli, const char* nume_fisier) {

	if (vectorScoli!= NULL && strlen(nume_fisier) > 0) {
		FILE* f = fopen(nume_fisier, "a");
		if (f == NULL) {
			printf("Eroare: nu s-a putut deschide fisierul %s pentru scriere.\n", nume_fisier);
		}

		for (int i = 0; i < nr_scoli; i++) {
			fprintf(f, "%s,", vectorScoli[i].denumire);
			fprintf(f, "%d,", vectorScoli[i].nr_elevi);
			fprintf(f, "%.2f\n", vectorScoli[i].medie);
		}
		
		fclose(f);
		printf("Vectorul de tip Scoala a fost salvat cu succes in fisierul %s.\n", nume_fisier);
	}
}

void dezalocaMemorie(Scoala* scoala, int dim) {
	if (scoala->denumire != NULL) {
		for (int i = 0; i < dim; i++) {
			free(scoala[i].denumire);
		}
	}
	free(scoala);
}

void main() {

	/*int nr_scoli;
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
	}*/

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
	/*int nr_scoli2;
	printf("Introduceti numarul de scoli: ");
	scanf("%d", &nr_scoli2);
	fgetc(stdin);
	printf("\n");
	Scoala* scoala2 = citesteScoli(nr_scoli2);

	Scoala* scoalaConcatenata = concateneazaScoli(scoala, nr_scoli, scoala2, nr_scoli2);
	printf("Scoli concatenate:\n");
	for (int i = 0; i < (nr_scoli + nr_scoli2); i++) {
		printf("%s, %d, %.2f\n", scoalaConcatenata[i].denumire, scoalaConcatenata[i].nr_elevi, scoalaConcatenata[i].medie);
	}*/

	//int dim = 0;
	//Scoala* scoala = NULL;
	//citireScoliDinFIsier("scoli.txt", &scoala, &dim);
	//afisareVectorScoli(scoala, dim);

	printf("\n____________________________________________________\n");
	int nr_scoli;
	printf("Introduceti nr de scoli:\n");
	scanf("%d", &nr_scoli);
	getchar();

	Scoala* scoliAdaugateInVector;
	
	initializeazaVectorScoliCuApelInMain(&scoliAdaugateInVector, nr_scoli);
	salveazaVectorScoliInFisier(scoliAdaugateInVector, nr_scoli, "scoli.txt");

	for (int i = 0; i < nr_scoli; i++) {
		free(scoliAdaugateInVector[i].denumire);
	}
	free(scoliAdaugateInVector);
	/*initializeazaScoalaCuApelInMain(&scoalaAdaugata);
	afiseazaScoala(scoalaAdaugata);
	salveazaScoalaInFisier(scoalaAdaugata, "scoli.txt");*/
	//afisareVectorScoli(scoala, dim);

	//dezalocaMemorie(scoala, dim);
	


}