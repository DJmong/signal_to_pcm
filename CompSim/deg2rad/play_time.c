#include "po_define.h"

int play_time(po *a){

	double number = a->t*a->fs;
	return (int)number;
}