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
void make_sound(short *buf,po *po_a){
	int i;
	int j = 0;
	int number;
	int f[] = { C, E, G, C, E, G, A, A, A, G , F, F, F, E, E, E, D, D, D, C };
	int f_cont[] = { 2, 2, 2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1 };
	int f_size = sizeof(f) / sizeof(int);
	int count=0;
	number = _get_number(f_cont, sizeof(f_cont) / sizeof(int), po_a->fs);

	buf = (short*)malloc(number*sizeof(short));
	
	for (j = 0; j < f_size; j++){
		po_a->f = 440 * pow(2, (f[j] - 49) / (double)12);
		
		
		for (i = 0; i < po_a->fs/f_cont[j]; i++){
			//다음 음 계산
			po_a->x += 2 * PI / po_a->fs;
			
			if (i < po_a->fs*0.8){
				buf[count] = (short)(po_a->a*sin_signal(po_a));
			}
			count++;
		}
		if (j!=f_size-1)
		count += (int)(po_a->fs*0.2);


	}
	

	file_write(buf, number, 'w');
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

