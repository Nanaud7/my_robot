#include "Control.h"

// Début Test
double xTarget = -10;
double yTarget = 1;
// Fin Test

int state = ROTATION;
double relativeAngleInitial = 0;
double distanceToTargetInitial = 0;

char bufferCtrl[32] = "";

void robotControl(){
    Odometry(); // Odométrie

    // Calcul de la distance séparant le robot de la cible
    double distanceToTarget = sqrt(pow(xTarget-g_x,2) + pow(yTarget-g_y,2));

    // Calcul de l'angle de rotation à effectuer pour orienter le robot vers la cible
    double angleToTarget = atan2(yTarget - g_y, xTarget - g_x);
    sprintf(bufferCtrl, "angleToTarget = %lf", angleToTarget);
    nRF_Write(bufferCtrl);
    //nRF_EnQ(myQueue, bufferCtrl);

    switch (state)
    {
    case STAND_BY :
        Motor_Disable();
        break;

    case ROTATION :
        controlRotation(angleToTarget);
        break;

    case MOVE :
        controlMove(distanceToTarget, angleToTarget);
        break;

    default:
        state = STAND_BY;
        break;
    
    }
}

double robotControlSpeed(double x, double a){
    double speed = atan(-x*(x-1)*a) / atan(0.25*a);
    return speed;
}

uint8_t controlRotation(double angleToTarget){
        double relativeAngle = angleToTarget - g_angle;

        // Angle à parcourir lors de cette rotation
        if (relativeAngleInitial == 0){
            relativeAngleInitial = relativeAngle;
        }
        //relativeAngle = angleToPiPi(relativeAngle);

        // Calcul de la progrssion normalisée
        double progression = 1 - relativeAngle/relativeAngleInitial;
	    progression = progression<=1?progression:1;
	    progression = progression>=0?progression:0;

        // Choix du sens de rotation
        if (relativeAngle > 0){
            Motor_robotRotLeft();
        } else {
            Motor_robotRotRight();
        }

        // Calcul de la vitesse
        double speed = ROT_RPM_MAX * robotControlSpeed(progression, 30) + 1;
        Motor_setSpeed(speed);

        // Condition d'arrêt
        if (progression > 0.99){
            //Motor_Disable();
            state = STAND_BY;
            relativeAngleInitial = 0;
        }

        return 0;
}

uint8_t controlMove(double distanceToTarget, double angleToTarget){
    if (distanceToTargetInitial == 0){
        distanceToTargetInitial = distanceToTarget;
    }

    double progression = 1 - (distanceToTarget / distanceToTargetInitial);
    progression = progression<=1?progression:1;
    progression = progression>=0?progression:0;

    Motor_robotForward();

    double speed = MOV_RPM_MAX * robotControlSpeed(progression, 40) + 1;

    double angleError = angleToPiPi(angleToTarget - g_angle) / M_PI;

    if(angleError > 0){
        Motor_setSpeedLeft(speed);
        Motor_setSpeedRight(speed * (1 - angleError));
    } else {
    	Motor_setSpeedLeft(speed * (1 - angleError));
    	Motor_setSpeedRight(speed);
    }

    // Condition d'arrêt
    if (progression > 0.95 || distanceToTarget < 30){
        //Motor_Disable();
        state = STAND_BY;
        distanceToTargetInitial = 0;
    }

    return 0;
}

double angleToZeroTwoPi(double angle) {
	return fmod(fmod(angle, M_PI) + 2*M_PI, 2*M_PI);
}

double angleToPiPi(double angle) {
	return angleToZeroTwoPi(angle + M_PI) - M_PI;
}