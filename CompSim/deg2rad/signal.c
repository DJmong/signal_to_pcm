#include <stdio.h>
#include <math.h>
#include "po_define.h"
#include "def_PI.h"



double sin_signal(po *a){
	double t = sin(2 * PI*(a->f)*(a->x) + (a->p));
	return t;
}



double cos_signal(po *a){
	double t= cos(2*PI*(a->f)*(a->x) + (a->p));
	return t;
}



double piano_signal(po *a){
	double t = 0;
	/*
	
	   /\
	  /  \____________
	 /   			  \
	/				   \____
		주파수 값으로 나눈 현재 값이  
	*/

	return t;
}
