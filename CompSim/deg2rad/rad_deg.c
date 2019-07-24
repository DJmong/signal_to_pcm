#define _CRT_SECURE_NO_WARNINGS
#include "def_PI.h"
#include <stdio.h>

double rad2deg(double theta_rad){
	double theta_deg;

	theta_deg = 180*theta_rad/PI;

	return theta_deg;
}

double deg2rad(double theta_deg){
	double theta_rad;

	theta_rad = PI * theta_deg / 180;

	return theta_rad;
}

