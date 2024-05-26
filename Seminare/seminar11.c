//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//
//typedef struct Cinema Cinema;
//typedef struct Nod Nod;
//
//struct Cinema {
//	int id;
//	int nrFilme;
//	char** listaFilme;
//};
//
//struct Nod {
//	Cinema info;
//	Nod* st;
//	Nod* dr;
//};
//
//Cinema citireCinema(FILE* f) {
//	Cinema c;
//	fscanf(f, "%d", &c.id);
//	fscanf(f, "%d", &c.nrFilme);
//	if (c.nrFilme !=0) {
//		c.listaFilme = (char**)malloc(sizeof(char*) * c.nrFilme);
//		for (int i = 0; i < c.nrFilme; i++) {
//			char buffer[100];
//			fscanf(f, "%s", buffer);
//			c.listaFilme[i] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//			strcpy(c.listaFilme[i], buffer);
//		}
//	}
//	else {
//		c.listaFilme = NULL;
//	}
//	return c;
//}
//
//void afisareCinema(Cinema c) {
//	printf("Cinematograful cu id-ul %d are %d filme in derulare: ", c.id, c.nrFilme);
//	for (int i = 0; i < c.nrFilme; i++) {
//		printf("%s ", c.listaFilme[i]);
//	}
//	printf("\n");
//}
//
//void afisareArborePreordine(Nod* rad) {
//	if (rad) {
//		afisareCinema(rad->info);
//		afisareArborePreordine(rad->st);
//		afisareArborePreordine(rad->dr);
//	}
//}
//
//void afisareArboreInordine(Nod* rad) {
//	if (rad) {
//		afisareArboreInordine(rad->st);
//		afisareCinema(rad->info);
//		afisareArboreInordine(rad->dr);
//	}
//}
//
//int calculFilmeRedate(Nod* rad) {
//	if (rad) {
//		int suma = rad->info.nrFilme;
//		suma += calculFilmeRedate(rad->st);
//		suma += calculFilmeRedate(rad->dr);
//		return suma;
//	}
//	else {
//		return 0;
//	}
//}
//
//Nod* rotireDreapta(Nod* rad) {
//	if (rad) {
//		Nod* aux = rad->st;
//		rad->st = aux->dr;
//		aux->dr = rad;
//		return aux;
//	}
//	else {
//		return rad;
//	}
//}
//
//Nod* rotireStanga(Nod* rad) {
//	if (rad) {
//		Nod* aux = rad->dr;
//		rad->dr = aux->st;
//		aux->st = rad;
//		return aux;
//	}
//	else {
//		return rad;
//	}
//}
//
//int calculInaltime(Nod* rad) {
//	if (rad) {
//		int inaltimeSt = calculInaltime(rad->st);
//		int intinaltimeDr = calculInaltime(rad->dr);
//		return 1 + (inaltimeSt > intinaltimeDr ? inaltimeSt : intinaltimeDr);
//	}
//	else {
//		return 0;
//	}
//}
//
//int calculGradEchilibru(Nod* rad) {
//	if (rad == NULL) {
//		return 0;
//	}
//	else {
//		calculInaltime(rad->st) - calculInaltime(rad->dr);
//	}
//}
//
//void inserareInArbore(Nod** radacina, Cinema c) {
//	if (*radacina) {
//		if ((*radacina)->info.id > c.id) {
//			inserareInArbore(&((*radacina)->st), c);
//		}
//		else {
//			inserareInArbore(&((*radacina)->dr), c);
//		}
//		int grad = calculGradEchilibru(*radacina);
//
//		if (grad == 2) {
//			int gradCopil = calculGradEchilibru((*radacina)->st);
//			if (gradCopil < 0) {
//				(*radacina)->st = rotireStanga((*radacina)->st);
//			}
//			*radacina = rotireDreapta(*radacina);
//		}
//		else if (grad == -2) {
//			int gradCopil = calculGradEchilibru((*radacina)->dr);
//			if (gradCopil > 0) {
//				(*radacina)->dr = rotireDreapta((*radacina)->dr);
//			}
//			*radacina = rotireStanga(*radacina);
//		}
//	}
//	else {
//		Nod* nod = (Nod*)malloc(sizeof(Nod));
//		nod->dr = NULL;
//		nod->st = NULL;
//		nod->info = c;
//		*radacina = nod;
//	}
//}
//Nod* citireFisier(const char* fisier) {
//	Nod* radacina = NULL;
//	if (fisier != NULL && strlen(fisier) != 0) {
//		FILE* f = fopen(fisier, "r");
//		if (f != NULL) {
//			int dim = 0;
//			fscanf(f, "%d", &dim);
//			for (int i = 0; i < dim; i++) {
//				Cinema cinema = citireCinema(f);
//				inserareInArbore(&radacina, cinema);
//			}
//			fclose(f);
//		}
//	}
//	return radacina;
//}
//
//void stergeArbore(Nod** rad) {
//	if (rad) {
//		stergeArbore(&((*rad)->st));
//		stergeArbore(&((*rad)->dr));
//		if ((*rad)->info.listaFilme=!NULL) {
//			for (int i = 0; i < (*rad)->info.nrFilme; i++) {
//				free((*rad)->info.listaFilme[i]);
//			}
//			free((*rad)->info.listaFilme);
//		}
//		free(*rad);
//		*rad = NULL;
//	}
//}
//
//Cinema nrMaxFilme(Nod* radacina) {
//	if (radacina) {
//		Cinema cinemaMax = radacina->info;
//		Cinema cinemaStanga = nrMaxFilme(radacina->st);
//		Cinema cinemaDreapta = nrMaxFilme(radacina->dr);
//		if (cinemaStanga.nrFilme > cinemaDreapta.nrFilme) {
//			cinemaMax = cinemaStanga;
//		}
//		if (cinemaDreapta.nrFilme > cinemaStanga.nrFilme) {
//			cinemaMax = cinemaDreapta;
//		}
//		return cinemaMax;
//	}
//	else {
//		Cinema c;
//		c.id = -1;
//		c.nrFilme = 0;
//		c.listaFilme = NULL;
//		return c;
//	}
//}
//
//void main() {
//	Nod* arbore = citireFisier("cinema.txt");
//	afisareArborePreordine(arbore);
//	printf("\n\nNumar filme: %d\n", calculFilmeRedate(arbore));
//
//	Cinema cinema = nrMaxFilme(arbore);
//	printf("\nCinema cu cele mai multe filme:\n");
//	afisareCinema(cinema);
//
//
//
//}