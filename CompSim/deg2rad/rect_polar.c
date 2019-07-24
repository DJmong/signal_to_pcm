#include <stdio.h>
#include <math.h>
#include "po_define.h"
#include "def_PI.h"
double rad2deg(double theta_rad);
void rect2polar(po *a){
	double r;
	double theta;

	if (a->y_type == 'p'){
		printf("이미 극 좌표입니다");
	}
	else{
		r = sqrt(a->x*a->x + a->y*a->y);
		if (a->x < 0&&a->y>=0)
			theta = atan(a->y / a->x)+PI;
		else if (a->x < 0 && a->y < 0)
			theta = atan(a->y / a->x) - PI;
		else if (a->x == 0 && a->y > 0)
			theta = (float)PI / 2;
		else if (a->x == 0 && a->y < 0)
			theta = -PI / 2;
		else if (a->x == 0 && a->y == 0)
			theta = 0;
		else
			theta = atan(a->y / a->x);

		theta = rad2deg(theta);

		a->x = r;
		a->y = theta;
		a->y_type = 'p';
	}
}

void polar2rect(po *a){
	if (a->y_type == 'r'){
		printf("이미 직교좌표입니다");
	}
	else{
		a->x = a->x*cos(a->y);
		a->y = a->x*sin(a->y);
	}

}