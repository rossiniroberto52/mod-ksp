#include<iostream>
#include "gravity_calc.h"
using namespace std;

int main() {
    float mass_terra = 59.72;
    float eng_imp, gravity_acell, MassF, MassE;
    cout << "forca do motor: " << endl;
    cin >> eng_imp; 
    cout << "aceleracao da gravidade: " << endl;
    cin >> gravity_acell;
    cout << "Massa total: " << endl;
    cin >> MassF;
    cout << "Massa vazia: " << endl;
    cin >> MassE;

    float deltaV = DeltaV_calc(eng_imp, gravity_acell, MassF, MassE);
    float orbit_needed = reach_orbit_calc(mass_terra, 35);
    cout << "DeltaV: " << deltaV << endl;
    cout << "nescessario para orbita: " << orbit_needed << endl;
    if(orbit_needed > deltaV){
        cout << "não é possivel ir a orbita!" << endl;
    }else{
        cout << "é possivel ir a orbita!" << endl;
    }
    return 0;
}
