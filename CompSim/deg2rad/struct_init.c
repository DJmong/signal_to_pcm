
#include "po_define.h"
#include "def_PI.h"


void struct_init(po *po_a, double f, double p, double a, double x, double fs){
	po_a->y_type = 'r';
	po_a->f = f;
	po_a->p = p;
	po_a->a = a;
	po_a->x = x;
	po_a->fs =fs; //샘플링 주파수, 재생 시간에 관여
	//fs,t는 재생 시간에 관여함
	//f는 소리 높 낮이
	//a는 소리의 최대 크기
}