#ifndef GRAVITY_CALC_H
#define GRAVITY_CALC_H

#include <cmath>
#include <math.h>

using namespace std;
const float G = 6.674184*pow(10, (-11));
const float pi = 3.14159;

float gravity_strenght(float massA, float massB, float distance) {
    float gratational_force = G*((massA*massB)/pow(distance, 2));
    return gratational_force;
}

float DeltaV_calc(float eng_impulse, float gravity_aceleration, float FullMass, float EmptyMass){
    float DeltaV = (eng_impulse*gravity_aceleration*log((FullMass/EmptyMass)));
    return DeltaV;
}

float reach_orbit_calc(float astro_mass, float distance_to_planet_center){
    float NeededVel = ((G*astro_mass)/distance_to_planet_center);
    return NeededVel;
}

float gravity_art_satelit(float Max_mass , float Min_mass, float distance){
    float v = sqrt((G + ((Min_mass+Max_mass)/2))/distance);
    return v;
}

float angular_velocity_angular_momenty(float time_of_revolution){
    float omega = ((2*pow(pi, 2))/pow(time_of_revolution, 2));
    return omega;
}

float orbit_period_time(float massF, float massE, float distance){
    const float G = pow(6.67, (-11));
    float pi  = 3.14159;
    float t = sqrt((4*pow(pi, 2))/G*((massE+massF)/2)*pow(distance, 3));
    return t;
}

float thirty_kepler_law(float MassF, float MassE, float distance){
    float MassM = (((MassF + MassE)/2));
    float k = (orbit_period_time(MassF, MassE, distance)/pow(distance, 3));
    return k;
}
#endif