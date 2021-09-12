#include "Odometry.h"

float g_x = 0, g_y = 0, g_angle = 0;

uint8_t Odometry_Init(void){
    g_x = 0;
    g_y = 0;
    g_angle = 0;

    return 0;
}

void Odometry(void){
    int cpt_l = (int)getLeftTicks();
	int cpt_r = (int)getRightTicks();

	float dDistance =  (cpt_l * L_COEF + cpt_r * R_COEF)/2;
	float dAngle = (cpt_r * R_COEF - cpt_l * L_COEF)/ENTRAXE;

	g_x += dDistance * cos(g_angle);
	g_y += dDistance * sin(g_angle);
	g_angle += dAngle;

	if(g_angle > M_PI)
		g_angle = g_angle - (M_PI * 2.0f);

	if(g_angle < (-1) * M_PI)
		g_angle = g_angle + (M_PI * 2.0f);
}
