
#include "po_define.h"
#include "def_PI.h"


void struct_init(po *po_a, double f, double p, double a, double x, double fs){
	po_a->y_type = 'r';
	po_a->f = f;
	po_a->p = p;
	po_a->a = a;
	po_a->x = x;
	po_a->fs =fs; //���ø� ���ļ�, ��� �ð��� ����
	//fs,t�� ��� �ð��� ������
	//f�� �Ҹ� �� ����
	//a�� �Ҹ��� �ִ� ũ��
}