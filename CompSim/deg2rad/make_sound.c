#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "po_define.h"
#include "def_PI.h"
#include "rect_polar.h"
#include "rad_deg.h"
#include "signal.h"
#include "octave.h"
#include "file_io.h"

static int _get_number(int f_cont[], int cont_size, double fs);
void struct_init(po *po_a, double f, double p, double a, double x, double fs);
static void _make_octave(int f_size, int f_val[], int f_cont[], po *po_a, short x[]);
void make_sound(){
	po *po_a = (po*)malloc(sizeof(po));
	struct_init(po_a, 271, 0, 11000, 0, 44100);

	int i;			//loop
	int j = 0;		//loop
	int number;		//sizeof x
	int f_val[] = { C, E, G, C, E, G, A, A, A, G , F, F, F, E, E, E, D, D, D, C }; //octave
	int f_cont[] = { 2, 2, 2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1 }; 
	int f_size = sizeof(f_val) / sizeof(int);

	number = _get_number(f_cont, sizeof(f_cont) / sizeof(int), po_a->fs);

	short *x = (short*)malloc(number*sizeof(short));
	
	_make_octave(f_size, f_val, f_cont, po_a, x);
	

	file_write(x, number, 'w');

	free(po_a);
	free(x);
}

static int _get_number(int f_cont[],int cont_size, double fs){
	int i;
	int result = 0;
	for (i = 0; i < cont_size; i++){
		result += (int)fs / f_cont[i];
	}
	result += (int)((cont_size-1)*fs*0.2);
	return result;
}

static void _make_octave(int f_size, int f_val[], int f_cont[], po *po_a, short x[]){
	int i, j;
	int count = 0;
	for (j = 0; j < f_size; j++){
		po_a->f = 440 * pow(2, (f_val[j] - 49) / (double)12);

		for (i = 0; i < po_a->fs / f_cont[j]; i++){
			//다음 음 계산
			po_a->x += 2 * PI / po_a->fs;

			if (i < po_a->fs*0.8) x[count] = (short)(po_a->a*sin_signal(po_a));
			else x[count] = 0;
			count++;
		}

		if (j != f_size-1)
			count += (int)(po_a->fs*0.2);
	}
}