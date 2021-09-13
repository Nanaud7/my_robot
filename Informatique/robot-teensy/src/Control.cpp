#include "Control.h"

// Début Test
double xTarget = 0;
double yTarget = 10;
// Fin Test

int state = 0;
double relativeAngleInitial = 0;

void robotControl(){
    Odometry(); // Odométrie

    // Calcul de la distance séparant le robot de la cible
    double distanceToTarget = sqrt(pow(xTarget-g_x,2) + pow(yTarget-g_y,2));

    // Calcul de l'angle de rotation à effectuer pour orienter le robot vers la cible
    double angleToTarget = atan2(yTarget - g_y, xTarget - g_x);

    switch (state)
    {
    case STAND_BY :
        Motor_Disable();
        break;

    case ROTATION :
        double relativeAngle = angleToTarget - g_angle;

        // Angle à parcourir lors de cette rotation
        if (relativeAngleInitial == 0){
            relativeAngleInitial = relativeAngle;
        }

        // Calcul de la progrssion normalisée
        double progression = 1 - relativeAngle/relativeAngleInitial;
	    progression = progression<=1?progression:1;
	    progression = progression>=0?progression:0;

        // Choix du sens de rotation
        if (relativeAngle > 0){
            Motor_robotRotRight();
        } else {
            Motor_robotRotLeft();
        }

        // Calcul de la vitesse
        double speed = RPM_MAX * robotControlSpeed(progression, COEFF_A) + 0.5;
        Motor_setSpeed(speed);
        Motor_Enable();

        // Condition d'arrêt
        if (progression > 0.95){
            state = STAND_BY;
            relativeAngleInitial = 0;
        }


        break;

    case TRANSLATION :
        break;
    
    default:
        break;
    }
}

double robotControlSpeed(double x, double a){
    double speed = atan(-x*(x-1)*a) / atan(0.25*a);
    return speed;
}