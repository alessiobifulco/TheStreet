// alessio
// bifulco
// 0000990143
// B
// alessio.bifulco@studio.unibo.it

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct {
	int num;
	double x;
	double y;
	double z;
}typedef scatole;

struct {
	int in;
	int c;
}typedef appoggio;			//questa struct di appoggio, in un indice che mi servire per trovare la soluzione migliore e ce un contatore

int xsort(double* x, double* y) {				//ordino le scatole per x, in modo tale da poter andare una per una

	scatole* scatoleX = (scatole*)x;
	scatole* scatoleY = (scatole*)y;

	if (scatoleX->x > scatoleY->x) {
		return 1;
	}
	else if (scatoleX->x < scatoleY->x) {
		return -1;
	}
	else { 
		return 0; }
}

void load(FILE* f, scatole* s, appoggio* ap) {					//vado a caricare i valori della seconda struct e num che sarà il numero di ogni scatola
	//int a;
	//a = 0;
	int i;
	i = 0;
	//for(i = 0; i<dim<; i++ )
	while (fscanf(f, "%lf %lf %lf", &s[i].x, &s[i].y, &s[i].z) != EOF) {			//va avanti finche finisce il file, EOF -> end of file
		ap[i].c = 0;
		ap[i].in = -1;
		s[i].num = i;
		i++;
	}
}

void solution(int dim, scatole* s, appoggio* ap) {		//cerco la soluzione usand due for annidati, confronto y e z perchè sono già ordinate per x
	int i, j;											//nel indice in salvo in quale posizione si trova la scatola precedente
	//i = 0;								
	//j = 0;
	for (i = 1; i < dim; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (s[i].y > s[j].y && s[i].z > s[j].z) {
				if (ap[i].c <= ap[j].c) {
					ap[i].in = j;
					ap[i].c = ap[j].c + 1;				//viene incrementato il contatore c perchè contava uno in meno
				}

			}
		}

	}

}

int main(int argc, char* argv[]) {
	int dim, i, j;
	i = 0;
	dim = 0;
	j = 0;

	FILE* filein = stdin;								//apro il file
	if (argc > 1) {
		filein = fopen(argv[1], "r");
		if (filein == NULL) {
			fprintf(stderr, "can not open %s\n", argv[1]);
			return EXIT_FAILURE;
		}
	}
	fscanf(filein, "%d", &dim);

		scatole* s = (scatole*)calloc(dim, sizeof(scatole));					//alloco
		appoggio* ap = (appoggio*)calloc(dim, sizeof(appoggio));				//alloco

		load(filein, s, ap);
		
		qsort(s, dim, sizeof(scatole), xsort);		//qsort una funzione già presente nelle librerie di c
		

		solution(dim, s, ap);

		i = 0;
		do {											//serve per trovare la prima scatola, quella che contiene piu scatole
			if (ap[i].c > ap[j].c) {
				j = i;
			}
			i++;
		} while (i < dim);
	
		i = 0;
		printf("scatole %d \n", ap[j].c + 1);
		do {
			printf("scatola %d:  %f   %f  %f\n", s[j].num, s[j].x, s[j].y, s[j].z);
			j = ap[j].in;
		} while (i != 1 && j != -1);			//stampa finche non finiscono le scatole precedenti e poi stampo la precedente

		fclose(filein);
	
	return 0;
}
	
	
