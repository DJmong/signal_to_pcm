#include <stdio.h>
#include <stdlib.h>
#include "po_define.h"
#include "def_PI.h"
#include <math.h>
#define MAX_AMP 32768


void struct_init(po *po_a, double f, double p, double a, double x, double fs);
void make_sound(short buf[], po *po_a);

void main(){
	po *po_a = (po*)malloc(sizeof(po));
	struct_init(po_a, 271, 0, 11000, 0, 44100);
	
	short *x=(short*)NULL;
	make_sound(x, po_a);

	free(po_a);
	free(x);

}

