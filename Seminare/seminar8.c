//#define	_CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
////min heap si max heap
////structura liniara
//
//typedef struct Quizz Quizz;
//struct Quizz {
//	char* materie;
//	int grileGresite;
//};
//
//typedef struct Heap Heap;
//struct Heap {
//	Quizz* vector;
//	int dimensiune;
//	int dimensiuneTotala;
//};
//
//Heap initializareHeap(int nrElemente) {
//	Heap heap;
//	heap.vector = (Quizz*)malloc(sizeof(Quizz) * nrElemente);
//	heap.dimensiuneTotala = nrElemente;
//	heap.dimensiune = 0;
//	return heap;
//}
//
//Heap agaugaUnQuizzInHeap(Quizz quizz, Heap heap) {
//	if (heap.dimensiune < heap.dimensiuneTotala) {
//		heap.vector[heap.dimensiune] = quizz;//shallow copy
//		heap.dimensiune++;
//		//TO DO filtrare cand adaugam un element trebuie 
//	}
//	
//	return heap;
//}
//
//Quizz initializareQuizz(const char* materie, int grileGresite) {
//	Quizz quizz;
//	
//	quizz.materie = (char*)malloc(strlen(materie) + 1);
//	strcpy(quizz.materie, materie);
//	quizz.grileGresite = grileGresite;
//
//	return quizz;
//}
//
//void afisareQuizz(Quizz q) {
//	printf("La materia %s sunt %d grile gresite\n", q.materie, q.grileGresite);
//}
//
//void afisareHeap(Heap heap) {
//	for (int i = 0; i < heap.dimensiune; i++) {
//		afisareQuizz(heap.vector[i]);
//	}
//}
//
//void filtreazaHeap(Heap heap, int pozRadacina) {
//	int nodSt = pozRadacina * 2 + 1;
//	int nodDr = pozRadacina * 2 + 2;
//	int indexMin = pozRadacina;
//	if (nodSt < heap.dimensiune && heap.vector[nodSt].grileGresite < heap.vector[indexMin].grileGresite) {
//		indexMin = nodSt;
//	}
//	if (nodDr < heap.dimensiune && heap.vector[nodDr].grileGresite < heap.vector[indexMin].grileGresite) {
//		indexMin = nodDr;
//	}
//	if (indexMin != pozRadacina) {
//		Quizz aux;
//		 aux = heap.vector[pozRadacina];
//		heap.vector[pozRadacina] = heap.vector[indexMin];
//		heap.vector[indexMin] = aux;
//		if (indexMin * 2 + 1 < heap.dimensiune-1) {//daca nodul de la pozMin are copii
//			filtreazaHeap(heap, indexMin);
//		}
//		
//	}
//}
//Quizz extrageMinRadacina(Heap* heap) {
//	if (heap->dimensiune > 0) {
//		Quizz aux;
//		aux = heap->vector[0];
//		heap->vector[0] = heap->vector[heap->dimensiune - 1];
//		heap->vector[heap->dimensiune - 1] = aux;
//		//se schimba primul element cu ultimul
//		heap->dimensiune--;
//		//se ascunde elementul 
//		for (int i = (heap->dimensiune) / 2 - 1; i >= 0; i--) {
//			filtreazaHeap((*heap), i);
//		}
//		return aux;
//	}
//	else {
//		return initializareQuizz("N\A", -1);
//	}
//}
//
//void afisareTotalaHeap(Heap heap) {
//	for (int i = 0; i < heap.dimensiuneTotala; i++) {
//		afisareQuizz(heap.vector[i]);
//	}
//}
//
//void dezalocareTotalaHeap(Heap* heap) {//dezalocare de la vector
//	for (int i = 0; i < heap->dimensiuneTotala; i++) {
//		free(heap->vector[i].materie);
//	}
//	free(heap->vector);
//	heap->vector = NULL;
//	heap->dimensiune = 0;
//	heap->dimensiuneTotala = 0;
//}
//
//void main() {
//
//	Heap heap;
//	heap = initializareHeap(6);
//
//	heap.vector[0] = initializareQuizz("SDD", 3);
//	heap.vector[1] = initializareQuizz("CTS", 7);
//	heap.vector[2] = initializareQuizz("Java", 5);
//	heap.vector[3] = initializareQuizz("POO", 2);
//	heap.vector[4] = initializareQuizz("Android", 9);
//	heap.vector[5] = initializareQuizz("BD", 4);
//
//	heap.dimensiune = 6;
//	afisareHeap(heap);
//	for (int i = (heap.dimensiune) / 2 - 1; i >= 0; i--) {
//		filtreazaHeap(heap, i);
//	}
//	printf("\n");
//	afisareHeap(heap);
//
//	printf("\n\n");
//	afisareQuizz(extrageMinRadacina(&heap));
//	afisareQuizz(extrageMinRadacina(&heap));
//	afisareHeap(heap);
//	printf("\n\n");
//	afisareHeap(heap);
//	printf("\n\n");
//	afisareTotalaHeap(heap);
//
//	dezalocareTotalaHeap(&heap);
//
//}