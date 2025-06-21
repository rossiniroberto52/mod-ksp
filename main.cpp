#include<iostream>
#include "gravity_calc.h"
using namespace std;

int main() {
    float massF, massE, distance;
    float mass_terra = 59.972*pow(10, 24);
    float eng_imp, gravity_acell, MassF, MassE;
    int opcao;
    printf("opções\n1) calc de deltaV \n2) satelite gravitational force\n3) angular velocity\n4) time to revolution\n5) thirty kepler law\nopção: ");
    cin >> opcao;
    if(opcao == 1){
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
    }else if(opcao == 2){
        float gravity_str;
        cout << "Massa total: " << endl;
        cin >> massF;
        cout << "Massa limpa: " << endl;
        cin >> massE;
        cout << "distancia: " << endl;
        cin >> distance;
        gravity_str = gravity_strenght(massF, massE, distance);
        float res = gravity_art_satelit(massF, massE, distance);
        cout << "força gravitacional do satelite: " << res << endl;
    }else if(opcao == 3){
        
        cout << "Massa total: " << endl;
        cin >> MassF;
        cout << "Massa vazia: " << endl;
        cin >> MassE;
        cout << "distancia: " << endl;
        cin >> distance;

        float time = orbit_period_time(massF, massE, distance);
        float velocity = angular_velocity_angular_momenty(time);
        cout << "velocity on corpse: " << velocity << " (m/s)" <<endl;
        cout << "time to revolution: " << time << (" (Hours)")<<endl; 
    }
    else if(opcao == 4){
        cout << "Mass Full" << endl;
        cin >> massF;
        cout << "Mass Empyt" <<endl;
        cin >> massE;
        cout << "distance" << endl;
        cin >> distance;
        cout << "time ro revolution: " << orbit_period_time(massF, massF, distance) << "days" <<endl;
    }else if(opcao == 5){
        cout << "Mass Full" << endl;
        cin >> massF;
        cout << "Mass Empyt" <<endl;
        cin >> massE;
        cout << "distance" << endl;
        cin >> distance;
        cout << "K = " << thirty_kepler_law(massF, massE, distance)<<endl;
    }


    return 0;
}
