#ifndef GRAVITY_CALC_H
#define GRAVITY_CALC_H

#include <cmath>
#include <math.h>

using namespace std;

float gravity_strenght(float massA, float massB, float distance) {
    const float G = std::pow(6.67, (-11)); // Gravitational constant in m^3 kg^-1 s^-2
    float gratational_force = G*((massA*massB)/std::pow(distance, 2));
    return gratational_force;
}

float DeltaV_calc(float eng_impulse, float gravity_aceleration, float FullMass, float EmptyMass){
    float DeltaV = (eng_impulse*gravity_aceleration*log((FullMass/EmptyMass)));
    return DeltaV;
}

float reach_orbit_calc(float astro_mass, float distance_to_planet_center){
    const float G = std::pow(6.67, (-11));
    float NeededVel = ((G*astro_mass)/distance_to_planet_center);
    return NeededVel;
}

#endif