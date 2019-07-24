#include <stdio.h>
#include <stdlib.h>
#include "rect_polar.h"
#include "rad_deg.h"
#include "signal.h"
#include "file_io.h"
#include <math.h>
#define MAX_AMP 32768


void struct_init(po *po_a, double f, double p, double a, double x, double fs, double t);
int play_time(po_a);

void main(){
	po *po_a = (po*)malloc(sizeof(po));

	struct_init(po_a, 261, 0, 11000, 0, 16000, 5);
	
	int number = play_time(po_a);

	short *x = (short*)malloc(sizeof(short)*number);
	int i;

	for (i = 0; i < number; i++){
		po_a->x += deg2rad(po_a->f);
		x[i] = po_a->a*sin_signal(po_a);
	}
	file_write(x, number, 'w');
	free(po_a);
	free(x);

}

