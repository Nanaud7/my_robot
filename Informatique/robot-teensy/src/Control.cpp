#include "Control.h"

int state = ROTATION;
double relativeAngleInitial = 0;
double distanceToTargetInitial = 0;

char bufferCtrl[32] = "";

void robotControl(){
    // Odométrie
    Odometry();

    // Calcul de la distance séparant le robot de la cible
    double distanceToTarget = sqrt(pow(blueStrategy[indexStrategy].x - g_x ,2) + pow(blueStrategy[indexStrategy].y - g_y,2));

    // Calcul de l'angle de rotation à effectuer pour orienter le robot vers la cible
    double angleToTarget = atan2(blueStrategy[indexStrategy].y - g_y, blueStrategy[indexStrategy].x - g_x);

    if (angleToTarget > M_PI || angleToTarget < -M_PI)
        angleToTarget = angleToPiPi(angleToTarget);

    //sprintf(bufferCtrl, "angleT:%.2f", angleToTarget);
    //nRF_Write(bufferCtrl);

    //sprintf(bufferCtrl, "state:%d", state);
    //nRF_Write(bufferCtrl);

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

        //if (relativeAngle > M_PI || relativeAngle < -M_PI)
        //    relativeAngle = angleToPiPi(relativeAngle);

        //sprintf(bufferCtrl, "relAngle:%.2f", relativeAngle);
        //nRF_Write(bufferCtrl);

        // Angle à parcourir lors de cette rotation
        if (relativeAngleInitial == 0)
            relativeAngleInitial = relativeAngle;

        //relativeAngle = angleToPiPi(relativeAngle);

        //sprintf(bufferCtrl, "relAngleInit:%.2f", relativeAngleInitial);
        //nRF_Write(bufferCtrl);

        // Calcul de la progression normalisée
        double progression = 1 - relativeAngle/relativeAngleInitial;
	    progression = progression<=1?progression:1;
	    progression = progression>=0?progression:0;

        //sprintf(bufferCtrl, "progress:%.2f", progression);
        //nRF_Write(bufferCtrl);

        // Choix du sens de rotation
        if (relativeAngle > 0){
            Motor_robotRotLeft();
        } else {
            Motor_robotRotRight();
        }

        // Condition d'arrêt
        if (progression > 0.999){
            Motor_Disable();
            state = MOVE;
            relativeAngleInitial = 0;
        }
        else{
            // Calcul de la vitesse
            double speed = ROT_RPM_MAX * robotControlSpeed(progression, 20) + 0.75;
            Motor_setSpeed(speed);
            Motor_Enable();
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

    double speed = 0;

    if(distanceToTargetInitial < 50){
        speed = 10 * robotControlSpeed(progression, 10) + 0.75;
    } else{
        speed = MOV_RPM_MAX * robotControlSpeed(progression, 20) + 0.75;
    }

    double angleError = angleToPiPi(angleToTarget - g_angle) / M_PI;

    // Condition d'arrêt
    if (progression > 0.95){
        Motor_Disable();
        distanceToTargetInitial = 0;
        indexStrategy++;

        if (indexStrategy >= numberOfPoints)
            state = STAND_BY;
        else 
            state = ROTATION;
    }
    else{
        if(angleError > 0){
            Motor_setSpeedLeft(speed);
            Motor_setSpeedRight(speed * (1 - angleError));
        } else {
            Motor_setSpeedLeft(speed * (1 - angleError));
            Motor_setSpeedRight(speed);
        }
        Motor_Enable();
    }

    return 0;
}

double angleToZeroTwoPi(double angle) {
	return fmod(fmod(angle, M_PI) + 2*M_PI, 2*M_PI);
}

double angleToPiPi(double angle) {
	return angleToZeroTwoPi(angle + M_PI) - M_PI;
}