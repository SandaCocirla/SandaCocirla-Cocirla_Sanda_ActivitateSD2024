//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Scoala Scoala;
//struct Scoala {
//	char* denumire;
//	int nr_elevi;
//	float medie;
//};
//
//
//void inserareScoala(Scoala** vectorScoli, int* dim, Scoala scoala) {//tinem adresa pointerului de vector, avem nevoie de adresa dimensiunii vectorului, Structura pe care sa o putem initializa
//	Scoala* copie; //pointer la structura Svoala care va fi uutilizat pentru a crea o copie a vectorului existent in care va fi inserata noua structura
//	int dimensiuneNoua = (*dim) + 1; //se calculeaza noua dimensiune a vectorului dup[ inserarea unei structuri
//	copie = (Scoala*)malloc(sizeof(Scoala)*dimensiuneNoua); //se aloca memorie pentru noua copie a vectorului 
//	for (int i = 0; i < (*dim); i++) { //se copiaza fiecare element din vectorul original in noua copie a vectorului
//		copie[i] = (*vectorScoli)[i];
//	}
//	copie[(*dim)] = scoala; // se adauga noua structura la sfarsitul copiei vectorului
//	(*dim) = dimensiuneNoua; //se actualizeaza dimensiunea vectorului la noua dimensiune calculata
//	if ((*vectorScoli) != NULL) {//daca vectorul original nu este null, se elibereaza memoria alocata pentru aceasta, pt ca s-a creat copia noua
//		free((*vectorScoli));
//	}
//	(*vectorScoli) = copie;//se actualizeaza pointerul 
//}
////Scrieti intr-un program C functia care sa citeasca obiectele din fisier si sa le salveze intr-un vector.
//void citireScoalaDinFisierSiSalveazaInVector(Scoala** vector, int* dim, const char* nume_fisier) {
//	if (vector != NULL && strlen(nume_fisier) > 0) {
//		FILE* f = fopen(nume_fisier, "r");
//		if (f != NULL) {
//			(*dim) = 0;
//			char buffer[100];
//			char delimitator[] = ",\n";
//			while (fgets(buffer, 100, f) != NULL) {
//				char* token;
//				token = strtok(buffer, delimitator);
//				Scoala scoala;
//				scoala.denumire = (char*)malloc(strlen(token) + 1);
//				strcpy(scoala.denumire, token);
//				token = strtok(NULL, delimitator);
//				scoala.nr_elevi = atoi(token);
//				token = strtok(NULL, delimitator);
//				scoala.medie = atoi(token);
//				inserareScoala(vector, dim, scoala);
//			}
//		}
//		fclose(f);
//	}
//}
//
////Creati o functie care sa copieze (deep copy) elementele din vector intr-o matrice alocată dinamic. 
////Asezarea in matrice pe linii a obiectelor o faceti dupa un criteriu aplicat unui atribut. 
////Astfel veti obține mai multe clustere reprezentate de liniile matricei.
//
////void copiazaElementeDinVectorInMatrice(Scoala* vectorScoala, Scoala*** matrice, int dim, int* nr_linii, int* nr_coloane) {
////	int criteriu;
////	printf("Insereaza criteriul de departajare: ");
////	scanf("%d", &criteriu);
////	
////	int* elemente_pe_linii = malloc(sizeof(int) * criteriu);
////
////	for (int i = 0; i < criteriu; i++) {
////		elemente_pe_linii[i] = 0;
////	}
////
////	for (int i = 0; i < dim; i++) {
////		int pozitie = vectorScoala[i].nr_elevi % criteriu;
////		elemente_pe_linii[pozitie]++;
////	}
////
////	int categorii = 0;
////	for (int i = 0; i < criteriu; i++) {
////		if (elemente_pe_linii[i] > 0) {
////			categorii++;
////		}
////	}
////
////	*nr_linii = categorii;
////
////	*matrice = (Scoala**)malloc(sizeof(Scoala*) * categorii);
////
////	int linie = 0;
////
////	for (int i = 0; i < criteriu; i++) {
////		if (elemente_pe_linii[i] > 0) {
////			(*matrice)[linie] = malloc(sizeof(Scoala) * elemente_pe_linii[i]);
////			
////			int coloana = 0;
////			for (int j = 0; j < dim; j++) {
////				if (vectorScoala[j].nr_elevi % criteriu == i) {
////					(*matrice)[linie][coloana] = vectorScoala[j];
////					coloana++;
////				}
////			}
////			linie++;
////		}
////	}
////}
//
//
////void copiazaElementeDinVectorInMatrice(Scoala* vectorScoala, Scoala*** matrice, int dim, int nr_linii, int* nr_coloane) {
////	
////	*matrice = (Scoala**)malloc(nr_linii * sizeof(Scoala*));
////
////	int* elementePeCategorie = malloc(nr_linii * sizeof(int));
////	for (int i = 0; i < dim; i++) {
////		if (vectorScoala[i].nr_elevi % 2 == 0) {
////			insereazaScoala()
////		}
////	}
////
////}
////int main() {}