#ifndef GRAVITY_CALC_H
#define GRAVITY_CALC_H

#include <cmath>
#include <math.h>

using namespace std;

float gravity_strenght(float massA, float massB, float distance) {
    const float G = pow(6.67, (-11)); // Gravitational constant in m^3 kg^-1 s^-2
    float gratational_force = G*((massA*massB)/pow(distance, 2));
    return gratational_force;
}

float DeltaV_calc(float eng_impulse, float gravity_aceleration, float FullMass, float EmptyMass){
    float DeltaV = (eng_impulse*gravity_aceleration*log((FullMass/EmptyMass)));
    return DeltaV;
}

float reach_orbit_calc(float astro_mass, float distance_to_planet_center){
    const float G = pow(6.67, (-11));
    float NeededVel = ((G*astro_mass)/distance_to_planet_center);
    return NeededVel;
}

float gravity_art_satelit(float Max_mass , float Min_mass, float distance){
    const float G = pow(6.67, (-11));
    float v = sqrt((G + ((Min_mass+Max_mass)/2))/distance);
    return v;
}

float angular_velocity_angular_momenty(float time_of_revolution){
    float pi = 3.14159;
    float omega = ((2*pow(pi, 2))/pow(time_of_revolution, 2));
    return omega;
}

float orbit_period_time(float massF, float massE, float distance){
    const float G = pow(6.67, (-11));
    float pi  = 3.14159;
    float t = sqrt((4*pow(pi, 2))/G*((massE+massF)/2)*pow(distance, 3));
    return t;
}

#endif